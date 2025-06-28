#include "signuppage.h"
#include "ui_signuppage.h"
#include <QGraphicsBlurEffect>
#include <QDialog>
SignUpPage::SignUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpPage)
{
    ui->setupUi(this);
}

SignUpPage::~SignUpPage()
{
    delete ui;
}
