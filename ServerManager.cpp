#include "ServerManager.h"
#include "Logger.h"


ServerManager::ServerManager(ushort port, QObject *parent)
    : QObject{parent}
{
    setupServer(port);
}

void ServerManager::notifyOtherClients(QString prevName, QString name)
{
    auto message = protocol.setClientNameMessage(prevName, name);
    foreach (auto cl, clients) {
        auto clientName = cl->property("clientName").toString();
        if (clientName != name) {
            cl->write(message);
        }
    }
}

void ServerManager::onTextForOtherClients(QString message, QString receiver, QString sender)
{
    auto msg = protocol.SetText(message, receiver);
    if (receiver == "All") {
        foreach (auto cl, clients) {
            auto clientName = cl->property("clientName").toString();
            if (clientName != sender) {
                cl->write(msg);
            }
        }
    } else {
        foreach (auto cl, clients) {
            auto clientName = cl->property("clientName").toString();
            if (clientName == receiver) {
                cl->write(msg);
                return;
            }
        }
    }
}

void ServerManager::newClientConnectionReceived()
{
    auto client = server->nextPendingConnection();

    auto id = clients.count() + 1;
    auto clientName = QString("Client (%1)").arg(id);
    client->setProperty("id", id);
    client->setProperty("clientName", clientName);

    connect(client, &QTcpSocket::disconnected, this, &ServerManager::onClientDisconnected);
    emit newClientConnected(client);

    if (id > 1) {
        auto message = protocol.setConnectionACKMessage(clientName, clients.keys());
        client->write(message);

        auto newClientMessage = protocol.setNewClientMessage(clientName);
        foreach (auto cl, clients) {
            cl->write(newClientMessage);
        }
    }
    clients[clientName] = client;

    Logger::logEvent(QString("New client connection received: %1").arg(clientName));

}

void ServerManager::onClientDisconnected()
{
    auto client = qobject_cast<QTcpSocket *>(sender());
    auto clientName = client->property("clientName").toString();
    clients.remove(clientName);
    auto message = protocol.setClinetDisconnectedMessage(clientName);
    foreach (auto cl, clients) {
        cl->write(message);
    }

    emit clientDisconnected(client);

    Logger::logEvent(QString("Client disconnected: %1").arg(clientName));

}

void ServerManager::setupServer(ushort port)
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &ServerManager::newClientConnectionReceived);
    server->listen(QHostAddress::Any, port);
}
