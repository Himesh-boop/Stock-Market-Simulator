/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginPage
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *LoginArea;
    QLabel *PictureArea;
    QLabel *WelcomeBanner;
    QLineEdit *Password;
    QPushButton *LoginButton;
    QLabel *character;
    QLineEdit *Username;
    QLabel *statusLabel;
    QCheckBox *rememberMeCheckbox;
    QPushButton *forgotPasswordButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loginPage)
    {
        if (loginPage->objectName().isEmpty())
            loginPage->setObjectName("loginPage");
        loginPage->resize(1168, 692);
        centralwidget = new QWidget(loginPage);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 40, 761, 551));
        widget->setStyleSheet(QString::fromUtf8("QPushButton#LoginButton{\n"
"    background-color:rgba(85, 98, 112, 255);\n"
"    color:rgba(255, 255, 255, 200);\n"
"    border-radius:8px;\n"
"    font-size: 16px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton#LoginButton:pressed{\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgba(255, 107, 107, 255);\n"
"    background-position:calc(100% - 10px)center;\n"
"}\n"
"QPushButton#LoginButton:hover{\n"
"    background-color:rgba(255, 107, 107, 255);\n"
"}\n"
"\n"
"QPushButton#ShowPasswordButton{\n"
"    background-color:rgba(85, 98, 112, 200);\n"
"    color:rgba(255, 255, 255, 200);\n"
"    border-radius:3px;\n"
"}\n"
"QPushButton#ShowPasswordButton:pressed{\n"
"    background-color: rgba(255, 107, 107, 255);\n"
"}\n"
"QPushButton#ShowPasswordButton:hover{\n"
"    background-color:rgba(255, 107, 107, 200);\n"
"}"));
        LoginArea = new QLabel(widget);
        LoginArea->setObjectName("LoginArea");
        LoginArea->setGeometry(QRect(330, 50, 291, 401));
        LoginArea->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 255);\n"
"border-radius:10px;"));
        PictureArea = new QLabel(widget);
        PictureArea->setObjectName("PictureArea");
        PictureArea->setGeometry(QRect(30, 30, 311, 391));
        PictureArea->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(85, 98, 112, 255), stop:1 rgba(255, 107, 107, 255));\n"
"border-radius:10px;\n"
""));
        WelcomeBanner = new QLabel(widget);
        WelcomeBanner->setObjectName("WelcomeBanner");
        WelcomeBanner->setGeometry(QRect(370, 80, 161, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(false);
        WelcomeBanner->setFont(font);
        WelcomeBanner->setStyleSheet(QString::fromUtf8("color:rgba(0, 0, 0, 200);"));
        Password = new QLineEdit(widget);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(370, 230, 211, 41));
        Password->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(0, 0, 0, 0);\n"
"border-bottom-color:rgba(46, 82, 101, 200);\n"
"color:black;\n"
"padding-bottom:7px;\n"
""));
        Password->setEchoMode(QLineEdit::EchoMode::Password);
        LoginButton = new QPushButton(widget);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(370, 340, 201, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Historic")});
        font1.setUnderline(false);
        LoginButton->setFont(font1);
        LoginButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        LoginButton->setStyleSheet(QString::fromUtf8(""));
        character = new QLabel(widget);
        character->setObjectName("character");
        character->setGeometry(QRect(10, 80, 311, 281));
        QFont font2;
        font2.setPointSize(200);
        font2.setUnderline(false);
        character->setFont(font2);
        character->setStyleSheet(QString::fromUtf8("color:rgba(255, 107, 107, 255);"));
        Username = new QLineEdit(widget);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(370, 170, 211, 41));
        Username->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(0, 0, 0, 0);\n"
"border-bottom-color:rgba(46, 82, 101, 200);\n"
"color:black;\n"
"padding-bottom:7px;\n"
""));
        statusLabel = new QLabel(widget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(370, 280, 211, 21));
        statusLabel->setStyleSheet(QString::fromUtf8("color: rgba(255, 0, 0, 200);"));
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rememberMeCheckbox = new QCheckBox(widget);
        rememberMeCheckbox->setObjectName("rememberMeCheckbox");
        rememberMeCheckbox->setGeometry(QRect(370, 310, 131, 20));
        rememberMeCheckbox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        rememberMeCheckbox->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 150);"));
        forgotPasswordButton = new QPushButton(widget);
        forgotPasswordButton->setObjectName("forgotPasswordButton");
        forgotPasswordButton->setGeometry(QRect(410, 400, 131, 31));
        forgotPasswordButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        forgotPasswordButton->setStyleSheet(QString::fromUtf8("color: rgba(85, 98, 112, 200);\n"
"background-color: transparent;\n"
"border: none;\n"
"text-decoration: underline;"));
        forgotPasswordButton->setFlat(true);
        LoginArea->raise();
        PictureArea->raise();
        WelcomeBanner->raise();
        LoginButton->raise();
        character->raise();
        Username->raise();
        statusLabel->raise();
        rememberMeCheckbox->raise();
        forgotPasswordButton->raise();
        Password->raise();
        loginPage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(loginPage);
        statusbar->setObjectName("statusbar");
        loginPage->setStatusBar(statusbar);

        retranslateUi(loginPage);

        QMetaObject::connectSlotsByName(loginPage);
    } // setupUi

    void retranslateUi(QMainWindow *loginPage)
    {
        loginPage->setWindowTitle(QCoreApplication::translate("loginPage", "Login System", nullptr));
        LoginArea->setText(QString());
        PictureArea->setText(QString());
        WelcomeBanner->setText(QCoreApplication::translate("loginPage", "Welcome", nullptr));
        Password->setPlaceholderText(QCoreApplication::translate("loginPage", "Password", nullptr));
#if QT_CONFIG(tooltip)
        LoginButton->setToolTip(QCoreApplication::translate("loginPage", "Click to login", nullptr));
#endif // QT_CONFIG(tooltip)
        LoginButton->setText(QCoreApplication::translate("loginPage", "LOGIN", nullptr));
        character->setText(QCoreApplication::translate("loginPage", "\343\200\275", nullptr));
        Username->setPlaceholderText(QCoreApplication::translate("loginPage", "Username", nullptr));
        statusLabel->setText(QString());
        rememberMeCheckbox->setText(QCoreApplication::translate("loginPage", "Remember me", nullptr));
        forgotPasswordButton->setText(QCoreApplication::translate("loginPage", "Forgot Password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginPage: public Ui_loginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
