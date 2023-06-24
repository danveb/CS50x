-- Write a SQL query that returns the average energy of songs that are by Drake.
-- Your query should output a table with a single column and a single row containing the average energy.
-- You should not make any assumptions about what Drake’s artist_id is.

-- #1 () -> select id from "artists" table where name is 'Drake'
-- #2 -> select AVG(energy) from "songs" table where artist_id is #1 query
SELECT AVG(energy) FROM songs WHERE artist_id LIKE (SELECT id FROM artists WHERE name = 'Drake');

-- +-------------+
-- | AVG(energy) |
-- +-------------+
-- | 0.599       |
-- +-------------+