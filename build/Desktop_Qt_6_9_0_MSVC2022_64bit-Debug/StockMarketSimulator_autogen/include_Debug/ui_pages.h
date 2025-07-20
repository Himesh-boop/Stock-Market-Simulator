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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
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
    QWidget *contentPanel;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *PortfolioPage;
    QGridLayout *gridLayout;
    QFrame *Cards;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QLabel *label_9;
    QTableView *table;
    QLabel *portfolioTitle;
    QWidget *CashPage;
    QVBoxLayout *verticalLayout_2;
    QWidget *cashTitle;
    QGridLayout *gridLayout_4;
    QWidget *Title_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *label_12;
    QWidget *cashCard;
    QGridLayout *gridLayout_5;
    QFrame *Cards_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_11;
    QLabel *label_13;
    QWidget *cashButtons;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *cashTable;
    QWidget *CandleStickPage;
    QVBoxLayout *verticalLayout_3;
    QWidget *chartControls;
    QHBoxLayout *controlsLayout;
    QWidget *tradingButtons;
    QHBoxLayout *tradingLayout;
    QPushButton *buyButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBox;
    QPushButton *sellButton;
    QSpacerItem *horizontalSpacer;
    QWidget *companySymbols;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *companySymbolsCombo;
    QWidget *chartTypeWidget;
    QHBoxLayout *chartTypeLayout;
    QLabel *chartTypeLabel;
    QPushButton *chartTypeToggle;
    QWidget *rsiWidget;
    QHBoxLayout *rsiLayout;
    QLabel *rsiLabel;
    QPushButton *rsiToggle;
    QWidget *algorithmsWidget;
    QHBoxLayout *algorithmsLayout;
    QLabel *algorithmsLabel;
    QComboBox *algorithmsCombo;
    QChartView *chartWidget;
    QChartView *indicatorChart;
    QWidget *HistoryPage;
    QGridLayout *gridLayout_8;
    QWidget *historyTitle;
    QGridLayout *gridLayout_3;
    QLabel *title;
    QTableView *historyTable;

    void setupUi(QMainWindow *pages)
    {
        if (pages->objectName().isEmpty())
            pages->setObjectName("pages");
        pages->resize(1413, 872);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pages->sizePolicy().hasHeightForWidth());
        pages->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
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
        horizontalLayout->setObjectName("horizontalLayout");
        navPanel = new QWidget(centralwidget);
        navPanel->setObjectName("navPanel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(navPanel->sizePolicy().hasHeightForWidth());
        navPanel->setSizePolicy(sizePolicy1);
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


        horizontalLayout->addWidget(navPanel);

        contentPanel = new QWidget(centralwidget);
        contentPanel->setObjectName("contentPanel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(9);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(contentPanel->sizePolicy().hasHeightForWidth());
        contentPanel->setSizePolicy(sizePolicy2);
        verticalLayout_4 = new QVBoxLayout(contentPanel);
        verticalLayout_4->setObjectName("verticalLayout_4");
        stackedWidget = new QStackedWidget(contentPanel);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 100px;\n"
"    min-height: 40px;\n"
"    padding: 6px 12px;\n"
"    border-radius: 20px; /* Full rounded look */\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    background-color: #333; /* Default dark for Withdraw */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    opacity: 0.85;\n"
"}\n"
""));
        PortfolioPage = new QWidget();
        PortfolioPage->setObjectName("PortfolioPage");
        gridLayout = new QGridLayout(PortfolioPage);
        gridLayout->setObjectName("gridLayout");
        Cards = new QFrame(PortfolioPage);
        Cards->setObjectName("Cards");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(Cards->sizePolicy().hasHeightForWidth());
        Cards->setSizePolicy(sizePolicy3);
        Cards->setFrameShape(QFrame::Shape::NoFrame);
        Cards->setFrameShadow(QFrame::Shadow::Plain);
        horizontalLayout_2 = new QHBoxLayout(Cards);
        horizontalLayout_2->setSpacing(11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_4 = new QWidget(Cards);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8(" background-color: rgba(200, 255, 200, 30);  /* Light translucent green */\n"
"    border-radius: 12px;                        /* Curved corners */\n"
"    padding: 12px;                              /* Space inside the card */"));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        QFont font;
        font.setPointSize(14);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_6->addWidget(label_7);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_6->addWidget(label_6);


        horizontalLayout_2->addWidget(widget_4);

        widget_2 = new QWidget(Cards);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8(" background-color: rgba(200, 255, 200, 30);  /* Light translucent green */\n"
"    border-radius: 12px;                        /* Curved corners */\n"
"    padding: 12px;                              /* Space inside the card */"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_5->addWidget(label_4);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_5->addWidget(label_5);


        horizontalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(Cards);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8(" background-color: rgba(200, 255, 200, 30);  /* Light translucent green */\n"
"    border-radius: 12px;                        /* Curved corners */\n"
"    padding: 12px;                              /* Space inside the card */"));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_8 = new QLabel(widget_3);
        label_8->setObjectName("label_8");
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_7->addWidget(label_8);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_7->addWidget(label_9);


        horizontalLayout_2->addWidget(widget_3);


        gridLayout->addWidget(Cards, 1, 0, 1, 1);

        table = new QTableView(PortfolioPage);
        table->setObjectName("table");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(6);
        sizePolicy4.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy4);
        table->setMinimumSize(QSize(0, 0));
        table->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #2E2E2E;\n"
