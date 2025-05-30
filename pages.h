#ifndef PAGES_H
#define PAGES_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
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


    void setupCandlestickChart();
    void updateCandlestickChart(const QJsonArray &data);
};

#endif // PAGES_H
