#include "signuppage.h"
#include "ui_signuppage.h"
#include "db/logindb.h"
SignUpPage::SignUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpPage)
{
    ui->setupUi(this);
    connect(ui->CreateAccButton, &QPushButton::clicked, this, &SignUpPage::onCreateAccButtonClicked);
}
void SignUpPage::onCreateAccButtonClicked(){
    QString username = ui->Username->text();
    QString email = ui->email->text();
    QString password = ui->password->text();
    if (username.isEmpty() || email.isEmpty() || password.isEmpty()) {
        qDebug() << "All fields must be filled.";
        return;
    }
    storeInDatabase(username, email, password);
}
void SignUpPage::storeInDatabase(const QString &username, const QString &email, const QString &password){
    loginDB db; // creates db connection and table if needed
    if (db.insertUser(username, email, password)) {
        qDebug() << "User created successfully!";
        this->accept();
    } else {
        qDebug() << "Failed to create user.";
    }
}
SignUpPage::~SignUpPage()
{
    delete ui;
}