"    color: white;\n"
"    gridline-color: #505050;\n"
"    font-size: 10 px;\n"
"    border: none;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #444;\n"
"    color: white;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 6px;\n"
"    border-bottom: 1px solid #505050;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #66ccff;\n"
"    color: black;\n"
"}\n"
""));
        table->setTabKeyNavigation(true);
        table->setShowGrid(false);
        table->horizontalHeader()->setVisible(true);
        table->verticalHeader()->setVisible(false);

        gridLayout->addWidget(table, 2, 0, 1, 1);

        portfolioTitle = new QLabel(PortfolioPage);
        portfolioTitle->setObjectName("portfolioTitle");
        portfolioTitle->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 50px;\n"
"font-weight: bold;"));

        gridLayout->addWidget(portfolioTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(PortfolioPage);
        CashPage = new QWidget();
        CashPage->setObjectName("CashPage");
        verticalLayout_2 = new QVBoxLayout(CashPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        cashTitle = new QWidget(CashPage);
        cashTitle->setObjectName("cashTitle");
        gridLayout_4 = new QGridLayout(cashTitle);
        gridLayout_4->setObjectName("gridLayout_4");
        Title_2 = new QWidget(cashTitle);
        Title_2->setObjectName("Title_2");
        sizePolicy3.setHeightForWidth(Title_2->sizePolicy().hasHeightForWidth());
        Title_2->setSizePolicy(sizePolicy3);
        verticalLayout_8 = new QVBoxLayout(Title_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_10 = new QLabel(Title_2);
        label_10->setObjectName("label_10");
        QFont font1;
        font1.setBold(true);
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 50px;\n"
"font-weight: bold;"));

        verticalLayout_8->addWidget(label_10);

        label_12 = new QLabel(Title_2);
        label_12->setObjectName("label_12");
        QFont font2;
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 20px;\n"
""));

        verticalLayout_8->addWidget(label_12);


        gridLayout_4->addWidget(Title_2, 0, 0, 1, 1);


        verticalLayout_2->addWidget(cashTitle);

        cashCard = new QWidget(CashPage);
        cashCard->setObjectName("cashCard");
        gridLayout_5 = new QGridLayout(cashCard);
        gridLayout_5->setObjectName("gridLayout_5");
        Cards_2 = new QFrame(cashCard);
        Cards_2->setObjectName("Cards_2");
        sizePolicy3.setHeightForWidth(Cards_2->sizePolicy().hasHeightForWidth());
        Cards_2->setSizePolicy(sizePolicy3);
        Cards_2->setFrameShape(QFrame::Shape::NoFrame);
        Cards_2->setFrameShadow(QFrame::Shadow::Plain);
        horizontalLayout_3 = new QHBoxLayout(Cards_2);
        horizontalLayout_3->setSpacing(11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_11 = new QWidget(Cards_2);
        widget_11->setObjectName("widget_11");
        widget_11->setStyleSheet(QString::fromUtf8(" background-color: rgba(200, 255, 200, 30);  /* Light translucent green */\n"
"    border-radius: 12px;                        /* Curved corners */\n"
"    padding: 12px;                              /* Space inside the card */"));
        verticalLayout_9 = new QVBoxLayout(widget_11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_11 = new QLabel(widget_11);
        label_11->setObjectName("label_11");
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_9->addWidget(label_11);

        label_13 = new QLabel(widget_11);
        label_13->setObjectName("label_13");
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;"));

        verticalLayout_9->addWidget(label_13);


        horizontalLayout_3->addWidget(widget_11);


        gridLayout_5->addWidget(Cards_2, 0, 0, 1, 1);


        verticalLayout_2->addWidget(cashCard);

        cashButtons = new QWidget(CashPage);
        cashButtons->setObjectName("cashButtons");
        horizontalLayout_4 = new QHBoxLayout(cashButtons);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton = new QPushButton(cashButtons);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 30px;\n"
"    min-height: 20px;\n"
"    padding: 6px 12px;\n"
"    border-radius: 15px; /* Full rounded look */\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    background-color: #8dd279; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    opacity: 0.85;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(cashButtons);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 30px;\n"
"    min-height: 20px;\n"
"    padding: 6px 12px;\n"
"    border-radius: 15px; /* Full rounded look */\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #333; /* Default dark for Withdraw */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    opacity: 0.85;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_2->addWidget(cashButtons);

        cashTable = new QTableView(CashPage);
        cashTable->setObjectName("cashTable");
        cashTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #1e1e1e;\n"
"    alternate-background-color: #2a2a2a;\n"
"    gridline-color: #3c3c3c;\n"
"    font-size: 14px;\n"
"    font-family: \"Segoe UI\", \"Arial\", sans-serif;\n"
"    color: #e0e0e0;\n"
"    border: 1px solid #3c3c3c;\n"
"    selection-background-color: #007acc;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2d2d30;\n"
"    color: #e6e6e6;\n"
"    font-weight: bold;\n"
"    padding: 6px;\n"
"    border: 1px solid #3c3c3c;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 4px;\n"
"    border-bottom: 1px solid #2f2f2f;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #005f9e;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #2a2a2a;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #5a5a5a;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::ad"
                        "d-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0;\n"
"    background: none;\n"
"}\n"
""));

        verticalLayout_2->addWidget(cashTable);

        verticalLayout_2->setStretch(3, 5);
        stackedWidget->addWidget(CashPage);
        CandleStickPage = new QWidget();
        CandleStickPage->setObjectName("CandleStickPage");
        verticalLayout_3 = new QVBoxLayout(CandleStickPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chartControls = new QWidget(CandleStickPage);
        chartControls->setObjectName("chartControls");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(chartControls->sizePolicy().hasHeightForWidth());
        chartControls->setSizePolicy(sizePolicy5);
        chartControls->setMinimumSize(QSize(0, 80));
        controlsLayout = new QHBoxLayout(chartControls);
        controlsLayout->setSpacing(15);
        controlsLayout->setObjectName("controlsLayout");
        controlsLayout->setContentsMargins(10, -1, 10, -1);
        tradingButtons = new QWidget(chartControls);
        tradingButtons->setObjectName("tradingButtons");
        tradingButtons->setEnabled(true);
        tradingLayout = new QHBoxLayout(tradingButtons);
        tradingLayout->setSpacing(10);
        tradingLayout->setObjectName("tradingLayout");
        buyButton = new QPushButton(tradingButtons);
        buyButton->setObjectName("buyButton");
        buyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 80px;\n"
"    min-height: 35px;\n"
"    padding: 8px 16px;\n"
"    border-radius: 18px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #4CAF50; /* Green for buy */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));

        tradingLayout->addWidget(buyButton);

        widget = new QWidget(tradingButtons);
        widget->setObjectName("widget");
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName("spinBox");
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #555;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    font: bold 12px \"Segoe UI\";\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    background-color: #3A3A3A;\n"
"    border-left: 1px solid #555;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    subcontrol-position: top right;\n"
"    border-top-right-radius: 6px;\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"    border-bottom-right-radius: 6px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #505050;\n"
"}\n"
"\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"QSpinBox::up-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    image: none;\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"    width: 10px;\n"
"    heigh"
                        "t: 10px;\n"
"    image: none;\n"
"}\n"
""));

        horizontalLayout_6->addWidget(spinBox);


        tradingLayout->addWidget(widget);

        sellButton = new QPushButton(tradingButtons);
        sellButton->setObjectName("sellButton");
        sellButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 80px;\n"
