#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QCryptographicHash>

class DatabaseManager
{
private:
    static DatabaseManager* instance;
    QSqlDatabase db;

    DatabaseManager(); // Private constructor for singleton

public:
    static DatabaseManager* getInstance();
    ~DatabaseManager();

    bool initializeDatabase();
    bool isConnected();
    QString hashPassword(const QString &password);
    bool insertUser(const QString &username, const QString &email, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    bool userExists(const QString &username);
    bool emailExists(const QString &email);
    QSqlDatabase getDatabase();

    // Delete copy constructor and assignment operator
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
};

#endif // DATABASEMANAGER_H
