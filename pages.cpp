#include "pages.h"
#include "ui_pages.h"
#include <QProcess>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
#include <QtCharts/QChart>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QWheelEvent>
#include <QKeyEvent>
#include <algorithm>
#include <limits>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include "db/transactiondb.h"
#include "db/portfoliodb.h"

class CustomChartView : public QChartView {
public:
    CustomChartView(QWidget* parent = nullptr) : QChartView(parent) {
        setRubberBand(QChartView::RectangleRubberBand);
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

protected:
    void wheelEvent(QWheelEvent* event) override {
        if (chart()) {
            const qreal factor = 1.15;
            if (event->angleDelta().y() > 0) {
                chart()->zoom(factor);
            } else {
                chart()->zoom(1.0 / factor);
            }
            event->accept();
        }
    }

    void keyPressEvent(QKeyEvent* event) override {
        if (event->key() == Qt::Key_R) {
            if (chart()) {
                chart()->zoomReset();
            }
        }
        QChartView::keyPressEvent(event);
    }
};

void pages::setUsername(const QString &username)
{
    m_username = username;
    m_username[0] = m_username[0].toUpper();
    // ui->label->setText(QString("%1's Portfolio").arg(m_username));
}

void pages::fetchStockData() {
    QProcess* process = new QProcess(this);

    connect(process, &QProcess::finished, this, [this, process]() {
        QByteArray output = process->readAllStandardOutput();
        QByteArray errorOutput = process->readAllStandardError();
        QString jsonString = QString(output).trimmed();

        qDebug() << "Python script output:" << jsonString;
        qDebug() << "Python script error output:" << errorOutput;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        if (jsonDoc.isNull()) {
            qDebug() << "Failed to parse JSON data: invalid JSON";
            process->deleteLater();
            return;
        }
        if (!jsonDoc.isArray()) {
            qDebug() << "JSON is not an array but a" << (jsonDoc.isObject() ? "object" : "unknown type");
            process->deleteLater();
            return;
        }

        QJsonArray jsonArray = jsonDoc.array();
        qDebug() << "Received data points:" << jsonArray.size();

        if (!jsonArray.isEmpty()) {
            QJsonObject firstRecord = jsonArray.first().toObject();
            qDebug() << "First record:" << firstRecord;
        }

        updateCandlestickChart(jsonArray);

        process->deleteLater();
    });

    QString pythonExecutable = "python";
    QString scriptPath = "C:/StockMarketSimulator/Stock-Market-Simulator/Models/candlestickChart.py";

    QString symbol = ui->companySymbolsCombo->currentText();

    QStringList arguments = { scriptPath, symbol };

    process->start(pythonExecutable, arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Failed to start python process";
        process->deleteLater();
    }
}

pages::pages(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pages)
    , currentAnimation(nullptr)
    , lastCheckedButton(nullptr)
    , originalMinPrice(0)
    , originalMaxPrice(0)
    , originalMaxVolume(0)
    , pricePerShare(0.0)
{
    ui->setupUi(this);

    connect(ui->buyButton, &QPushButton::clicked, this, &pages::buyButtonPushed);
    connect(ui->sellButton, &QPushButton::clicked, this, &pages::sellButtonPushed);
    connect(ui->companySymbolsCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &pages::fetchStockData);

    connect(ui->Portfolio, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Cash, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Investment, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Ledger, &QPushButton::toggled, this, &pages::onButtonToggled);

    ui->Portfolio->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);



    ui->Table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);            // Symbol
    ui->Table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);          // Name
    ui->Table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Quantity
    ui->Table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Curr Price
    ui->Table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Total Price

    ui->cashTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);  // Date
    ui->cashTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);          // Type
    ui->cashTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Amount

    //fix width for symbol column
    ui->Table->setColumnWidth(0, 100);


    ui->cashTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);  // Date
    ui->cashTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);  // Type
    ui->cashTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);  // Amount

    ui->tableHistory->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Date
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents); // Type
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch); // Symbol
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Quantity
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Price
    ui->tableHistory->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch); // Total
    setupCandlestickChart();
}

pages::~pages()
{
    if (currentAnimation) {
        delete currentAnimation;
    }
}

