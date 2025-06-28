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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpPage
{
public:
    QWidget *widget;
    QLabel *BackGround;
    QLabel *SignUpArea;
    QLabel *CreateAccBanner;

    void setupUi(QWidget *SignUpPage)
    {
        if (SignUpPage->objectName().isEmpty())
            SignUpPage->setObjectName("SignUpPage");
        SignUpPage->resize(1230, 746);
        widget = new QWidget(SignUpPage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 70, 951, 511));
        BackGround = new QLabel(widget);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(0, 10, 951, 501));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(85, 98, 112, 255), stop:1 rgba(255, 107, 107, 255));\n"
"border-radius:10px;\n"
""));
        SignUpArea = new QLabel(widget);
        SignUpArea->setObjectName("SignUpArea");
        SignUpArea->setGeometry(QRect(190, 50, 571, 421));
        SignUpArea->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 255);\n"
"border-radius:10px;\n"
"background: transparent;"));
        CreateAccBanner = new QLabel(widget);
        CreateAccBanner->setObjectName("CreateAccBanner");
        CreateAccBanner->setGeometry(QRect(350, 50, 251, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Nirmala Text")});
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(false);
        CreateAccBanner->setFont(font);
        CreateAccBanner->setStyleSheet(QString::fromUtf8("color:rgba(0, 0, 0, 200);"));

        retranslateUi(SignUpPage);

        QMetaObject::connectSlotsByName(SignUpPage);
    } // setupUi

    void retranslateUi(QWidget *SignUpPage)
    {
        SignUpPage->setWindowTitle(QCoreApplication::translate("SignUpPage", "Form", nullptr));
        BackGround->setText(QString());
        SignUpArea->setText(QString());
        CreateAccBanner->setText(QCoreApplication::translate("SignUpPage", "Create Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpPage: public Ui_SignUpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPPAGE_H