"    min-height: 35px;\n"
"    padding: 8px 16px;\n"
"    border-radius: 18px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #f44336; /* Red for sell */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #da190b;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #c62828;\n"
"}"));

        tradingLayout->addWidget(sellButton);


        controlsLayout->addWidget(tradingButtons);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        controlsLayout->addItem(horizontalSpacer);

        companySymbols = new QWidget(chartControls);
        companySymbols->setObjectName("companySymbols");
        horizontalLayout_5 = new QHBoxLayout(companySymbols);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        companySymbolsCombo = new QComboBox(companySymbols);
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->addItem(QString());
        companySymbolsCombo->setObjectName("companySymbolsCombo");
        companySymbolsCombo->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    min-width: 120px;\n"
"    min-height: 30px;\n"
"    padding: 5px 10px;\n"
"    border-radius: 15px;\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #505050;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #E0E0E0;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    selection-background-color: #555;\n"
"    border: 1px solid #555;\n"
"    border-radius: 8px;\n"
"}"));

        horizontalLayout_5->addWidget(companySymbolsCombo);


        controlsLayout->addWidget(companySymbols);

        chartTypeWidget = new QWidget(chartControls);
        chartTypeWidget->setObjectName("chartTypeWidget");
        chartTypeLayout = new QHBoxLayout(chartTypeWidget);
        chartTypeLayout->setSpacing(5);
        chartTypeLayout->setObjectName("chartTypeLayout");
        chartTypeLabel = new QLabel(chartTypeWidget);
        chartTypeLabel->setObjectName("chartTypeLabel");
        chartTypeLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;\n"
