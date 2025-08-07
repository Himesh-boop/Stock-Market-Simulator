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
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include "db/transactiondb.h"
#include <QLineSeries>
#include <QMessageBox>
#include <QInputDialog>
#include<QDir>

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
    ui->portfolioTitle->setText(QString("%1's Portfolio").arg(m_username));
}

void pages::fetchStockData() {
    QProcess* process = new QProcess(this);

    connect(process, &QProcess::finished, this, [this, process]() {
        QByteArray output = process->readAllStandardOutput();
        QByteArray errorOutput = process->readAllStandardError();
        QString jsonString = QString(output).trimmed();

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

        this->jsonArray = jsonArray;

        if (!jsonArray.isEmpty()) {
            QJsonObject firstRecord = jsonArray.first().toObject();
        }

        updateCandlestickChart(jsonArray);

        process->deleteLater();
    });

    QString pythonExecutable = "python";
    QString scriptPath = QDir::currentPath() + "/../Models/candlestickChart.py";

    qDebug() << "Script Path:" << scriptPath;

    QString symbol = ui->companySymbolsCombo->currentText();

    QStringList arguments = {scriptPath, symbol};

    process->start(pythonExecutable, arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Failed to start python process";
        process->deleteLater();
    }
}

void pages::updatePortfolioSummary() {
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT quantity, current_price, average_price FROM portfolio")) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    double totalValue = 0.0;
    double totalInvestment = 0.0;

    while (query.next()) {
        int quantity = query.value(0).toInt();
        double currentPrice = query.value(1).toDouble();
        double avgBuyPrice = query.value(2).toDouble();

        totalValue += quantity * currentPrice;
        totalInvestment += quantity * avgBuyPrice;
    }

    double gainLoss = totalValue - totalInvestment;
    double percentChange = (totalInvestment == 0.0) ? 0.0 : (gainLoss / totalInvestment) * 100.0;

    ui->label_6->setText("Rs. " + QString::number(totalValue, 'f', 2));
    ui->label_5->setText("Rs. " + QString::number(gainLoss, 'f', 2));
    ui->label_9->setText(QString::number(percentChange, 'f', 2) + " %");

    qDebug() << "Total Value:" << totalValue << " Gain/Loss:" << gainLoss << " Change:" << percentChange;
}

void pages::loadPortfolioTable() {
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlTableModel* model = new QSqlTableModel(this, db);
    model->setTable("portfolio");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Symbol");
    model->setHeaderData(2, Qt::Horizontal, "Name");
    model->setHeaderData(3, Qt::Horizontal, "Quantity");
    model->setHeaderData(4, Qt::Horizontal, "Current Price");
    model->setHeaderData(5, Qt::Horizontal, "Total Value");

    ui->table->setModel(model);
    ui->table->hideColumn(0);

    updatePortfolioSummary();
}

void pages::loadCashTable() {
    QSqlDatabase db = QSqlDatabase::database("cashConnection");
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("cash_transactions");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Date");
    model->setHeaderData(2, Qt::Horizontal, "Type");
    model->setHeaderData(3, Qt::Horizontal, "Amount");

    ui->cashTable->setModel(model);
    ui->cashTable->hideColumn(0);
    // ui->cashTable->resizeColumnsToContents();
}

void pages::updateCashUI() {
    double currentCash = cashDB->getCurrentBalance();
    ui->label_13->setText("Rs. " + QString::number(currentCash, 'f', 2));
    loadCashTable();
}

void pages::handleDepositClicked() {
    bool ok;
    double amount = QInputDialog::getDouble(this, "Deposit", "Enter amount:", 0, 0, 1e9, 2, &ok);
    if (ok && amount > 0) {
        QString now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        if (cashDB->insertTransaction(now, "Deposit", amount)) {
            updateCashUI();
        }
    }
}

void pages::handleWithdrawClicked() {
    bool ok;
    double amount = QInputDialog::getDouble(this, "Withdraw", "Enter amount:", 0, 0, 1e9, 2, &ok);
    if (ok && amount > 0) {
        double current = cashDB->getCurrentBalance();
        if (amount > current) {
            QMessageBox::warning(this, "Withdraw Failed", "Not enough cash.");
            return;
        }
        QString now = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        if (cashDB->insertTransaction(now, "Withdraw", amount)) {
            updateCashUI();
        }
    }
}


