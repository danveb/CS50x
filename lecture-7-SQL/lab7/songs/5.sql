-- Write a SQL query that returns the average energy of all the songs.
-- Your query should output a table with a single column and a single row containing the average energy.

-- use AVG(energy) function keyword
SELECT AVG(energy) FROM songs;

-- +-------------+
-- | AVG(energy) |
-- +-------------+
-- | 0.65906     |
-- +-------------+