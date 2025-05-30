/********************************************************************************
** Form generated from reading UI file 'pages.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGES_H
#define UI_PAGES_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *PortfolioPage;
    QWidget *CashPage;
    QWidget *CandleStickPage;
    QVBoxLayout *verticalLayout_3;
    QChartView *chartWidget;
    QWidget *widget;
    QWidget *HistoryPage;
    QWidget *NewsPage;

    void setupUi(QMainWindow *pages)
    {
        if (pages->objectName().isEmpty())
            pages->setObjectName("pages");
        pages->resize(536, 408);
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
"	min-height: 60px;\n"
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
"    margin-right: -20px; /* Keeps layout from shifting */\n"
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
        icon.addFile(QString::fromUtf8(":/icons/account_circle_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon1.addFile(QString::fromUtf8(":/icons/wallet_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon2.addFile(QString::fromUtf8(":/icons/candlestick_chart_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon3.addFile(QString::fromUtf8(":/icons/assignment_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon4.addFile(QString::fromUtf8(":/icons/newspaper_1000dp_E3E3E3_FILL0_wght400_GRAD0_opsz48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        verticalLayout_2 = new QVBoxLayout(contentPanel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(contentPanel);
        stackedWidget->setObjectName("stackedWidget");
        PortfolioPage = new QWidget();
        PortfolioPage->setObjectName("PortfolioPage");
        stackedWidget->addWidget(PortfolioPage);
        CashPage = new QWidget();
        CashPage->setObjectName("CashPage");
        stackedWidget->addWidget(CashPage);
        CandleStickPage = new QWidget();
        CandleStickPage->setObjectName("CandleStickPage");
        verticalLayout_3 = new QVBoxLayout(CandleStickPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chartWidget = new QChartView(CandleStickPage);
        chartWidget->setObjectName("chartWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(chartWidget->sizePolicy().hasHeightForWidth());
        chartWidget->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(chartWidget);

        widget = new QWidget(CandleStickPage);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(widget);

        stackedWidget->addWidget(CandleStickPage);
        HistoryPage = new QWidget();
        HistoryPage->setObjectName("HistoryPage");
        stackedWidget->addWidget(HistoryPage);
        NewsPage = new QWidget();
        NewsPage->setObjectName("NewsPage");
        stackedWidget->addWidget(NewsPage);

        verticalLayout_2->addWidget(stackedWidget);


        horizontalLayout->addWidget(contentPanel);

        pages->setCentralWidget(centralwidget);

        retranslateUi(pages);

        stackedWidget->setCurrentIndex(2);


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
