#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include "Protocol.h"
#include "SendReceive.h"

LoginWindow::LoginWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.passwordLineEdit->setEchoMode(QLineEdit::Password);

}

LoginWindow::~LoginWindow()
{}

void LoginWindow::on_pushButton_clicked()
{
    ////Collect data inputted into both the username and password text fields
    //QString username = ui.usernameLineEdit->text();
    //QString password= ui.passwordLineEdit->text();



    //// Create a login request
    //QByteArray loginRequest = ChatProtocol::createLoginRequest(username, password);

    //// Send the login request to the server
    //clientManager->sendMessage(loginRequest, "Server");

    // Add a wait here for a response from the database

    // if number recieved represents confirmation, then show mainWindow ui,
    // else print account login unsuccessful on screen



    // Create MainWindow on the heap
    mainWindow = new MainWindow;

    // Show MainWindow
    mainWindow->show();

    // Connect a slot to delete MainWindow when it's closed
    connect(mainWindow, &MainWindow::destroyed, [this]() {
        mainWindow = nullptr; // Set the QPointer to null when MainWindow is destroyed
        });

    // Close the LoginWindow
    this->close();
}
