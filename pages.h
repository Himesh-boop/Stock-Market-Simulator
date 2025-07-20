#ifndef PAGES_H
#define PAGES_H

#include <QMainWindow>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
#include <QDateTime>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <qjsonarray.h>
#include "db/transactiondb.h"
#include "db/cashdb.h"
#include "db/portfoliodb.h"


namespace Ui {
class pages;
}

class pages : public QMainWindow
{
    Q_OBJECT

public:
    explicit pages(QWidget *parent = nullptr);
    ~pages();
    void fetchStockData();
    void setUsername(const QString& username);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

private slots:
    void onButtonToggled(bool checked);

private:
    Ui::pages *ui;
    QPropertyAnimation *currentAnimation;
    QPushButton *lastCheckedButton;
    QString m_username;

    QChartView *chartView = nullptr;
    QCandlestickSeries *candlestickSeries = nullptr;
    QChart *chart = nullptr;

    CashDB* cashDB;
    PortfolioDB* portfolioDB;
    TransactionDB* transactionDB;

    QBarSeries *volumeSeries;
    QBarSet *volumeSet;
    QValueAxis *volumeAxisY;
    QDateTimeAxis* axisX;
    QValueAxis* axisYPrice;

    double originalMinPrice;
    double originalMaxPrice;
    double originalMaxVolume;
    QDateTime originalFirstDate;
    QDateTime originalLastDate;

    void resetZoom();
    void setupCandlestickChart();
    void updateCandlestickChart(const QJsonArray &data);
    void buyButtonPushed();
    void sellButtonPushed();
    double pricePerShare;
    QJsonArray jsonArray;
    void extractLatestClosingPrice(const QJsonArray &data);
    void loadCashTable();
    void loadPortfolioTable();
    void loadHistoryTable();
    // void onIndicatorChanged(int index);
    void drawIndicatorOverlay(const QJsonArray& data, const QString& indicator);
    void updateIndicatorChart(const QJsonArray &data, const QString &indicatorName);
    void handleDepositClicked();
    void handleWithdrawClicked();
    void updateCashUI();
};

#endif // PAGES_H
