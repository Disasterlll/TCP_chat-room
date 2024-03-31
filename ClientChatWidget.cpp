#include "ClientChatWidget.h"
#include "ui_ClientChatWidget.h"
#include "Logger.h"

#include <QMessageBox>
#include <QDesktopServices>

ClientChatWidget::ClientChatWidget(QTcpSocket *client, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientChatWidget)
{
    ui->setupUi(this);
    _client = new ClientController(client, this);
//    connect(_client, &QTcpSocket::readyRead, this, &ClientChatWidget::dataReceived);
    connect(_client, &ClientController::disconnected, this, &ClientChatWidget::clientDisconnected);
    connect(_client, &ClientController::textMessageReceived, this, &ClientChatWidget::textMessageReceived);
    connect(_client, &ClientController::nameChanged, this, &ClientChatWidget::onClientNameChanged);
    connect(_client, &ClientController::initReceivingFile, this, &ClientChatWidget::onInitReceivingFile);
    connect(_client, &ClientController::fileSaved, this, &ClientChatWidget::onFileSaved);

    dir.mkdir(_client->name());
    dir.setPath("./" + _client->name());
}

void ClientChatWidget::disconnect()
{
    _client->disconnectFromHost();
}

ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}

void ClientChatWidget::clientDisconnected()
{
    ui->wdgSendMessage->setEnabled(false);
}

void ClientChatWidget::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();

    Logger::logEvent(QString("Message sent from %1: %2").arg(_client->name()).arg(message));

    _client->sendMessage(message);
    ui->lnMessage->setText("");
    ui->lstMessages->addItem(message);
}

void ClientChatWidget::textMessageReceived(QString message, QString receiver)
{
    if (receiver == "Server" || receiver == "All") {
        ui->lstMessages->addItem(message);
    }
    if(receiver != "Server"){
        emit textForOtherClients(message, receiver, _client->name());
    }
    Logger::logEvent(QString("Message received from %1: %2").arg(_client->name()).arg(message));

}

void ClientChatWidget::onInitReceivingFile(QString clientName, QString fileName, qint64 fileSize)
{
    auto message = QString("File transfer request from Client (%1). Accept or Decline?\nFile Name:%2\nFile Size: %3 bytes")
            .arg(clientName, fileName)
            .arg(fileSize);
    auto result = QMessageBox::question(this, "Receiving File", message);
    if (result == QMessageBox::Yes) {
        _client->sendAcceptFile();
    } else {
        _client->sendRejectFile();
    }

    Logger::logEvent(QString("File received from %1: %2").arg(_client->name()).arg(message));

}

void ClientChatWidget::onFileSaved(QString path)
{
    auto message = QString("File saved here:\n%1").arg(path);
    QMessageBox::information(this, "File saved", message);
}

void ClientChatWidget::on_lblOpenFolder_linkActivated(const QString &link)
{
    Q_UNUSED(link);// to get rid of compiler wanring for unreferenced formal parameter
    QDesktopServices::openUrl(QUrl::fromLocalFile(_client->name()));
}

void ClientChatWidget::onClientNameChanged(QString prevName, QString name)
{
    QFile::rename(dir.canonicalPath(), name);
    emit clientNameChanged(prevName, name);
}

