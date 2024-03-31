#ifndef CHATPROTOCOL_H
#define CHATPROTOCOL_H

#include <QByteArray>
#include <QString>



class Protocol
{
public:
    enum MessageType{
        Text,
        Name,
        FileSendRequest,
        AcceptSendingFile,
        RejectSendingFile,
        SendFile,
        ClientName,
        ConnectionACK,
        NewClient,
        ClientDisconnected
    };

    Protocol();

    QByteArray SetText(QString message, QString receiver);
    QByteArray setName(QString name);
    QByteArray setFileSendRequest(QString fileName);
    QByteArray setAcceptFile();
    QByteArray setRejectFile();
    QByteArray setFile(QString fileName);

    QByteArray setClientNameMessage(QString prevName, QString name);
    QByteArray setConnectionACKMessage(QString clientName, QStringList otherClients);
    QByteArray setNewClientMessage(QString clientName);
    QByteArray setClinetDisconnectedMessage(QString clientName);

    void loadData(QByteArray data);

    const QString &getMessage() const;

    const QString &getName() const;

    MessageType getType() const;

    const QString &getFileName() const;

    qint64 getFileSize() const;

    const QByteArray &getFileData() const;

    const QString &getReceiver() const;

private:
    QByteArray getData(MessageType type, QString data);

    MessageType type;
    QString message;
    QString name;
    QString fileName;
    qint64 fileSize;
    QByteArray fileData;
    QString receiver;

};

#endif // CHATPROTOCOL_H
