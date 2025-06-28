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
    void fetchStockData(const QString& symbol);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

private slots:
    void onButtonToggled(bool checked);

private:
    Ui::pages *ui;
    QPropertyAnimation *currentAnimation;
    QPushButton *lastCheckedButton;

    // Chart related members
    QChartView *chartView = nullptr;
    QCandlestickSeries *candlestickSeries = nullptr;
    QChart *chart = nullptr;

    QBarSeries *volumeSeries;
    QBarSet *volumeSet;
    QValueAxis *volumeAxisY;
    QDateTimeAxis* axisX;
    QValueAxis* axisYPrice;

    // Store original ranges for zoom reset
    double originalMinPrice;
    double originalMaxPrice;
    double originalMaxVolume;
    QDateTime originalFirstDate;
    QDateTime originalLastDate;

    // Method to reset zoom
    void resetZoom();
    void setupCandlestickChart();
    void updateCandlestickChart(const QJsonArray &data);
};

#endif // PAGES_H
