#include "cashdb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

CashDB::CashDB() {
    QSqlDatabase db = QSqlDatabase::database("main_connection");

    if (!db.open()) {
        qDebug() << "Failed to open cash database:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS cash_transactions ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "date TEXT NOT NULL, "
                  "type TEXT CHECK(type IN ('Deposit', 'Withdraw')) NOT NULL, "
                  "amount REAL NOT NULL)");

    if (!query.exec()) {
        qDebug() << "Failed to create cash_transactions table:" << query.lastError().text();
    } else {
        qDebug() << "Cash transactions table ready.";
    }
}

bool CashDB::insertTransaction(const QString &date, const QString &type, double amount) {
    QSqlQuery query(db);

    query.prepare("INSERT INTO cash_transactions (date, type, amount) "
                  "VALUES (:date, :type, :amount)");
    query.bindValue(":date", date);
    query.bindValue(":type", type);
    query.bindValue(":amount", amount);

    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }

    return true;
}
