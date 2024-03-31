#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "Protocol.h"

#include <QObject>
#include <QTcpSocket>

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QHostAddress ip = QHostAddress::LocalHost, ushort port = 4500, QObject *parent = nullptr);
    explicit ClientController(QTcpSocket *client, QObject *parent = nullptr);

    void connectToServer();
    void disconnectFromHost();

    void sendMessage(QString message);
    void sendName(QString name);
    QString name() const;


    void sendInitSendingFile(QString fileName);
    void sendAcceptFile();
    void sendRejectFile();

signals:
    void connected();
    void disconnected();
//    void dataReceived(QByteArray data);
    void textMessageReceived(const QString message, QString receiver);
    void nameChanged(QString prevName, QString name);
    void rejectReceivingFile();
    void initReceivingFile(QString clientName, QString fileName, qint64 fileSize);
    void fileSaved(QString path);
private slots:
    void readyRead();

private: //fields
    QTcpSocket *socket;
    QHostAddress ip;
    ushort port;
    Protocol protocol;
    QString tmpFileName;

private: //methods
     void setupClient();
     void sendFile();
     void saveFile();
};

#endif // CLIENTMANAGER_H