void pages::onButtonToggled(bool checked)
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button || !checked) return;

    // Switch to corresponding page in stacked widget
    if (button == ui->Portfolio) {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (button == ui->Cash) {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (button == ui->Investment) {
        ui->stackedWidget->setCurrentIndex(2);
        fetchStockData();
    } else if (button == ui->Ledger) {
        ui->stackedWidget->setCurrentIndex(3);
    }

    if (currentAnimation) {
        currentAnimation->stop();
        delete currentAnimation;
    }

    // Original position
    QRect origGeometry = button->geometry();

    currentAnimation = new QPropertyAnimation(button, "geometry");
    currentAnimation->setDuration(150); // 150ms animation
    currentAnimation->setStartValue(origGeometry);

    QRect targetGeometry = origGeometry;
    targetGeometry.setLeft(origGeometry.left() + 20);
    targetGeometry.setRight(origGeometry.right() + 20);

    currentAnimation->setEndValue(targetGeometry);
    currentAnimation->setEasingCurve(QEasingCurve::OutCubic);
    currentAnimation->start();

    if (lastCheckedButton && lastCheckedButton != button) {
        QPropertyAnimation *reverseAnim = new QPropertyAnimation(lastCheckedButton, "geometry");
        reverseAnim->setDuration(150);
        QRect lastButtonGeom = lastCheckedButton->geometry();
        reverseAnim->setStartValue(lastButtonGeom);

        QRect origLastButtonGeom = lastButtonGeom;
        origLastButtonGeom.setLeft(lastButtonGeom.left() - 20);
        origLastButtonGeom.setRight(lastButtonGeom.right() - 20);

        reverseAnim->setEndValue(origLastButtonGeom);
        reverseAnim->setEasingCurve(QEasingCurve::OutCubic);

        reverseAnim->start(QAbstractAnimation::DeleteWhenStopped);
    }

    lastCheckedButton = button;
}

void pages::setupCandlestickChart() {
    chart = new QChart();
    candlestickSeries = new QCandlestickSeries();
    volumeSeries = new QBarSeries();
    volumeSet = new QBarSet("Volume");

    chart->addSeries(candlestickSeries);
    chart->addSeries(volumeSeries);
    volumeSeries->append(volumeSet);

    chart->setTitle("Stock Price Chart with Volume");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    axisX = new QDateTimeAxis();
    axisX->setFormat("dd-MM");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    candlestickSeries->attachAxis(axisX);
    volumeSeries->attachAxis(axisX);

    axisYPrice = new QValueAxis();
    axisYPrice->setTitleText("Price");
    chart->addAxis(axisYPrice, Qt::AlignLeft);
    candlestickSeries->attachAxis(axisYPrice);

    volumeAxisY = new QValueAxis();
    volumeAxisY->setTitleText("Volume");
    chart->addAxis(volumeAxisY, Qt::AlignRight);
    volumeSeries->attachAxis(volumeAxisY);

    chartView = qobject_cast<QChartView*>(ui->chartWidget);

    if (!chartView) {
        QWidget* parent = ui->chartWidget->parentWidget();

        QRect geometry = ui->chartWidget->geometry();
        QString objectName = ui->chartWidget->objectName();

        chartView = new CustomChartView(parent);
        chartView->setObjectName(objectName);
        chartView->setGeometry(geometry);

        ui->chartWidget->hide();
        chartView->show();

        ui->chartWidget = chartView;
    } else {
        chartView->installEventFilter(this);
    }

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
    chartView->setDragMode(QGraphicsView::ScrollHandDrag);
    chartView->setInteractive(true);

    qDebug() << "Chart setup complete with candlestick + volume bars and custom zoom.";
}

void pages::updateCandlestickChart(const QJsonArray &data) {
    if (!candlestickSeries || !volumeSet || data.isEmpty()) {
        qDebug() << "No series or empty data";
        return;
    }

    // Clear existing data
    candlestickSeries->clear();
    volumeSet->remove(0, volumeSet->count());

    qDebug() << "=== Stock Data with Volume ===";

    // Sort by date
    QVector<QJsonValue> tempList;
    for (const QJsonValue &val : data) {
        tempList.append(val);
    }

    std::sort(tempList.begin(), tempList.end(), [](const QJsonValue &a, const QJsonValue &b) {
        return a.toObject()["date"].toString() < b.toObject()["date"].toString();
    });

    QJsonArray sortedData;
    for (const QJsonValue &val : tempList) {
        sortedData.append(val);
    }

    // Track ranges for proper axis management
    double maxVolume = 0;
    double minPrice = std::numeric_limits<double>::max();
    double maxPrice = std::numeric_limits<double>::lowest();
    QDateTime firstDate, lastDate;

    for (int i = 0; i < sortedData.size(); ++i) {
        QJsonObject obj = sortedData[i].toObject();

        QString dateStr = obj["date"].toString();
        double open = obj["open"].toDouble();
        double high = obj["high"].toDouble();
        double low = obj["low"].toDouble();
        double close = obj["close"].toDouble();
        double volume = obj["volume"].toDouble();

        maxVolume = std::max(maxVolume, volume);
        minPrice = std::min(minPrice, low);
        maxPrice = std::max(maxPrice, high);

        qDebug() << QString("Date: %1 | O: %2 | H: %3 | L: %4 | C: %5 | Vol: %6")
                        .arg(dateStr).arg(open).arg(high).arg(low).arg(close).arg(volume);

        QDateTime dateTime = QDateTime::fromString(dateStr, "yyyy-MM-ddT00:00:00.000");
        if (!dateTime.isValid()) {
            qDebug() << "Invalid date format:" << dateStr;
            continue;
        }

        if (i == 0) firstDate = dateTime;
        if (i == sortedData.size() - 1) lastDate = dateTime;

        qint64 timestamp = dateTime.toMSecsSinceEpoch();

        // Candlestick
        auto *candlestickSet = new QCandlestickSet(timestamp);
        candlestickSet->setOpen(open);
        candlestickSet->setHigh(high);
        candlestickSet->setLow(low);
        candlestickSet->setClose(close);
        candlestickSet->setBrush(close >= open ? Qt::green : Qt::red);
        candlestickSeries->append(candlestickSet);

        // Volume
        volumeSet->append(volume);
    }

    originalMinPrice = minPrice * 0.95;
    originalMaxPrice = maxPrice * 1.05;
    originalMaxVolume = maxVolume * 1.1;
    originalFirstDate = firstDate;
    originalLastDate = lastDate;

    axisYPrice->setRange(originalMinPrice, originalMaxPrice);
    volumeAxisY->setRange(0, originalMaxVolume);
    axisX->setRange(originalFirstDate, originalLastDate);

    qDebug() << "=== End Stock Data ===";
    qDebug() << "Added" << candlestickSeries->count() << "candlestick sets and"
             << volumeSet->count() << "volume bars.";
}

void pages::resetZoom() {
    if (chart && axisYPrice && volumeAxisY && axisX) {
        axisYPrice->setRange(originalMinPrice, originalMaxPrice);
        volumeAxisY->setRange(0, originalMaxVolume);
        axisX->setRange(originalFirstDate, originalLastDate);
        chart->zoomReset();
    }
}

bool pages::eventFilter(QObject* obj, QEvent* event) {
    if (obj == chartView && event->type() == QEvent::Wheel) {
        QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
        if (chart) {
            const qreal factor = 1.15;
            if (wheelEvent->angleDelta().y() > 0) {
                chart->zoom(factor);
            } else {
                chart->zoom(1.0 / factor);
            }
            return true;
        }
    } else if (obj == chartView && event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_R) {
            resetZoom();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

// Alternative simpler approach - get the last item from the already sorted data
void pages::extractLatestClosingPrice(const QJsonArray &data) {
    if (data.isEmpty()) {
        qDebug() << "No data available to extract closing price";
        pricePerShare = 0.0;
        return;
    }

    QJsonObject latestEntry = data.last().toObject();
    pricePerShare = latestEntry["close"].toDouble();

    qDebug() << "Latest closing price:" << pricePerShare;
    qDebug() << "Date:" << latestEntry["date"].toString();
}

void pages::buyButtonPushed() {
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString symbol = ui->companySymbolsCombo->currentText();
    int quantity = ui->spinBox->value();

    TransactionDB tdb;
    tdb.insertEntry(currentTime, "BUY", symbol, quantity, pricePerShare);
}

void pages::sellButtonPushed(){
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString symbol = ui->companySymbolsCombo->currentText();
    int quantity = ui->spinBox->value();

    TransactionDB tdb;
    tdb.insertEntry(currentTime, "SELL", symbol, quantity, pricePerShare);
}

void pages::loadPortfolioTable() {
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);  // parent set to this to auto-manage memory
    model->setQuery("SELECT symbol, name, quantity, current_price, total_value FROM portfolio", db);

    if (model->lastError().isValid()) {
        qDebug() << "Query error:" << model->lastError().text();
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, "Symbol");
    model->setHeaderData(1, Qt::Horizontal, "Company");
    model->setHeaderData(2, Qt::Horizontal, "Shares");
    model->setHeaderData(3, Qt::Horizontal, "Current Price");
    model->setHeaderData(4, Qt::Horizontal, "Total Value");

    ui->Table->setModel(model);
    ui->Table->resizeColumnsToContents();
}

