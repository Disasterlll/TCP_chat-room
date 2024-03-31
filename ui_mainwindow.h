/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tbClientsChat;
    QListWidget *lstClients;
    QLabel *label;
    QLabel *label_2;
    QPushButton *downloadLogs;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(716, 601);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tbClientsChat = new QTabWidget(centralwidget);
        tbClientsChat->setObjectName("tbClientsChat");
        tbClientsChat->setGeometry(QRect(167, 29, 531, 491));
        lstClients = new QListWidget(centralwidget);
        lstClients->setObjectName("lstClients");
        lstClients->setGeometry(QRect(15, 30, 141, 481));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 131, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 10, 131, 16));
        label_2->setFont(font);
        downloadLogs = new QPushButton(centralwidget);
        downloadLogs->setObjectName("downloadLogs");
        downloadLogs->setGeometry(QRect(40, 520, 91, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 716, 38));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Server", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Client(s) Connected", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Chat Messages", nullptr));
        downloadLogs->setText(QCoreApplication::translate("MainWindow", "Download Logs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
