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


void pages::fetchStockData(const QString& symbol) {
    QProcess* process = new QProcess(this);

    connect(process, &QProcess::finished, this, [this, process]() {
        QByteArray output = process->readAllStandardOutput();
        QString jsonString(output);

        // Debug print the raw output
        qDebug() << "Python script output:" << jsonString;

        // Parse JSON data
        QJsonDocument jsonDoc = QJsonDocument::fromJson(output);
        if (jsonDoc.isNull() || !jsonDoc.isArray()) {
            qDebug() << "Failed to parse JSON data";
            process->deleteLater();
            return;
        }

        QJsonArray jsonArray = jsonDoc.array();
        qDebug() << "Received data points:" << jsonArray.size();

        // Example: print first data point (if any)
        if (!jsonArray.isEmpty()) {
            QJsonObject firstRecord = jsonArray.first().toObject();
            qDebug() << "First record:" << firstRecord;
        }

        process->deleteLater();

        // TODO: Here, you can process the jsonArray and update your UI
    });

    connect(process, &QProcess::errorOccurred, this, [process](QProcess::ProcessError error) {
        qDebug() << "Process error:" << error;
        process->deleteLater();
    });
    
    QString pythonExecutable = "python";
    QString scriptPath = "C:/Stock Market Simulator/Stock-Market-Simulator/Models/candlestickChart.py"; // **Update this path**

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
{
    ui->setupUi(this);

    // Connect all buttons to the toggle slot
    connect(ui->Portfolio, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Cash, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Investment, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Ledger, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->News, &QPushButton::toggled, this, &pages::onButtonToggled);

    // Set Portfolio as initially selected
    ui->Portfolio->setChecked(true);
    // Set initial page to match the initially selected button
    ui->stackedWidget->setCurrentIndex(0); // Portfolio page
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
        fetchStockData("NABIL");
    } else if (button == ui->Ledger) {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (button == ui->News) {
        ui->stackedWidget->setCurrentIndex(4);
    }

    // Delete any existing animation
    if (currentAnimation) {
        currentAnimation->stop();
        delete currentAnimation;
    }

    // Original position
    QRect origGeometry = button->geometry();

    // Create new animation
    currentAnimation = new QPropertyAnimation(button, "geometry");
    currentAnimation->setDuration(150); // 150ms animation
    currentAnimation->setStartValue(origGeometry);

    // Create target geometry (shifted 20px to the right)
    QRect targetGeometry = origGeometry;
    targetGeometry.setLeft(origGeometry.left() + 20);
    targetGeometry.setRight(origGeometry.right() + 20);

    currentAnimation->setEndValue(targetGeometry);
    currentAnimation->setEasingCurve(QEasingCurve::OutCubic);
    currentAnimation->start();

    // If there was a previously checked button, animate it back
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

        // Auto-delete when done
        reverseAnim->start(QAbstractAnimation::DeleteWhenStopped);
    }

    lastCheckedButton = button;
}
