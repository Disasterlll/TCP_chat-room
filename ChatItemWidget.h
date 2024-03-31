#ifndef CHATITEMWIDGET_H
#define CHATITEMWIDGET_H

#include <QWidget>

namespace Ui {
class ChatItemWidget;
}

class ChatItemWidget : public QWidget
{
    Q_OBJECT

public:

    explicit ChatItemWidget(QWidget *main = nullptr);
    ~ChatItemWidget();
    void setMessage(QString message, bool is_My_Message = false);

private:

    Ui::ChatItemWidget *ui;

};

#endif 
