#include "portfoliodb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PortfolioDB::PortfolioDB() {
    QSqlDatabase db = QSqlDatabase::database("main_connection");

    if (!db.open()) {
        qDebug() << "Failed to open portfolio database:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS portfolio ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "symbol TEXT NOT NULL, "
                  "name TEXT, "
                  "quantity INTEGER, "
                  "current_price REAL, "
                  "total_value REAL)");

    if (!query.exec()) {
        qDebug() << "Failed to create portfolio table:" << query.lastError().text();
    } else {
        qDebug() << "Portfolio table ready.";
    }
}

bool PortfolioDB::insertEntry(const QString &symbol, const QString &name, int quantity, double currentPrice) {
    QSqlQuery query(db);

    double totalValue = quantity * currentPrice;

    query.prepare("INSERT INTO portfolio (symbol, name, quantity, current_price, total_value) "
                  "VALUES (:symbol, :name, :quantity, :current_price, :total_value)");
    query.bindValue(":symbol", symbol);
    query.bindValue(":name", name);
    query.bindValue(":quantity", quantity);
    query.bindValue(":current_price", currentPrice);
    query.bindValue(":total_value", totalValue);

    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }

    return true;
}
