-- Write a SQL query to determine the average rating of all movies released in 2012.
-- Your query should output a table with a single column and a single row (not counting the header) containing the average rating.

-- AVG(rating)
-- JOIN movies ON movie.id = ratings.movie_id
-- WHERE movies from year 2012

SELECT AVG(rating) FROM ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE year = 2012;

-- +------------------+
-- |   AVG(rating)    |
-- +------------------+
-- | 6.29787154592979 |
-- +------------------+