#include "portfoliodb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

PortfolioDB::PortfolioDB() {
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug() << "SQLite driver not available!";
        return;
    }

    if (QSqlDatabase::contains("main_connection")) {
        db = QSqlDatabase::database("main_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
        QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QDir dir;
        if (!dir.exists(dbPath)) {
            dir.mkpath(dbPath);
        }
        db.setDatabaseName(dbPath + "/portfolio.db");
    }

    if (!db.open()) {
        qDebug() << "Failed to open portfolio database:" << db.lastError().text();
        return;
    }

    // Create table (initially without average_price)
    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS portfolio ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "symbol TEXT UNIQUE NOT NULL, "
                  "name TEXT, "
                  "quantity INTEGER, "
                  "current_price REAL, "
                  "total_value REAL)");

    if (!query.exec()) {
        qDebug() << "Failed to create portfolio table:" << query.lastError().text();
    }

    // 🆕 Add average_price column if missing
    QSqlQuery check(db);
    check.exec("PRAGMA table_info(portfolio)");
    bool hasAveragePrice = false;

    while (check.next()) {
        if (check.value(1).toString() == "average_price") {
            hasAveragePrice = true;
            break;
        }
    }

    if (!hasAveragePrice) {
        QSqlQuery alterQuery(db);
        if (!alterQuery.exec("ALTER TABLE portfolio ADD COLUMN average_price REAL")) {
            qDebug() << "Failed to add average_price column:" << alterQuery.lastError().text();
        } else {
            qDebug() << "average_price column added successfully.";
        }
    }
}

bool PortfolioDB::insertOrUpdateEntry(const QString &symbol, int quantity, double currentPrice) {
    QSqlQuery query(db);

    query.prepare("SELECT quantity, average_price FROM portfolio WHERE symbol = :symbol");
    query.bindValue(":symbol", symbol);

    if (!query.exec()) {
        qDebug() << "Error checking for existing symbol:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int currentQuantity = query.value(0).toInt();
        double currentAvgPrice = query.value(1).toDouble();
        int newQuantity = currentQuantity + quantity;

        if (newQuantity < 0) {
            qDebug() << "Sell quantity exceeds owned quantity!";
            return false;
        }

        if (newQuantity == 0) {
            QSqlQuery deleteQuery(db);
            deleteQuery.prepare("DELETE FROM portfolio WHERE symbol = :symbol");
            deleteQuery.bindValue(":symbol", symbol);
            if (!deleteQuery.exec()) {
                qDebug() << "Failed to delete entry:" << deleteQuery.lastError().text();
                return false;
            }
        } else {
            double newAvgPrice = currentAvgPrice;

            if (quantity > 0) {
                // Recalculate weighted average price for new buy
                double totalCost = (currentAvgPrice * currentQuantity) + (currentPrice * quantity);
                newAvgPrice = totalCost / newQuantity;
            }

            double totalValue = newQuantity * currentPrice;

            QSqlQuery updateQuery(db);
            updateQuery.prepare("UPDATE portfolio SET "
                                "quantity = :quantity, "
                                "current_price = :current_price, "
                                "total_value = :total_value, "
                                "average_price = :average_price "
                                "WHERE symbol = :symbol");
            updateQuery.bindValue(":quantity", newQuantity);
            updateQuery.bindValue(":current_price", currentPrice);
            updateQuery.bindValue(":total_value", totalValue);
            updateQuery.bindValue(":average_price", newAvgPrice);
            updateQuery.bindValue(":symbol", symbol);

            if (!updateQuery.exec()) {
                qDebug() << "Update failed:" << updateQuery.lastError().text();
                return false;
            }
        }
    } else {
        if (quantity <= 0) {
            qDebug() << "Cannot insert zero or negative quantity for a new symbol.";
            return false;
        }

        double totalValue = quantity * currentPrice;

        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT INTO portfolio (symbol, quantity, current_price, total_value, average_price) "
                            "VALUES (:symbol, :quantity, :current_price, :total_value, :average_price)");
        insertQuery.bindValue(":symbol", symbol);
        insertQuery.bindValue(":quantity", quantity);
        insertQuery.bindValue(":current_price", currentPrice);
        insertQuery.bindValue(":total_value", totalValue);
        insertQuery.bindValue(":average_price", currentPrice);

        if (!insertQuery.exec()) {
            qDebug() << "Insert failed:" << insertQuery.lastError().text();
            return false;
        }
    }

    return true;
}
