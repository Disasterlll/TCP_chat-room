#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include "Protocol.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);
    void notifyOtherClients(QString prevName, QString name);

public slots:
    void onTextForOtherClients(QString message, QString receiver, QString sender);
signals:
    void newClientConnected(QTcpSocket *client);
    void clientDisconnected(QTcpSocket *client);
private slots:
    void newClientConnectionReceived();
    void onClientDisconnected();

private: // fields
    QTcpServer *server;
    QMap<QString, QTcpSocket *> clients;
    Protocol protocol;
private: //mehtods
    void setupServer(ushort port);
};

#endif // SERVERMANAGER_H
