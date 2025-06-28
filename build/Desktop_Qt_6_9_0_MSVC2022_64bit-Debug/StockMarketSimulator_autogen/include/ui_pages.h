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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
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
    QWidget *Title;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *Table;
    QWidget *CashPage;
    QWidget *Title_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
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
        pages->resize(608, 408);
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
        gridLayout = new QGridLayout(PortfolioPage);
        gridLayout->setObjectName("gridLayout");
        Cards = new QFrame(PortfolioPage);
        Cards->setObjectName("Cards");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(Cards->sizePolicy().hasHeightForWidth());
        Cards->setSizePolicy(sizePolicy2);
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

        Title = new QWidget(PortfolioPage);
        Title->setObjectName("Title");
        sizePolicy2.setHeightForWidth(Title->sizePolicy().hasHeightForWidth());
        Title->setSizePolicy(sizePolicy2);
        verticalLayout_4 = new QVBoxLayout(Title);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(Title);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 50;\n"
"font-weight: bold;"));

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(Title);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 17;"));

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(Title);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 14;\n"
""));

        verticalLayout_4->addWidget(label_3);


        gridLayout->addWidget(Title, 0, 0, 1, 1);

        Table = new QTableWidget(PortfolioPage);
        if (Table->columnCount() < 5)
            Table->setColumnCount(5);
        if (Table->rowCount() < 8)
            Table->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Table->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Table->setItem(0, 3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Table->setItem(0, 4, __qtablewidgetitem4);
        QFont font3;
        font3.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font3);
        Table->setItem(1, 0, __qtablewidgetitem5);
        Table->setObjectName("Table");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(6);
        sizePolicy3.setHeightForWidth(Table->sizePolicy().hasHeightForWidth());
        Table->setSizePolicy(sizePolicy3);
        Table->setMinimumSize(QSize(400, 300));
        Table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    border-bottom: 1px solid #505050;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #66ccff;\n"
"    color: black;\n"
"}\n"
""));
        Table->setTabKeyNavigation(true);
        Table->setShowGrid(false);
        Table->setRowCount(8);
        Table->setColumnCount(5);
        Table->horizontalHeader()->setVisible(false);
        Table->verticalHeader()->setVisible(false);

        gridLayout->addWidget(Table, 2, 0, 1, 1);

        stackedWidget->addWidget(PortfolioPage);
        CashPage = new QWidget();
        CashPage->setObjectName("CashPage");
        Title_2 = new QWidget(CashPage);
        Title_2->setObjectName("Title_2");
        Title_2->setGeometry(QRect(-10, 0, 451, 109));
        sizePolicy2.setHeightForWidth(Title_2->sizePolicy().hasHeightForWidth());
        Title_2->setSizePolicy(sizePolicy2);
        verticalLayout_8 = new QVBoxLayout(Title_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_10 = new QLabel(Title_2);
        label_10->setObjectName("label_10");
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 50;\n"
"font-weight: bold;"));

        verticalLayout_8->addWidget(label_10);

        label_11 = new QLabel(Title_2);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 17;"));

        verticalLayout_8->addWidget(label_11);

        label_12 = new QLabel(Title_2);
        label_12->setObjectName("label_12");
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("background-color : transparent;\n"
"color : white;\n"
"border: none;\n"
"font-size: 14;\n"
""));

        verticalLayout_8->addWidget(label_12);

        stackedWidget->addWidget(CashPage);
        CandleStickPage = new QWidget();
        CandleStickPage->setObjectName("CandleStickPage");
        verticalLayout_3 = new QVBoxLayout(CandleStickPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chartWidget = new QChartView(CandleStickPage);
        chartWidget->setObjectName("chartWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(chartWidget->sizePolicy().hasHeightForWidth());
        chartWidget->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(chartWidget);

        widget = new QWidget(CandleStickPage);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);

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

        stackedWidget->setCurrentIndex(0);


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
        label_7->setText(QCoreApplication::translate("pages", "Total Value:", nullptr));
        label_6->setText(QCoreApplication::translate("pages", "Rs. XXXX", nullptr));
        label_4->setText(QCoreApplication::translate("pages", "Total Gain/Loss:", nullptr));
        label_5->setText(QCoreApplication::translate("pages", "Rs. XXXX", nullptr));
        label_8->setText(QCoreApplication::translate("pages", "Total Change:", nullptr));
        label_9->setText(QCoreApplication::translate("pages", " XX.XXX %", nullptr));
        label->setText(QCoreApplication::translate("pages", "My Portfolio", nullptr));
        label_2->setText(QCoreApplication::translate("pages", "Track your investments and gains", nullptr));
        label_3->setText(QCoreApplication::translate("pages", "Portfolio Overview", nullptr));

        const bool __sortingEnabled = Table->isSortingEnabled();
        Table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = Table->item(0, 0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("pages", "Symbol", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table->item(0, 1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("pages", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Table->item(0, 2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("pages", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Table->item(0, 3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("pages", "Current Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Table->item(0, 4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("pages", "Total Value", nullptr));
        Table->setSortingEnabled(__sortingEnabled);

        label_10->setText(QCoreApplication::translate("pages", "My Portfolio", nullptr));
        label_11->setText(QCoreApplication::translate("pages", "Track your investments and gains", nullptr));
        label_12->setText(QCoreApplication::translate("pages", "Portfolio Overview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pages: public Ui_pages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGES_H
