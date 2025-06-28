/********************************************************************************
** Form generated from reading UI file 'signuppage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPPAGE_H
#define UI_SIGNUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpPage
{
public:
    QWidget *widget_2;
    QLabel *SignUpArea;
    QLabel *PictureArea;
    QLabel *WelcomeBanner;
    QLineEdit *email;
    QPushButton *CreateAccButton;
    QLineEdit *Username;
    QLineEdit *password;

    void setupUi(QWidget *SignUpPage)
    {
        if (SignUpPage->objectName().isEmpty())
            SignUpPage->setObjectName("SignUpPage");
        SignUpPage->resize(1230, 746);
        widget_2 = new QWidget(SignUpPage);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(250, 70, 761, 551));
        widget_2->setStyleSheet(QString::fromUtf8("QPushButton#LoginButton{\n"
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
"}\n"
"\n"
"QPushButton#signUpButton{\n"
"    background-color:rgba(255, 107, 107, 255);\n"
"    color:rgba(255, 255, 255, 200);\n"
"    border-radius:8px;\n"
"    font-size: 16"
                        "px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton#signUpButton:pressed{\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: rgba(85, 98, 112, 255);\n"
"    background-position:calc(100% - 10px)center;\n"
"}\n"
"QPushButton#signUpButton:hover{\n"
"    background-color:rgba(85, 98, 112, 255);\n"
"}"));
        SignUpArea = new QLabel(widget_2);
        SignUpArea->setObjectName("SignUpArea");
        SignUpArea->setGeometry(QRect(100, 70, 291, 401));
        SignUpArea->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 255);\n"
"border-radius:10px;"));
        PictureArea = new QLabel(widget_2);
        PictureArea->setObjectName("PictureArea");
        PictureArea->setGeometry(QRect(390, 50, 311, 391));
        PictureArea->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(85, 98, 112, 255), stop:1 rgba(255, 107, 107, 255));\n"
"border-radius:10px;\n"
""));
        WelcomeBanner = new QLabel(widget_2);
        WelcomeBanner->setObjectName("WelcomeBanner");
        WelcomeBanner->setGeometry(QRect(130, 100, 181, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(false);
        WelcomeBanner->setFont(font);
        WelcomeBanner->setStyleSheet(QString::fromUtf8("color:rgba(0, 0, 0, 200);"));
        email = new QLineEdit(widget_2);
        email->setObjectName("email");
        email->setGeometry(QRect(130, 250, 211, 41));
        email->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(0, 0, 0, 0);\n"
"border-bottom-color:rgba(46, 82, 101, 200);\n"
"color:black;\n"
"padding-bottom:7px;\n"
""));
        email->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        email->setEchoMode(QLineEdit::EchoMode::Normal);
        CreateAccButton = new QPushButton(widget_2);
        CreateAccButton->setObjectName("CreateAccButton");
        CreateAccButton->setGeometry(QRect(130, 390, 191, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Historic")});
        font1.setUnderline(false);
        CreateAccButton->setFont(font1);
        CreateAccButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        CreateAccButton->setStyleSheet(QString::fromUtf8(""));
        Username = new QLineEdit(widget_2);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(130, 180, 211, 41));
        Username->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(0, 0, 0, 0);\n"
"border-bottom-color:rgba(46, 82, 101, 200);\n"
"color:black;\n"
"padding-bottom:7px;\n"
""));
        password = new QLineEdit(widget_2);
        password->setObjectName("password");
        password->setGeometry(QRect(130, 320, 211, 41));
        password->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(0, 0, 0, 0);\n"
"border-bottom-color:rgba(46, 82, 101, 200);\n"
"color:black;\n"
"padding-bottom:7px;\n"
""));
        SignUpArea->raise();
        PictureArea->raise();
        WelcomeBanner->raise();
        CreateAccButton->raise();
        Username->raise();
        email->raise();
        password->raise();

        retranslateUi(SignUpPage);

        QMetaObject::connectSlotsByName(SignUpPage);
    } // setupUi

    void retranslateUi(QWidget *SignUpPage)
    {
        SignUpPage->setWindowTitle(QCoreApplication::translate("SignUpPage", "Form", nullptr));
        SignUpArea->setText(QString());
        PictureArea->setText(QString());
        WelcomeBanner->setText(QCoreApplication::translate("SignUpPage", "Sign Up", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("SignUpPage", "Email", nullptr));
#if QT_CONFIG(tooltip)
        CreateAccButton->setToolTip(QCoreApplication::translate("SignUpPage", "Click to login", nullptr));
#endif // QT_CONFIG(tooltip)
        CreateAccButton->setText(QCoreApplication::translate("SignUpPage", "Create Account", nullptr));
        Username->setPlaceholderText(QCoreApplication::translate("SignUpPage", "Username", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("SignUpPage", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpPage: public Ui_SignUpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
