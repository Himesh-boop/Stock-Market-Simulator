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
}

bool PortfolioDB::insertOrUpdateEntry(const QString &symbol, int quantity, double currentPrice) {
    QSqlQuery query(db);

    query.prepare("SELECT quantity FROM portfolio WHERE symbol = :symbol");
    query.bindValue(":symbol", symbol);

    if (!query.exec()) {
        qDebug() << "Error checking for existing symbol:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int currentQuantity = query.value(0).toInt();
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
            double totalValue = newQuantity * currentPrice;

            query.prepare("UPDATE portfolio SET "
                          "quantity = :quantity, "
                          "current_price = :current_price, "
                          "total_value = :total_value "
                          "WHERE symbol = :symbol");
            query.bindValue(":quantity", newQuantity);
            query.bindValue(":current_price", currentPrice);
            query.bindValue(":total_value", totalValue);
            query.bindValue(":symbol", symbol);

            if (!query.exec()) {
                qDebug() << "Update failed:" << query.lastError().text();
                return false;
            }
        }
    } else {
        if (quantity <= 0) {
            qDebug() << "Cannot insert zero or negative quantity for a new symbol.";
            return false;
        }

        double totalValue = quantity * currentPrice;

        query.prepare("INSERT INTO portfolio (symbol, quantity, current_price, total_value) "
                      "VALUES (:symbol, :quantity, :current_price, :total_value)");
        query.bindValue(":symbol", symbol);
        query.bindValue(":quantity", quantity);
        query.bindValue(":current_price", currentPrice);
        query.bindValue(":total_value", totalValue);

        if (!query.exec()) {
            qDebug() << "Insert failed:" << query.lastError().text();
            return false;
        }
    }

    return true;
}
