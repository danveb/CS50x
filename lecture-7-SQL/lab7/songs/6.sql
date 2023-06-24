-- Write a SQL query that lists the names of songs that are by Post Malone.
-- Your query should output a table with a single column for the name of each song.
-- You should not make any assumptions about what Post Malone’s artist_id is.

------------------------------------- SIMPLE QUERY -------------------------------------
-- #1 perform a check on post malone
-- SELECT * FROM artists WHERE name = 'Post Malone';

-- +----+-------------+
-- | id |    name     |
-- +----+-------------+
-- | 54 | Post Malone |
-- +----+-------------+

-- #2 perform a check on name of songs where artist_id is 54
-- SELECT name FROM songs WHERE artist_id = 54;

-- +------------------------------+
-- |             name             |
-- +------------------------------+
-- | rockstar (feat. 21 Savage)   |
-- | Psycho (feat. Ty Dolla $ign) |
-- | Better Now                   |
-- | I Fall Apart                 |
-- | Candy Paint                  |
-- | Congratulations              |
-- +------------------------------+

------------------------------------- NESTED QUERY -------------------------------------
-- #1 () -> select id from "artists" table where name is 'Post Malone'
-- #2 -> select name from "songs" table where artist_id is #1 query
SELECT name FROM songs WHERE artist_id LIKE (SELECT id FROM artists WHERE name = 'Post Malone');

-- +------------------------------+
-- |             name             |
-- +------------------------------+
-- | rockstar (feat. 21 Savage)   |
-- | Psycho (feat. Ty Dolla $ign) |
-- | Better Now                   |
-- | I Fall Apart                 |
-- | Candy Paint                  |
-- | Congratulations              |
-- +------------------------------+