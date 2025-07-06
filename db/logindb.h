#ifndef LOGINDB_H
#define LOGINDB_H

#include <QString>
#include <QSqlDatabase>

class loginDB {
public:
    loginDB();
    bool insertUser(const QString &username, const QString &email, const QString &password);
    QString hashPassword(const QString &password);

private:
    QSqlDatabase db;
};

#endif // LOGINDB_H
