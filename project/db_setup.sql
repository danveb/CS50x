-- DB: coinist

-- initialize todoist db with sqlite3
-- $ sqlite3 coinist.db

-- any errors or want to delete a SQL table?
DROP TABLE x...;

-- create table users, transactions, etc.
CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 1000000.00);
CREATE UNIQUE INDEX username ON users (username);
CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, user_id INTEGER NOT NULL, symbol TEXT NOT NULL, shares INTEGER NOT NULL, price REAL NOT NULL, icon TEXT NOT NULL, date TIMESTAMP);

-- .schema
CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 1000000.00);
CREATE TABLE sqlite_sequence(name,seq);
CREATE UNIQUE INDEX username ON users (username);
CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, user_id INTEGER NOT NULL, symbol TEXT NOT NULL, shares INTEGER NOT NULL, price REAL NOT NULL, icon TEXT NOT NULL, date TIMESTAMP);

-- insert a sample user to db
INSERT INTO users (username, hash) VALUES ('peach', 'peach');

-- check sample user on db
SELECT * FROM users;
+----+----------+--------------------------------------------------------------------------------------------------------+---------+
| id | username |                                                  hash                                                  |  cash   |
+----+----------+--------------------------------------------------------------------------------------------------------+---------+
| 1  | peach    | pbkdf2:sha256:600000$t1afv87POtzTVGxV$807a64716703ad6dd441f19b64fd11c78e5fc21041ca43d19b5556aade9fc16f | 1000000 |
+----+----------+--------------------------------------------------------------------------------------------------------+---------+

-- delete a user on db
DELETE FROM users WHERE id = 1;

-- check transactions
SELECT * FROM transactions;
+----+---------+--------+--------+------------------+---------------------+
| id | user_id | symbol | shares |      price       |        date         |
+----+---------+--------+--------+------------------+---------------------+
| 1  | 1       | BTC    | 4      | 31115.1702904226 | 2023-07-03 15:44:27 |
+----+---------+--------+--------+------------------+---------------------+

