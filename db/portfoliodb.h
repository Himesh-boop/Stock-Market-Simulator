#ifndef PORTFOLIODB_H
#define PORTFOLIODB_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQueryModel>

class PortfolioDB {
public:
    PortfolioDB();
    bool insertOrUpdateEntry(const QString &symbol, int quantity, double currentPrice);
    
private:
    QSqlDatabase db;
};

#endif // PORTFOLIODB_H
