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

    void setupCandlestickChart();
    void updateCandlestickChart(const QJsonArray &data);
};

#endif // PAGES_H
