CREATE TABLE table_name;

# create a new database with sqlite3 and create table "favorites"
# sqlite3 favorites.db
# sqlite> .mode csv
# sqlite> .import favorites.csv name_of_table
# sqlite> .schema

SELECT columns FROM table_name;

# sqlite> SELECT * FROM favorites;
"10/24/2022 8:33:26",C,Credit
"10/24/2022 10:32;26",Python,Runoff
"10/24/2022 11:10;47",Python,Mario
"10/24/2022 11:22;35",Python,Scratch
"10/24/2022 11:39:06",Python,Readability

# run sqlite3 on "favorites" table and SELECT * FROM favorites;
# sqlite3 favorites
# sqlite> SELECT * FROM favorites;
+---------------------+----------+-------------+
|      Timestamp      | language |   problem   |
+---------------------+----------+-------------+
| 10/24/2022 8:33:26  | C        | Credit      |
| 10/24/2022 10:32;26 | Python   | Runoff      |
| 10/24/2022 11:10;47 | Python   | Mario       |
| 10/24/2022 11:22;35 | Python   | Scratch     |
| 10/24/2022 11:39:06 | Python   | Readability |
+---------------------+----------+-------------+

# select only language column from "favorites" table
# sqlite> SELECT language FROM favorites;
+----------+
| language |
+----------+
| C        |
| Python   |
| Python   |
| Python   |
| Python   |
+----------+

# Functions in SQL
# AVG
# COUNT
# DISTINCT
# LOWER
# MAX
# MIN
# UPPER
# ...

# select the count of the rows from "favorites" table
# sqlite> SELECT COUNT(*) FROM favorites;
+----------+
| COUNT(*) |
+----------+
| 5        |
+----------+

# select only the distinct languages from "favorites" table
# sqlite> SELECT DISTINCT(language) FROM favorites;
+----------+
| language |
+----------+
| C        |
| Python   |
+----------+

# select the count of distinct languages from "favorites" table
# sqlite> SELECT COUNT(DISTINCT(language)) FROM favorites;
+---------------------------+
| COUNT(DISTINCT(language)) |
+---------------------------+
| 2                         |
+---------------------------+

# We can add an "ALIAS" for a table name when outputting
# sqlite> SELECT COUNT(DISTINCT(language)) AS language_count FROM favorites;
+----------------+
| language_count |
+----------------+
| 2              |
+----------------+

# Other KEYWORDS in SQL
# WHERE (filter data)
# LIKE (alternative to =)
# ORDER BY
# LIMIT
# GROUP BY

# count all rows from "favorites" table where "language" is "C"
# sqlite> SELECT COUNT(*) FROM favorites WHERE language = 'C';
+----------+
| COUNT(*) |
+----------+
| 1        |
+----------+

# count all rows from "favorites" table where "language" is "C"
# sqlite> SELECT COUNT(*) as c_count FROM favorites WHERE language = 'C';
+---------+
| c_count |
+---------+
| 1       |
+---------+

# count all rows as python_count from "favorites" table where "language" is "python"
# sqlite> SELECT COUNT(*) as python_count FROM favorites WHERE language = 'Python';
+--------------+
| python_count |
+--------------+
| 4            |
+--------------+

# how many people liked "Python" and "Mario" problem specifically?
# sqlite> SELECT COUNT(*) as python_and_mario_likes FROM favorites WHERE language = 'Python' AND problem = 'Mario';
+------------------------+
| python_and_mario_likes |
+------------------------+
| 1                      |
+------------------------+

# sqlite> SELECT language, COUNT(*) FROM favorites GROUP BY language;
+----------+----------+
| language | COUNT(*) |
+----------+----------+
| C        | 1        |
| Python   | 4        |
+----------+----------+

# sqlite> SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) ASC;
+----------+----------+
| language | COUNT(*) |
+----------+----------+
| C        | 1        |
| Python   | 4        |
+----------+----------+

# sqlite> SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC;
+----------+----------+
| language | COUNT(*) |
+----------+----------+
| Python   | 4        |
| C        | 1        |
+----------+----------+

# find most popular language (descending order)
# sqlite> SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC LIMIT 1;
+----------+----------+
| language | COUNT(*) |
+----------+----------+
| Python   | 4        |
+----------+----------+

INSERT INTO table_name (columns...) VALUES (values of each column...);

# sqlite> SELECT DISTINCT(language) FROM favorites;
+----------+
| language |
+----------+
| C        |
| Python   |
+----------+

# insert into "favorites" table (language, problem columns) with values ('SQL', 'Fiftyvile')
# sqlite> INSERT INTO favorites (language, problem) VALUES ('SQL', 'Fiftyville');
# sqlite> SELECT DISTINCT(language) FROM favorites;
+----------+
| language |
+----------+
| C        |
| Python   |
| SQL      |
+----------+

# sqlite> SELECT * FROM favorites WHERE language = 'SQL';
+-----------+----------+------------+
| Timestamp | language |  problem   |
+-----------+----------+------------+
| NULL      | SQL      | Fiftyville |
+-----------+----------+------------+

UPDATE table_name SET column_name = value WHERE condition;

# sqlite> UPDATE favorites SET language = 'C++' WHERE language = 'SQL';
# sqlite> SELECT * FROM favorites WHERE language = 'C++';
+-----------+----------+------------+
| Timestamp | language |  problem   |
+-----------+----------+------------+
| NULL      | C++      | Fiftyville |
+-----------+----------+------------+

DELETE FROM table_name WHERE condition;

# sqlite> DELETE FROM favorites WHERE problem = 'Fiftyville';

