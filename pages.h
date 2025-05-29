#ifndef PAGES_H
#define PAGES_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
#include <QtCharts/QChart>


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
    QtCharts::QChartView *chartView = nullptr;
    QtCharts::QCandlestickSeries *candlestickSeries = nullptr;
    QtCharts::QChart *chart = nullptr;

    void setupCandlestickChart();
    void updateCandlestickChart(const QJsonArray &data);
};

#endif // PAGES_H
