/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindowClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindowClass)
    {
        if (LoginWindowClass->objectName().isEmpty())
            LoginWindowClass->setObjectName("LoginWindowClass");
        LoginWindowClass->resize(600, 400);
        centralWidget = new QWidget(LoginWindowClass);
        centralWidget->setObjectName("centralWidget");
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 140, 411, 22));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 120, 101, 16));
        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(90, 200, 411, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 180, 101, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 50, 151, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_3->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 260, 121, 31));
        LoginWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        LoginWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        LoginWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindowClass);
        statusBar->setObjectName("statusBar");
        LoginWindowClass->setStatusBar(statusBar);

        retranslateUi(LoginWindowClass);

        QMetaObject::connectSlotsByName(LoginWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindowClass)
    {
        LoginWindowClass->setWindowTitle(QCoreApplication::translate("LoginWindowClass", "LoginWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindowClass", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindowClass", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindowClass", "Cipher Circle", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindowClass", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindowClass: public Ui_LoginWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