"font-size: 12px;"));

        chartTypeLayout->addWidget(chartTypeLabel);

        chartTypeToggle = new QPushButton(chartTypeWidget);
        chartTypeToggle->setObjectName("chartTypeToggle");
        chartTypeToggle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 100px;\n"
"    min-height: 30px;\n"
"    padding: 5px 10px;\n"
"    border-radius: 15px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #2196F3;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1976D2;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1565C0;\n"
"}"));
        chartTypeToggle->setCheckable(true);

        chartTypeLayout->addWidget(chartTypeToggle);


        controlsLayout->addWidget(chartTypeWidget);

        rsiWidget = new QWidget(chartControls);
        rsiWidget->setObjectName("rsiWidget");
        rsiLayout = new QHBoxLayout(rsiWidget);
        rsiLayout->setSpacing(5);
        rsiLayout->setObjectName("rsiLayout");
        rsiLabel = new QLabel(rsiWidget);
        rsiLabel->setObjectName("rsiLabel");
        rsiLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;\n"
"font-size: 12px;"));

        rsiLayout->addWidget(rsiLabel);

        rsiToggle = new QPushButton(rsiWidget);
        rsiToggle->setObjectName("rsiToggle");
        rsiToggle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    min-width: 60px;\n"
"    min-height: 30px;\n"
"    padding: 5px 10px;\n"
"    border-radius: 15px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #666;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #777;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    background-color: #FF9800;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #F57C00;\n"
"}"));
        rsiToggle->setCheckable(true);

        rsiLayout->addWidget(rsiToggle);


        controlsLayout->addWidget(rsiWidget);

        algorithmsWidget = new QWidget(chartControls);
        algorithmsWidget->setObjectName("algorithmsWidget");
        algorithmsLayout = new QHBoxLayout(algorithmsWidget);
        algorithmsLayout->setSpacing(5);
        algorithmsLayout->setObjectName("algorithmsLayout");
        algorithmsLabel = new QLabel(algorithmsWidget);
        algorithmsLabel->setObjectName("algorithmsLabel");
        algorithmsLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: white;\n"
"border: none;\n"
"font-size: 12px;"));

        algorithmsLayout->addWidget(algorithmsLabel);

        algorithmsCombo = new QComboBox(algorithmsWidget);
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->addItem(QString());
        algorithmsCombo->setObjectName("algorithmsCombo");
        algorithmsCombo->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    min-width: 120px;\n"
"    min-height: 30px;\n"
"    padding: 5px 10px;\n"
"    border-radius: 15px;\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #505050;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #E0E0E0;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #3A3A3A;\n"
"    color: #E0E0E0;\n"
"    selection-background-color: #555;\n"
"    border: 1px solid #555;\n"
"    border-radius: 8px;\n"
"}"));

        algorithmsLayout->addWidget(algorithmsCombo);


        controlsLayout->addWidget(algorithmsWidget);


        verticalLayout_3->addWidget(chartControls);

        chartWidget = new QChartView(CandleStickPage);
        chartWidget->setObjectName("chartWidget");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(2);
        sizePolicy6.setHeightForWidth(chartWidget->sizePolicy().hasHeightForWidth());
        chartWidget->setSizePolicy(sizePolicy6);

        verticalLayout_3->addWidget(chartWidget);

        indicatorChart = new QChartView(CandleStickPage);
        indicatorChart->setObjectName("indicatorChart");

        verticalLayout_3->addWidget(indicatorChart);

        verticalLayout_3->setStretch(2, 2);
        stackedWidget->addWidget(CandleStickPage);
        HistoryPage = new QWidget();
        HistoryPage->setObjectName("HistoryPage");
        gridLayout_8 = new QGridLayout(HistoryPage);
        gridLayout_8->setObjectName("gridLayout_8");
        historyTitle = new QWidget(HistoryPage);
        historyTitle->setObjectName("historyTitle");
        gridLayout_3 = new QGridLayout(historyTitle);
        gridLayout_3->setObjectName("gridLayout_3");
        title = new QLabel(historyTitle);
        title->setObjectName("title");
        QFont font3;
        font3.setPointSize(24);
        font3.setBold(true);
        title->setFont(font3);
        title->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 50;\n"
