#include "authenticator.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>

Authenticator::Authenticator() {
    // Assumes loginDB already initialized the database elsewhere
}

bool Authenticator::authenticate(const QString &username, const QString &password) {
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    if (!db.isOpen()) {
        qDebug() << "Database not open in Authenticator.";
        return false;
    }

    QSqlQuery query(db);

    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();

        QByteArray inputHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
        if (storedHash == inputHash) {
            qDebug() << "Authentication successful";
            return true;
        } else {
            qDebug() << "Incorrect password";
            return false;
        }
    } else {
        qDebug() << "Username not found";
        return false;
    }
}
