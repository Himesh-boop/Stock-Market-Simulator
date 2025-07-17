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
    void extractLatestClosingPrice(const QJsonArray &data);
    void loadCashTable();
    void loadPortfolioTable();
    void loadHistoryTable();

};

#endif // PAGES_H
