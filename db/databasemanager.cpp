#include "databasemanager.h"

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager()
{
    initializeDatabase();
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

DatabaseManager* DatabaseManager::getInstance()
{
    if (instance == nullptr) {
        instance = new DatabaseManager();
    }
    return instance;
}

bool DatabaseManager::initializeDatabase()
{
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dbPath);

    db = QSqlDatabase::addDatabase("QSQLITE", "LoginConnection");
    db.setDatabaseName(dbPath + "/login.db");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    // Create users table if it doesn't exist
    QSqlQuery query(db);
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "username TEXT UNIQUE NOT NULL, "
                              "email TEXT UNIQUE NOT NULL, "
                              "password TEXT NOT NULL, "
                              "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)");

    if (!success) {
        qDebug() << "Failed to create users table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Database initialized successfully";
    return true;
}

bool DatabaseManager::isConnected()
{
    return db.isOpen() && db.isValid();
}

QString DatabaseManager::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool DatabaseManager::insertUser(const QString &username, const QString &email, const QString &password)
{
    if (!isConnected()) {
        qDebug() << "Database not connected";
        return false;
    }

    // Check if username already exists
    if (userExists(username)) {
        qDebug() << "Username already exists:" << username;
        return false;
    }

    // Check if email already exists
    if (emailExists(email)) {
        qDebug() << "Email already exists:" << email;
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username, email, password) VALUES (?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(email);
    query.addBindValue(hashPassword(password));

    if (!query.exec()) {
        qDebug() << "Failed to insert user:" << query.lastError().text();
        return false;
    }

    qDebug() << "User created successfully:" << username;
    return true;
}

bool DatabaseManager::authenticateUser(const QString &username, const QString &password)
{
    if (!isConnected()) {
        qDebug() << "Database not connected";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Authentication query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        QString inputHash = hashPassword(password);

        bool isValid = (storedHash == inputHash);
        qDebug() << "Authentication result for" << username << ":" << isValid;
        return isValid;
    }

    qDebug() << "User not found:" << username;
    return false;
}

bool DatabaseManager::userExists(const QString &username)
{
    if (!isConnected()) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool DatabaseManager::emailExists(const QString &email)
{
    if (!isConnected()) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE email = ?");
    query.addBindValue(email);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

QSqlDatabase DatabaseManager::getDatabase()
{
    return db;
}
