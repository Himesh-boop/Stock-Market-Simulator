#ifndef TRANSACTIONDB_H
#define TRANSACTIONDB_H

#include <QString>
#include <QSqlDatabase>

class TransactionDB
{
public:
    TransactionDB();
    bool insertEntry(const QString date, const QString type, const QString symbol, int quantity, double price);
private:
    QSqlDatabase db;
};

#endif // TRANSACTIONDB_H
