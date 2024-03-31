#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger {
public:
    static void logEvent(const QString& event) {
        QFile file("server_logs.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << " - " << event << "\n";
            file.close();
        }
    }
};

#endif // LOGGER_H
