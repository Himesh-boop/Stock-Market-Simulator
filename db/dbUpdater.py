import sqlite3
import sys

def check_user_exists(cursor):
    cursor.execute("SELECT username FROM users")
    usernames = cursor.fetchall()

    if sys.argv[1] in usernames:
        cursor.execute("SELECT password FROM users WHERE username = ?", (sys.argv[1],))
        password = cursor.fetchone()
        if password == sys.argv[2]:
            return True
        else:
            return False
    else:
        return False
        

def main():
    connection = sqlite3.connect('stock_market.db')
    cursor = connection.cursor()

    # commands
    command1 = """CREATE TABLE IF NOT EXISTS
    users (user_id INTEGER PRIMARY KEY AUTOINCREMENT, 
    username TEXT PRIMARY KEY, 
    password TEXT NOT NULL,)"""
    
    cursor.execute(command1)

    command2 = """CREATE TABLE IF NOT EXISTS
    stocks (portfolio_id INTEGER PRIMARY KEY AUTOINCREMENT, 
    user_id INTEGER PRIMARY KEY AUTOINCREMENT,  
    symbol TEXT PRIMARY KEY, 
    company TEXT NOT NULL,
    price_per_share REAL NOT NULL, 
    quantity INTEGER NOT NULL, 
    curernt_value REAL NOT NULL, 
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE
    )"""

    cursor.execute(command2)

    check = check_user_exists(cursor)

    if not check:
        cursor.execute("INSERT INTO users (username, password) VALUES (?, ?)", (sys.argv[1], sys.argv[2]))
    
