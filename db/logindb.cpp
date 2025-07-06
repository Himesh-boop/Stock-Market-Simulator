#include "db/logindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>
#include <QStandardPaths>
#include <QDir>

loginDB::loginDB() {
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dbPath);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath + "/login.db");

    if (!db.open()) {
        qDebug() << "Couldn't open the database";
        qDebug() << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS users ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "username TEXT UNIQUE, "
                  "email TEXT, "
                  "password TEXT)");

    if (!query.exec()) {
        qDebug() << "Error creating user table:" << query.lastError().text();
    }
}

QString loginDB::hashPassword(const QString &password){
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}

bool loginDB::insertUser(const QString &username, const QString &email, const QString &password) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, email, password) "
                  "VALUES (:username, :email, :password)");
    query.bindValue(":username", username);
    query.bindValue(":email", email);

    QString hashedPassword = hashPassword(password);
    query.bindValue(":password", hashedPassword);

    qDebug() << "loginDB was called";

    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }
    return true;
}
