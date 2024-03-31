#pragma once

#include <QMainWindow>
#include "ui_LoginWindow.h"
#include <QPointer>
#include "mainwindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget* parent = nullptr);
	~LoginWindow();


private slots:

	void on_pushButton_clicked();

private:
	Ui::LoginWindowClass ui;
	ClientController* ClientController;
	QPointer<MainWindow> mainWindow;

};
