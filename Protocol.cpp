#include "Protocol.h"

#include <QFileInfo>
#include <QIODevice>

Protocol::Protocol()
{

}

QByteArray Protocol::SetText(QString message, QString receiver)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << Text << receiver << message;
    return ba;
}

QByteArray Protocol::setName(QString name)
{
    return getData(Name, name);
}

QByteArray Protocol::setFileSendRequest(QString fileName)
{
    QByteArray ba;
    QFileInfo info(fileName);
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << FileSendRequest << info.fileName() << info.size();
    return ba;
}

QByteArray Protocol::setAcceptFile()
{
    return getData(AcceptSendingFile, "");

}

QByteArray Protocol::setRejectFile()
{
    return getData(RejectSendingFile, "");

}

QByteArray Protocol::setFile(QString fileName)
{
    QByteArray ba;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QFileInfo info(fileName);
        QDataStream out(&ba, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);
        out << SendFile << info.fileName() << info.size() << file.readAll() ;
        file.close();
    }
    return ba;
}

QByteArray Protocol::setClientNameMessage(QString prevName, QString name)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << ClientName << prevName << name;
    return ba;
}

QByteArray Protocol::setConnectionACKMessage(QString clientName, QStringList otherClients)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << ConnectionACK << clientName << otherClients;
    return ba;
}

QByteArray Protocol::setNewClientMessage(QString clientName)
{
    return getData(NewClient, clientName);
}

QByteArray Protocol::setClinetDisconnectedMessage(QString clientName)
{
    return getData(ClientDisconnected, clientName);
}

void Protocol::loadData(QByteArray data)
{
    QDataStream in(&data, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_6_0);
    in >> type;
    switch (type) {
    case Text:
        in >> receiver >> message;
        break;
    case Name:
        in >> name;
        break;
    case FileSendRequest:
        in >> fileName >> fileSize;
        break;
    case SendFile:
        in >> fileName >> fileSize >> fileData;
        break;
    default:
        break;
    }
}

QByteArray Protocol::getData(MessageType type, QString data)
{
    QByteArray ba;
    QDataStream out(&ba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << type << data;
    return ba;
}

const QString &Protocol::getReceiver() const
{
    return receiver;
}

const QByteArray &Protocol::getFileData() const
{
    return fileData;
}

qint64 Protocol::getFileSize() const
{
    return fileSize;
}

const QString &Protocol::getFileName() const
{
    return fileName;
}

Protocol::MessageType Protocol::getType() const
{
    return type;
}

const QString &Protocol::getName() const
{
    return name;
}

const QString &Protocol::getMessage() const
{
    return message;
}
