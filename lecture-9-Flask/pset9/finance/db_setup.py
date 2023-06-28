# execute finance.db
# $ sqlite3 finance.db
# sqlite> .schema

CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 10000.00);
CREATE TABLE sqlite_sequence(name,seq);
CREATE UNIQUE INDEX username ON users (username);

# grab all users from users table
SELECT * FROM users;

+----+----------+--------------------------------------------------------------------------------------------------------+-------+
| id | username |                                                  hash                                                  | cash  |
+----+----------+--------------------------------------------------------------------------------------------------------+-------+
| 1  | peach    | pbkdf2:sha256:600000$ZOE48auGGU431QFz$47750c5ea8e32b3e540f3835e57a088e0e4bcb0c016dbedd7e84dca2a7b3dc4e | 10000 |
+----+----------+--------------------------------------------------------------------------------------------------------+-------+

# build a "transactions" table on finance.db
CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, user_id INTEGER NOT NULL, symbol TEXT NOT NULL, shares INTEGER NOT NULL, price REAL NOT NULL, date TIMESTAMP);

# add transactions
INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (user_id, stock_symbol, stock_shares, stock_price, date);

# grab all transactions
SELECT * FROM transactions;

# +----+---------+--------+--------+--------+---------------------+
# | id | user_id | symbol | shares | price  |        date         |
# +----+---------+--------+--------+--------+---------------------+
# | 1  | 4       | TSLA   | 1      | 241.05 | 2023-06-26 21:02:48 |
# | 2  | 4       | TSLA   | 5      | 248.38 | 2023-06-27 10:46:37 |
# +----+---------+--------+--------+--------+---------------------+

# check available cash
SELECT cash FROM users WHERE id = 4;
# +--------+
# |  cash  |
# +--------+
# | 6829.7 |
# +--------+

