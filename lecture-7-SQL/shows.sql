-- execute shows.db
$ sqlite3 shows.db

-- run .schema command on shows.db to show tables "genres", "people", "ratings", "shows", "stars", "writers"
sqlite> .schema
-- CREATE TABLE genres (
--     show_id INTEGER NOT NULL,
--     genre TEXT NOT NULL,
--     FOREIGN KEY(show_id) REFERENCES shows(id)
-- );
-- CREATE TABLE people (
--     id INTEGER,
--     name TEXT NOT NULL,
--     birth NUMERIC,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE ratings (
--     show_id INTEGER NOT NULL,
--     rating REAL NOT NULL,
--     votes INTEGER NOT NULL,
--     FOREIGN KEY(show_id) REFERENCES shows(id)
-- );
-- CREATE TABLE shows (
--     id INTEGER,
--     title TEXT NOT NULL,
--     year NUMERIC,
--     episodes INTEGER,
--     PRIMARY KEY(id)
-- );
-- CREATE TABLE stars (
--     show_id INTEGER NOT NULL,
--     person_id INTEGER NOT NULL,
--     FOREIGN KEY(show_id) REFERENCES shows(id),
--     FOREIGN KEY(person_id) REFERENCES people(id)
-- );
-- CREATE TABLE writers (
--     show_id INTEGER NOT NULL,
--     person_id INTEGER NOT NULL,
--     FOREIGN KEY(show_id) REFERENCES shows(id),
--     FOREIGN KEY(person_id) REFERENCES people(id)
-- );

-- Data Types in SQLite3 for COLUMNS
BLOB       -- binary large objects that are groups of ones and zeros
INTEGER    -- an integer
NUMERIC    -- for numbers that are formatted specially like dates
REAL       -- like a float
TEXT       -- for strings and the like

-- COLUMNS can have special constraints?
NOT NULL -- never empty
UNIQUE -- never repeated

-- Very important keywords
PRIMARY KEY(id) -- database uses "id" as special; uniquely identify data
FOREIGN KEY(person_id) REFERENCES people(id) -- person_id comes from "people" table's id

----------------------------------- QUERIES -----------------------------------

-- show me ALL the people
SELECT * FROM people;

-- show me 10 people
SELECT * FROM people LIMIT 10;
+----+---------------------+-------+
| id |        name         | birth |
+----+---------------------+-------+
| 1  | Fred Astaire        | 1899  |
| 2  | Lauren Bacall       | 1924  |
| 3  | Brigitte Bardot     | 1934  |
| 5  | Ingmar Bergman      | 1918  |
| 6  | Ingrid Bergman      | 1915  |
| 8  | Marlon Brando       | 1924  |
| 9  | Richard Burton      | 1925  |
| 12 | Bette Davis         | 1908  |
| 13 | Doris Day           | 1922  |
| 14 | Olivia de Havilland | 1916  |
+----+---------------------+-------+

SELECT * FROM stars LIMIT 10;
+---------+-----------+
| show_id | person_id |
+---------+-----------+
| 62614   | 378823    |
| 62614   | 853892    |
| 62614   | 393936    |
| 62614   | 496420    |
| 62614   | 333162    |
| 62614   | 180174    |
| 62614   | 165183    |
| 62614   | 466749    |
| 63881   | 625401    |
| 63881   | 1933      |
+---------+-----------+

----------------------------------- QUERIES -----------------------------------

SELECT * FROM genres;
SELECT * FROM genres WHERE genre = 'Comedy' LIMIT 10;
+---------+--------+
| show_id | genre  |
+---------+--------+
| 62614   | Comedy |
| 63881   | Comedy |
| 65270   | Comedy |
| 65271   | Comedy |
| 65273   | Comedy |
| 65274   | Comedy |
| 65276   | Comedy |
| 65283   | Comedy |
| 65285   | Comedy |
| 65287   | Comedy |
+---------+--------+

----------------------------------- POWERFUL QUERIES -----------------------------------

SELECT COUNT(show_id) FROM genres WHERE genre = 'Comedy';

SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') LIMIT 10;
+-----------------------------+
|            title            |
+-----------------------------+
| Zeg 'ns Aaa                 |
| Catweazle                   |
| The Adventures of Don Quick |
| Albert and Victoria         |
| Archie's Funhouse           |
| Arnie                       |
| Barefoot in the Park        |
| Comedy Tonight              |
| The Culture Vultures        |
| Make Room for Granddaddy    |
+-----------------------------+

SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') ORDER BY title LIMIT 10;
+------------------+
|      title       |
+------------------+
| #                |
| #7DaysLater      |
| #ATown           |
| #Actress         |
| #Adulting        |
| #Adulting        |
| #AubreyGrams     |
| #Awkward Dates   |
| #AwkwardMoment   |
| #AwkwardMornings |
+------------------+

SELECT * FROM people WHERE name = 'Steve Carell';
+--------+--------------+-------+
|   id   |     name     | birth |
+--------+--------------+-------+
| 136797 | Steve Carell | 1962  |
+--------+--------------+-------+

-- get all shows where Steve Carell is in?
SELECT * FROM stars WHERE person_id = 136797;

--
SELECT title FROM shows WHERE id = 115148;

--
SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell')) ORDER BY title;
+------------------------------------+
|               title                |
+------------------------------------+
| Come to Papa                       |
| ES.TV HD                           |
| Entertainers with Byron Allen      |
| Fabrice Fabrice Interviews         |
| First Impressions with Dana Carvey |
| Hollywood Sessions                 |
| Inside Comedy                      |
| LA Times: The Envelope             |
| Mark at the Movies                 |
| Metacafe Unfiltered                |
| Over the Top                       |
| Riot                               |
| Rove LA                            |
| Some Good News                     |
| Space Force                        |
| Séries express                     |
| The Dana Carvey Show               |
| The Naked Trucker and T-Bones Show |
| The Office                         |
| Watching Ellie                     |
+------------------------------------+

----------------------------------- JOIN -----------------------------------

SELECT * FROM shows LIMIT 10;
+-------+-----------------------------+------+----------+
|  id   |            title            | year | episodes |
+-------+-----------------------------+------+----------+
| 62614 | Zeg 'ns Aaa                 | 1981 | 227      |
| 63881 | Catweazle                   | 1970 | 26       |
| 63962 | UFO                         | 1970 | 26       |
| 65269 | Ace of Wands                | 1970 | 46       |
| 65270 | The Adventures of Don Quick | 1970 | 6        |
| 65271 | Albert and Victoria         | 1970 | 12       |
| 65272 | All My Children             | 1970 | 4337     |
| 65273 | Archie's Funhouse           | 1970 | 23       |
| 65274 | Arnie                       | 1970 | 48       |
| 65276 | Barefoot in the Park        | 1970 | 12       |
+-------+-----------------------------+------+----------+
SELECT * FROM genres LIMIT 10;
+---------+-----------+
| show_id |   genre   |
+---------+-----------+
| 62614   | Comedy    |
| 63881   | Adventure |
| 63881   | Comedy    |
| 63881   | Family    |
| 63962   | Action    |
| 63962   | Sci-Fi    |
| 65269   | Family    |
| 65269   | Fantasy   |
| 65270   | Comedy    |
| 65270   | Sci-Fi    |
+---------+-----------+

-- Perform a JOIN to get a table with id, title, year, episodes, and genre columns
SELECT * FROM shows JOIN genres on shows.id = genres.show_id WHERE title = 'The Office';
+----------+------------+------+----------+----------+--------+
|    id    |   title    | year | episodes | show_id  | genre  |
+----------+------------+------+----------+----------+--------+
| 112108   | The Office | 1995 | 6        | 112108   | Comedy |
| 290978   | The Office | 2001 | 14       | 290978   | Comedy |
| 290978   | The Office | 2001 | 14       | 290978   | Drama  |
| 386676   | The Office | 2005 | 188      | 386676   | Comedy |
| 1791001  | The Office | 2010 | 30       | 1791001  | Comedy |
| 20877972 | The Office | 2022 | 20       | 20877972 | Comedy |
| 2186395  | The Office | 2012 | 8        | 2186395  | Comedy |
| 8305218  | The Office | 2019 | 28       | 8305218  | Comedy |
+----------+------------+------+----------+----------+--------+

SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE title = 'The Office';
+---------+------------+------+----------+---------+--------+--------+
|   id    |   title    | year | episodes | show_id | rating | votes  |
+---------+------------+------+----------+---------+--------+--------+
| 112108  | The Office | 1995 | 6        | 112108  | 7.5    | 45     |
| 290978  | The Office | 2001 | 14       | 290978  | 8.5    | 112944 |
| 386676  | The Office | 2005 | 188      | 386676  | 9.0    | 585206 |
| 1791001 | The Office | 2010 | 30       | 1791001 | 4.7    | 56     |
| 2186395 | The Office | 2012 | 8        | 2186395 | 6.0    | 12     |
| 8305218 | The Office | 2019 | 28       | 8305218 | 5.7    | 5718   |
+---------+------------+------+----------+---------+--------+--------+

-- explicit JOIN
SELECT title FROM people
JOIN stars ON people.id = stars.person_id
JOIN shows ON stars.show_id = shows.id
WHERE name = 'Steve Carell';
+------------------------------------+
|               title                |
+------------------------------------+
| The Dana Carvey Show               |
| Over the Top                       |
| Watching Ellie                     |
| Come to Papa                       |
| The Office                         |
| Entertainers with Byron Allen      |
| The Naked Trucker and T-Bones Show |
| Some Good News                     |
| ES.TV HD                           |
| Mark at the Movies                 |
| Inside Comedy                      |
| Rove LA                            |
| Metacafe Unfiltered                |
| Fabrice Fabrice Interviews         |
| Riot                               |
| Séries express                     |
| Hollywood Sessions                 |
| First Impressions with Dana Carvey |
| LA Times: The Envelope             |
| Space Force                        |
+------------------------------------+

-- implicit JOIN
SELECT title FROM people, stars, shows
WHERE people.id = stars.person_id
AND stars.show_id = shows.id
AND name = 'Steve Carell';
+------------------------------------+
|               title                |
+------------------------------------+
| The Dana Carvey Show               |
| Over the Top                       |
| Watching Ellie                     |
| Come to Papa                       |
| The Office                         |
| Entertainers with Byron Allen      |
| The Naked Trucker and T-Bones Show |
| Some Good News                     |
| ES.TV HD                           |
| Mark at the Movies                 |
| Inside Comedy                      |
| Rove LA                            |
| Metacafe Unfiltered                |
| Fabrice Fabrice Interviews         |
| Riot                               |
| Séries express                     |
| Hollywood Sessions                 |
| First Impressions with Dana Carvey |
| LA Times: The Envelope             |
| Space Force                        |
+------------------------------------+

SELECT * FROM people WHERE name LIKE 'Steve Car%l';
+--------+--------------+-------+
|   id   |     name     | birth |
+--------+--------------+-------+
| 136797 | Steve Carell | 1962  |
+--------+--------------+-------+

