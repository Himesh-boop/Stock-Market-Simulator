#include "transactiondb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>
#include <QStandardPaths>
#include "transactiondb.h"
#include <QDir>

TransactionDB::TransactionDB() {
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug() << "SQLite driver not available!";
        return;
    }

    if (QSqlDatabase::contains("TransactionConnection")) {
        db = QSqlDatabase::database("TransactionConnection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "TransactionConnection");
        QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QDir dir;
        if (!dir.exists(dbPath)) {
            dir.mkpath(dbPath);
        }

        db.setDatabaseName(dbPath + "/transactions.db");

        if (!db.open()) {
            qDebug() << "Failed to open transaction database:" << db.lastError().text();
            return;
        }
    }

    if (!db.isOpen()) {
        qDebug() << "Transaction DB is not open!";
        return;
    }

    QSqlQuery query(db);
    bool success = query.exec("CREATE TABLE IF NOT EXISTS transactions ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "date TEXT, "
                              "type TEXT, "
                              "symbol TEXT, "
                              "quantity INTEGER, "
                              "price REAL, "
                              "total_amount REAL)");
    if (!success) {
        qDebug() << "Error creating transaction table:" << query.lastError().text();
    } else {
        qDebug() << "Transaction table created!";
    }
}

bool TransactionDB::insertEntry(const QString date, const QString type, const QString symbol, int quantity, double price) {
    QSqlQuery query(db);

    double totalValue = quantity * price;

    query.prepare("INSERT INTO transactions (date, type, symbol, quantity, price, total_amount) "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(date);
    query.addBindValue(type);
    query.addBindValue(symbol);
    query.addBindValue(quantity);
    query.addBindValue(price);
    query.addBindValue(totalValue);

    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    } else{
        qDebug() << "Transaction Done!";
    }

    return true;
}
