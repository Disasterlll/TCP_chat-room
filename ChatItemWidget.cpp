#include "ChatItemWidget.h"
#include "ui_ChatItemWidget.h"

#include <QTime>

ChatItemWidget::ChatItemWidget(QWidget * main) :
    QWidget(main),
    ui(new Ui::ChatItemWidget)
{
    ui->setupUi(this);
}

ChatItemWidget::~ChatItemWidget()
{
    delete ui;
}

void ChatItemWidget::setMessage(QString message, bool is_My_Message)
{
    if(is_My_Message)
        ui->lblMessage->setAlignment(Qt::AlignRight);
    ui->lblMessage->setText(message);
    ui->lblTime->setText(QTime::currentTime().toString("HH:mm"));
}
