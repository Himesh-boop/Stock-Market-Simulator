/********************************************************************************
** Form generated from reading UI file 'pages.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGES_H
#define UI_PAGES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pages
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *navPanel;
    QVBoxLayout *verticalLayout;
    QPushButton *Portfolio;
    QPushButton *Cash;
    QPushButton *Investment;
    QPushButton *Ledger;
    QPushButton *News;
    QWidget *contentPanel;

    void setupUi(QMainWindow *pages)
    {
        if (pages->objectName().isEmpty())
            pages->setObjectName("pages");
        pages->resize(509, 283);
        pages->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #2E2E2E;\n"
"    color: #E0E0E0;\n"
"    border: none;\n"
"}\n"
"\n"
"/* QPushButton styles */\n"
"QPushButton {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: none;\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #606060;\n"
"}\n"
"\n"
"/* QLabel, QLineEdit, and QComboBox */\n"
"QLabel, QLineEdit, QComboBox {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #555;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"/* Remove focus border */\n"
"*:focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"/* Scrollbar style (optional) */\n"
"QScrollBar:vertical {\n"
"    background: #2E2E2E;\n"
"    width: 8px;\n"
"    margin: 2px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: #505050;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        centralwidget = new QWidget(pages);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: none;\n"
"    padding: 8px;\n"
"    border-radius: 4px;\n"
"    min-width: 100px;\n"
"    max-width: 100px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #606060;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #707070;\n"
"    margin-left: 20px;\n"
"    margin-right: -10px; /* Keeps layout from shifting */\n"
"    font-weight: bold;\n"
"    border-left: 4px solid #E0E0E0;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 0, 0, 0);
        navPanel = new QWidget(centralwidget);
        navPanel->setObjectName("navPanel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(navPanel->sizePolicy().hasHeightForWidth());
        navPanel->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(navPanel);
        verticalLayout->setObjectName("verticalLayout");
        Portfolio = new QPushButton(navPanel);
        Portfolio->setObjectName("Portfolio");
        Portfolio->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #707070;\n"
"    border: 1px solid #AAAAAA;\n"
"    font-weight: bold;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("account_circle_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Portfolio->setIcon(icon);
        Portfolio->setIconSize(QSize(35, 35));
        Portfolio->setCheckable(true);
        Portfolio->setAutoExclusive(true);
        Portfolio->setFlat(true);

        verticalLayout->addWidget(Portfolio);

        Cash = new QPushButton(navPanel);
        Cash->setObjectName("Cash");
        Cash->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #707070;\n"
"    border: 1px solid #AAAAAA;\n"
"    font-weight: bold;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("wallet_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Cash->setIcon(icon1);
        Cash->setIconSize(QSize(35, 35));
        Cash->setCheckable(true);
        Cash->setAutoExclusive(true);
        Cash->setFlat(true);

        verticalLayout->addWidget(Cash);

        Investment = new QPushButton(navPanel);
        Investment->setObjectName("Investment");
        Investment->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #707070;\n"
"    border: 1px solid #AAAAAA;\n"
"    font-weight: bold;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("candlestick_chart_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Investment->setIcon(icon2);
        Investment->setIconSize(QSize(35, 35));
        Investment->setCheckable(true);
        Investment->setAutoExclusive(true);

        verticalLayout->addWidget(Investment);

        Ledger = new QPushButton(navPanel);
        Ledger->setObjectName("Ledger");
        Ledger->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #707070;\n"
"    border: 1px solid #AAAAAA;\n"
"    font-weight: bold;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("assignment_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Ledger->setIcon(icon3);
        Ledger->setIconSize(QSize(35, 35));
        Ledger->setCheckable(true);
        Ledger->setAutoExclusive(true);
        Ledger->setFlat(true);

        verticalLayout->addWidget(Ledger);

        News = new QPushButton(navPanel);
        News->setObjectName("News");
        News->setStyleSheet(QString::fromUtf8("QPushButton:checked {\n"
"    background-color: #707070;\n"
"    border: 1px solid #AAAAAA;\n"
"    font-weight: bold;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("newspaper_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        News->setIcon(icon4);
        News->setIconSize(QSize(35, 35));
        News->setCheckable(true);
        News->setAutoExclusive(true);

        verticalLayout->addWidget(News);


        horizontalLayout->addWidget(navPanel);

        contentPanel = new QWidget(centralwidget);
        contentPanel->setObjectName("contentPanel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(9);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contentPanel->sizePolicy().hasHeightForWidth());
        contentPanel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(contentPanel);

        pages->setCentralWidget(centralwidget);

        retranslateUi(pages);

        QMetaObject::connectSlotsByName(pages);
    } // setupUi

    void retranslateUi(QMainWindow *pages)
    {
        pages->setWindowTitle(QCoreApplication::translate("pages", "MainWindow", nullptr));
        Portfolio->setText(QString());
        Cash->setText(QString());
        Investment->setText(QString());
        Ledger->setText(QString());
        News->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pages: public Ui_pages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGES_H
