#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    seupServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClientConnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("New Client added: %1").arg(id));
    auto chatWidget= new ClientChatWidget(client, ui->tbClientsChat);
    ui->tbClientsChat->addTab(chatWidget, QString("Client (%1)").arg(id));

    connect(chatWidget, &ClientChatWidget::clientNameChanged, this, &MainWindow::setClientName);

    connect(chatWidget, &ClientChatWidget::textForOtherClients, _server, &ServerManager::onTextForOtherClients);
}

void MainWindow::clientDisconnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("Client disconnected: %1").arg(id));
}

void MainWindow::setClientName(QString prevName, QString name)
{
    auto widget = qobject_cast<QWidget *>(sender());
    auto index = ui->tbClientsChat->indexOf(widget);
    ui->tbClientsChat->setTabText(index, name);

    _server->notifyOtherClients(prevName, name);
}


void MainWindow::seupServer()
{
    _server = new ServerManager();
    connect(_server, &ServerManager::newClientConnected, this, &MainWindow::newClientConnected);
    connect(_server, &ServerManager::clientDisconnected, this, &MainWindow::clientDisconnected);

}


void MainWindow::on_tbClientsChat_tabCloseRequested(int index)
{
    auto chatWidget = qobject_cast<ClientChatWidget *>(ui->tbClientsChat->widget(index));
    chatWidget->disconnect();
    ui->tbClientsChat->removeTab(index);
}


void MainWindow::downloadLogs() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Log File"), "", tr("Text Files (*.txt)"));
    if (!fileName.isEmpty()) {
        QFile::copy("server_logs.txt", fileName);
    }
}
