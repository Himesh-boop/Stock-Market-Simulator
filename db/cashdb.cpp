#include "cashdb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>

CashDB::CashDB() {
    if (QSqlDatabase::contains("cashConnection")) {
        db = QSqlDatabase::database("cashConnection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "cashConnection");
        QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QDir().mkpath(dbPath);
        db.setDatabaseName(dbPath + "/cash.db");
    }

    if (!db.open()) {
        qDebug() << "Failed to open cash database:" << db.lastError().text();
        return;
    }

    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM cash_transactions");

    if (checkQuery.exec() && checkQuery.next()) {
        int count = checkQuery.value(0).toInt();
        if (count == 0) {
            insertTransaction(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"), "Deposit", 500000.0);
        }
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

double CashDB::getCurrentBalance() {
    QSqlQuery query(db);
    query.prepare("SELECT type, amount FROM cash_transactions");

    double balance = 0;
    if (query.exec()) {
        while (query.next()) {
            QString type = query.value(0).toString();
            double amount = query.value(1).toDouble();

            if (type == "Deposit") balance += amount;
            else if (type == "Withdraw") balance -= amount;
        }
    }
    return balance;
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