void pages::loadHistoryTable() {
    QSqlDatabase db = QSqlDatabase::database("TransactionConnection");
    if (!db.isOpen()) {
        qDebug() << "Transaction database not open! Error:" << db.lastError();
        return;
    }

    QSqlTableModel* model = new QSqlTableModel(this, db);
    model->setTable("transactions");

    model->setSort(1, Qt::DescendingOrder);

    if (!model->select()) {
        qDebug() << "Error loading transactions:" << model->lastError();
        return;
    }

    model->setHeaderData(1, Qt::Horizontal, "Date");
    model->setHeaderData(2, Qt::Horizontal, "Type");
    model->setHeaderData(3, Qt::Horizontal, "Symbol");
    model->setHeaderData(4, Qt::Horizontal, "Quantity");
    model->setHeaderData(5, Qt::Horizontal, "Price");
    model->setHeaderData(6, Qt::Horizontal, "Total Amount");

    ui->historyTable->setModel(model);

    ui->historyTable->hideColumn(0);

    // ui->historyTable->resizeColumnsToContents();

    ui->historyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

    cashDB = new CashDB();
    portfolioDB = new PortfolioDB();
    transactionDB = new TransactionDB();

    connect(ui->buyButton, &QPushButton::clicked, this, &pages::buyButtonPushed);
    connect(ui->sellButton, &QPushButton::clicked, this, &pages::sellButtonPushed);
    connect(ui->companySymbolsCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &pages::fetchStockData);
    connect(ui->pushButton, &QPushButton::clicked, this, &pages::handleDepositClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &pages::handleWithdrawClicked);

    connect(ui->Portfolio, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Cash, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Investment, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Ledger, &QPushButton::toggled, this, &pages::onButtonToggled);

    ui->Portfolio->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);

    loadPortfolioTable();
    loadCashTable();
    loadHistoryTable();
    updateCashUI();
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
        loadPortfolioTable();
    } else if (button == ui->Cash) {
        ui->stackedWidget->setCurrentIndex(1);
        loadCashTable();
    } else if (button == ui->Investment) {
        ui->stackedWidget->setCurrentIndex(2);
        fetchStockData();
    } else if (button == ui->Ledger) {
        ui->stackedWidget->setCurrentIndex(3);
        loadHistoryTable();
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

    candlestickSeries->clear();
    volumeSet->remove(0, volumeSet->count());

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

        QDateTime dateTime = QDateTime::fromString(dateStr, "yyyy-MM-ddT00:00:00.000");
        if (!dateTime.isValid()) {
            qDebug() << "Invalid date format:" << dateStr;
            continue;
        }

        if (i == 0) firstDate = dateTime;
        if (i == sortedData.size() - 1) lastDate = dateTime;

        qint64 timestamp = dateTime.toMSecsSinceEpoch();

        auto *candlestickSet = new QCandlestickSet(timestamp);
        candlestickSet->setOpen(open);
        candlestickSet->setHigh(high);
        candlestickSet->setLow(low);
        candlestickSet->setClose(close);
        candlestickSet->setBrush(close >= open ? Qt::green : Qt::red);
        candlestickSeries->append(candlestickSet);
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

void pages::extractLatestClosingPrice(const QJsonArray &jsonArray) {
    if (jsonArray.isEmpty()) {
        qDebug() << "No stock entries found in JSON.";
        pricePerShare = 0.0;
        return;
    }

    QJsonObject lastEntry = jsonArray.last().toObject();

    if (!lastEntry.contains("close")) {
        qDebug() << "Latest entry has no 'close' value.";
        pricePerShare = 0.0;
        return;
    }

    pricePerShare = lastEntry["close"].toDouble();

    qDebug() << "Latest closing price:" << pricePerShare;
    if (lastEntry.contains("date")) {
        qDebug() << "Date:" << lastEntry["date"].toString();
    }
}

void pages::buyButtonPushed() {
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString symbol = ui->companySymbolsCombo->currentText();
    int quantity = ui->spinBox->value();

    if (jsonArray.isEmpty()) {
        QMessageBox::warning(this, "No Data", "Please wait for stock data to load.");
        return;
    }

    extractLatestClosingPrice(jsonArray);

    if (pricePerShare <= 0.0) {
        QMessageBox::warning(this, "Invalid Price", "Could not get current stock price.");
        return;
    }

    double totalCost = quantity * pricePerShare;
    double currentCash = cashDB->getCurrentBalance();

    if (totalCost > currentCash) {
        QMessageBox::warning(this, "Insufficient Funds",
                             QString("Not enough cash. Required: Rs. %1, Available: Rs. %2")
                                 .arg(totalCost, 0, 'f', 2).arg(currentCash, 0, 'f', 2));
        return;
    }

    qDebug() << "Buying" << quantity << "shares at Rs." << pricePerShare << "each";

    if (portfolioDB->insertOrUpdateEntry(symbol, quantity, pricePerShare)) {
        transactionDB->insertEntry(currentTime, "BUY", symbol, quantity, pricePerShare);

        cashDB->insertTransaction(currentTime, "Withdraw", totalCost);

        loadPortfolioTable();
        updatePortfolioSummary();
        updateCashUI();
        loadHistoryTable();

        QMessageBox::information(this, "Purchase Successful",
                                 QString("Bought %1 shares of %2 at Rs. %3 each\nTotal: Rs. %4")
                                     .arg(quantity).arg(symbol).arg(pricePerShare, 0, 'f', 2).arg(totalCost, 0, 'f', 2));
    }
}
void pages::sellButtonPushed() {
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString symbol = ui->companySymbolsCombo->currentText();
    int quantity = ui->spinBox->value();

    if (jsonArray.isEmpty()) {
        QMessageBox::warning(this, "No Data", "Please wait for stock data to load.");
        return;
    }

    extractLatestClosingPrice(jsonArray);

    if (pricePerShare <= 0.0) {
        QMessageBox::warning(this, "Invalid Price", "Could not get current stock price.");
        return;
    }

    double totalValue = quantity * pricePerShare;

    qDebug() << "Selling" << quantity << "shares at Rs." << pricePerShare << "each";

    if (!portfolioDB->insertOrUpdateEntry(symbol, -quantity, pricePerShare)) {
        QMessageBox::warning(this, "Sell Error", "You cannot sell more shares than you own.");
        return;
    }

    transactionDB->insertEntry(currentTime, "SELL", symbol, quantity, pricePerShare);
    cashDB->insertTransaction(currentTime, "Deposit", totalValue);

    loadPortfolioTable();
    updatePortfolioSummary();
    updateCashUI();
    loadHistoryTable();

    QMessageBox::information(this, "Sale Successful",
                             QString("Sold %1 shares of %2 at Rs. %3 each\nTotal received: Rs. %4")
                                 .arg(quantity).arg(symbol).arg(pricePerShare, 0, 'f', 2).arg(totalValue, 0, 'f', 2));
}


