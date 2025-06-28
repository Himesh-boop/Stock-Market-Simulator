#include "logindb.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include "pages/ui_signuppage.h"   // make ts sign up page

loginDB::loginDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");

    if(!db.open()){
        qDebug() << "Coudn't open the database";
        qDebug() << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)");

    if(!query.exec()){
        qDebug() << "Error creating user table";
        qDebug() << db.lastError().text();
    }
    query.prepare("INSERT INTO users (usename, password) VALUES (:username, :password)");
    query.bindValue(":username", "Himesh");
    query.bindValue(":password", "password123");
}