"font-weight: bold;"));

        gridLayout_3->addWidget(title, 0, 0, 1, 1);

        historyTable = new QTableView(historyTitle);
        historyTable->setObjectName("historyTable");

        gridLayout_3->addWidget(historyTable, 1, 0, 1, 1);


        gridLayout_8->addWidget(historyTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(HistoryPage);

        verticalLayout_4->addWidget(stackedWidget);


        horizontalLayout->addWidget(contentPanel);

        pages->setCentralWidget(centralwidget);

        retranslateUi(pages);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(pages);
    } // setupUi

    void retranslateUi(QMainWindow *pages)
    {
        pages->setWindowTitle(QCoreApplication::translate("pages", "MainWindow", nullptr));
        Portfolio->setText(QString());
        Cash->setText(QString());
        Investment->setText(QString());
        Ledger->setText(QString());
        label_7->setText(QCoreApplication::translate("pages", "Total Value:", nullptr));
        label_6->setText(QCoreApplication::translate("pages", "Rs. XXXX", nullptr));
        label_4->setText(QCoreApplication::translate("pages", "Total Gain/Loss:", nullptr));
        label_5->setText(QCoreApplication::translate("pages", "Rs. XXXX", nullptr));
        label_8->setText(QCoreApplication::translate("pages", "Total Change:", nullptr));
        label_9->setText(QCoreApplication::translate("pages", " XX.XXX %", nullptr));
        portfolioTitle->setText(QCoreApplication::translate("pages", "My Portfolio", nullptr));
        label_10->setText(QCoreApplication::translate("pages", "Cash", nullptr));
        label_12->setText(QCoreApplication::translate("pages", "Manage your cash balance", nullptr));
        label_11->setText(QCoreApplication::translate("pages", "Cash Balance:", nullptr));
        label_13->setText(QCoreApplication::translate("pages", "Rs. XXXX", nullptr));
        pushButton->setText(QCoreApplication::translate("pages", "Deposit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pages", "Withdraw", nullptr));
        buyButton->setText(QCoreApplication::translate("pages", "BUY", nullptr));
        sellButton->setText(QCoreApplication::translate("pages", "SELL", nullptr));
        companySymbolsCombo->setItemText(0, QCoreApplication::translate("pages", "BBC", nullptr));
        companySymbolsCombo->setItemText(1, QCoreApplication::translate("pages", "NRIC", nullptr));
        companySymbolsCombo->setItemText(2, QCoreApplication::translate("pages", "CIT", nullptr));
        companySymbolsCombo->setItemText(3, QCoreApplication::translate("pages", "GBIME", nullptr));
        companySymbolsCombo->setItemText(4, QCoreApplication::translate("pages", "SANIMA", nullptr));
        companySymbolsCombo->setItemText(5, QCoreApplication::translate("pages", "SBI", nullptr));

        chartTypeLabel->setText(QCoreApplication::translate("pages", "Chart Type:", nullptr));
        chartTypeToggle->setText(QCoreApplication::translate("pages", "Candlestick", nullptr));
        rsiLabel->setText(QCoreApplication::translate("pages", "RSI:", nullptr));
        rsiToggle->setText(QCoreApplication::translate("pages", "OFF", nullptr));
        algorithmsLabel->setText(QCoreApplication::translate("pages", "Indicators:", nullptr));
        algorithmsCombo->setItemText(0, QCoreApplication::translate("pages", "None", nullptr));
        algorithmsCombo->setItemText(1, QCoreApplication::translate("pages", "MACD", nullptr));
        algorithmsCombo->setItemText(2, QCoreApplication::translate("pages", "Bollinger Bands", nullptr));
        algorithmsCombo->setItemText(3, QCoreApplication::translate("pages", "Moving Average", nullptr));
        algorithmsCombo->setItemText(4, QCoreApplication::translate("pages", "Stochastic", nullptr));
        algorithmsCombo->setItemText(5, QCoreApplication::translate("pages", "Williams %R", nullptr));
        algorithmsCombo->setItemText(6, QCoreApplication::translate("pages", "CCI", nullptr));

        title->setText(QCoreApplication::translate("pages", "Transaction History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pages: public Ui_pages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGES_H
