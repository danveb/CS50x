-- Write a SQL query that lists the names of the songs that feature other artists.
-- Songs that feature other artists will include “feat.” in the name of the song.
-- Your query should output a table with a single column for the name of each song.

SELECT name FROM songs WHERE name LIKE '%feat.%';

-- +---------------------------------------------------------+
-- |                          name                           |
-- +---------------------------------------------------------+
-- | rockstar (feat. 21 Savage)                              |
-- | Psycho (feat. Ty Dolla $ign)                            |
-- | Girls Like You (feat. Cardi B)                          |
-- | Look Alive (feat. Drake)                                |
-- | These Days (feat. Jess Glynne, Macklemore & Dan Caplen) |
-- | Meant to Be (feat. Florida Georgia Line)                |
-- | Taste (feat. Offset)                                    |
-- | Solo (feat. Demi Lovato)                                |
-- | River (feat. Ed Sheeran)                                |
-- | Freaky Friday (feat. Chris Brown)                       |
-- | FEFE (feat. Nicki Minaj & Murda Beatz)                  |
-- | Body (feat. brando)                                     |
-- | Fuck Love (feat. Trippie Redd)                          |
-- | Dejala que vuelva (feat. Manuel Turizo)                 |
-- | 1, 2, 3 (feat. Jason Derulo & De La Ghetto)             |
-- | Corazon (feat. Nego do Borel)                           |
-- | I Miss You (feat. Julia Michaels)                       |
-- +---------------------------------------------------------+
