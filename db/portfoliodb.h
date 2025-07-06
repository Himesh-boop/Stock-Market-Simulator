#ifndef PORTFOLIODB_H
#define PORTFOLIODB_H

#include <QSqlDatabase>
#include <QString>

class PortfolioDB {
public:
    PortfolioDB();
    bool insertEntry(const QString &symbol, const QString &name, int quantity, double currentPrice);
    // Additional methods like update, delete, fetch could be added later
private:
    QSqlDatabase db;
};

#endif // PORTFOLIODB_H
