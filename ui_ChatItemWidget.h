/********************************************************************************
** Form generated from reading UI file 'ChatItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATITEMWIDGET_H
#define UI_CHATITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatItemWidget
{
public:
    QLabel *lblMessage;
    QLabel *lblTime;

    void setupUi(QWidget *ChatItemWidget)
    {
        if (ChatItemWidget->objectName().isEmpty())
            ChatItemWidget->setObjectName("ChatItemWidget");
        ChatItemWidget->resize(593, 73);
        lblMessage = new QLabel(ChatItemWidget);
        lblMessage->setObjectName("lblMessage");
        lblMessage->setGeometry(QRect(70, 9, 511, 16));
        lblTime = new QLabel(ChatItemWidget);
        lblTime->setObjectName("lblTime");
        lblTime->setGeometry(QRect(10, 10, 49, 16));

        retranslateUi(ChatItemWidget);

        QMetaObject::connectSlotsByName(ChatItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatItemWidget)
    {
        ChatItemWidget->setWindowTitle(QCoreApplication::translate("ChatItemWidget", "Form", nullptr));
        lblMessage->setText(QCoreApplication::translate("ChatItemWidget", "TextLabel", nullptr));
        lblTime->setText(QCoreApplication::translate("ChatItemWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatItemWidget: public Ui_ChatItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATITEMWIDGET_H
