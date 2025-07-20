#ifndef CASHDB_H
#define CASHDB_H

#include <QSqlDatabase>
#include <QString>

class CashDB {
public:
    CashDB();
    bool insertTransaction(const QString &date, const QString &type, double amount);
    double getCurrentBalance();
   
private:
    QSqlDatabase db;
};

#endif // CASHDB_H
