-- Write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.

SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = 'Johnny Depp' AND movies.title IN(
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = 'Helena Bonham Carter');

-- +------------------------------------------------+
-- |                     title                      |
-- +------------------------------------------------+
-- | Corpse Bride                                   |
-- | Charlie and the Chocolate Factory              |
-- | Sweeney Todd: The Demon Barber of Fleet Street |
-- | Alice in Wonderland                            |
-- | Dark Shadows                                   |
-- | Johnny's Inferno                               |
-- | Alice Through the Looking Glass                |
-- +------------------------------------------------+