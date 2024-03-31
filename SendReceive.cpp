#include "SendReceive.h"

#include <QDir>

ClientController::ClientController(QHostAddress ip, ushort port, QObject *parent)
    : QObject{parent},
      ip(ip),
      port(port)
{
    socket = new QTcpSocket(this);
    setupClient();
}

ClientController::ClientController(QTcpSocket *client, QObject *parent)
    : QObject{parent},
    socket(client)
{
    setupClient();
}

void ClientController::connectToServer()
{
    socket->connectToHost(ip, port);
}

void ClientController::disconnectFromHost()
{
    socket->disconnectFromHost();
}

void ClientController::sendMessage(QString message)
{
    socket->write(protocol.SetText(message, name()));
}

void ClientController::sendName(QString name)
{
    socket->write(protocol.setName(name));
}


QString ClientController::name() const
{
    auto id = socket->property("id").toInt();
    auto name = protocol.getName().length() > 0 ? protocol.getName() : QString("Client (%1)").arg(id);

    return name;
}

void ClientController::sendInitSendingFile(QString fileName)
{
    tmpFileName = fileName;
    socket->write(protocol.setFileSendRequest(fileName));
}

void ClientController::sendAcceptFile()
{
    socket->write(protocol.setAcceptFile());
}

void ClientController::sendRejectFile()
{
    socket->write(protocol.setRejectFile());
}
void ClientController::readyRead()
{
    auto data = socket->readAll();
    protocol.loadData(data);
    switch (protocol.getType()) {
    case Protocol::Text:
        emit textMessageReceived(protocol.getMessage(), protocol.getReceiver());
        break;
    case Protocol::Name:{
        auto prevName = socket->property("clientName").toString();
        socket->setProperty("clientName", name());
        emit nameChanged(prevName, name());
        break;
    }
    case Protocol::FileSendRequest:
        emit initReceivingFile(protocol.getName(), protocol.getFileName(), protocol.getFileSize());
        break;
    case Protocol::AcceptSendingFile:
        sendFile();
        break;
    case Protocol::RejectSendingFile:
        emit rejectReceivingFile();
        break;
    case Protocol::SendFile:
        saveFile();
        break;
    default:
        break;
    }
}

void ClientController::setupClient()
{
    connect(socket, &QTcpSocket::connected, this, &ClientController::connected);
    connect(socket, &QTcpSocket::disconnected, this, &ClientController::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ClientController::readyRead);
}

void ClientController::sendFile()
{
    socket->write(protocol.setFile(tmpFileName));
}

void ClientController::saveFile()
{
    QDir dir;
    dir.mkdir(name());
    auto path = QString("%1/%2/%3_%4")
            .arg(dir.canonicalPath(), name(), QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"), protocol.getFileName());
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(protocol.getFileData());
        file.close();
        emit fileSaved(path);
    }
}

