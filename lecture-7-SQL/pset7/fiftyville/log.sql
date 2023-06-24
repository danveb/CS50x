-- What we know?
-- theft took place on 7/28
-- theft took place on Humphrey St.

-- Goals?
-- who the thief is?
-- where the thief escaped to?
-- who the thief's accomplice was who helped escape town?

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- #1 search crime_scene_reports
SELECT * FROM crime_scene_reports;

-- #2 search specific report related to month 7, day 28, and street Humphrey%
SELECT * FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street LIKE 'Humphrey%';
--  potentially theft is related to id 295, where a CS50 duck was robbed at Humphrey Street bakery @ 10.15am where 3 witnesses were interviewed

-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------+
-- | id  | year | month | day |     street      |                         description                          |
-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------+
-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey |
-- |     |      |       |     |                 |  Street bakery. Interviews were conducted today with three w |
-- |     |      |       |     |                 | itnesses who were present at the time – each of their interv |
-- |     |      |       |     |                 | iew transcripts mentions the bakery.                         |
-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------+
-- | 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.           |
-- +-----+------+-------+-----+-----------------+--------------------------------------------------------------+

-- #3 check related interviews table for 3 witnesses
-- look for 7/28 and populate a list of interviewees
SELECT * FROM interviews
WHERE month = 7
AND day = 28;
-- based on the interviews conducted on 7/28 we can deduce Ruth, Eugene and Raymond are the witnesses to the theft


-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | id  |  name   | year | month | day |                          transcript                          |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 158 | Jose    | 2021 | 7     | 28  | “Ah,” said he, “I forgot that I had not seen you for some we |
-- |     |         |      |       |     | eks. It is a little souvenir from the King of Bohemia in ret |
-- |     |         |      |       |     | urn for my assistance in the case of the Irene Adler papers. |
-- |     |         |      |       |     | ”                                                            |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 159 | Eugene  | 2021 | 7     | 28  | “I suppose,” said Holmes, “that when Mr. Windibank came back |
-- |     |         |      |       |     |  from France he was very annoyed at your having gone to the  |
-- |     |         |      |       |     | ball.”                                                       |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 160 | Barbara | 2021 | 7     | 28  | “You had my note?” he asked with a deep harsh voice and a st |
-- |     |         |      |       |     | rongly marked German accent. “I told you that I would call.” |
-- |     |         |      |       |     |  He looked from one to the other of us, as if uncertain whic |
-- |     |         |      |       |     | h to address.                                                |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief ge |
-- |     |         |      |       |     | t into a car in the bakery parking lot and drive away. If yo |
-- |     |         |      |       |     | u have security footage from the bakery parking lot, you mig |
-- |     |         |      |       |     | ht want to look for cars that left the parking lot in that t |
-- |     |         |      |       |     | ime frame.                                                   |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recogniz |
-- |     |         |      |       |     | ed. Earlier this morning, before I arrived at Emma's bakery, |
-- |     |         |      |       |     |  I was walking by the ATM on Leggett Street and saw the thie |
-- |     |         |      |       |     | f there withdrawing some money.                              |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who |
-- |     |         |      |       |     |  talked to them for less than a minute. In the call, I heard |
-- |     |         |      |       |     |  the thief say that they were planning to take the earliest  |
-- |     |         |      |       |     | flight out of Fiftyville tomorrow. The thief then asked the  |
-- |     |         |      |       |     | person on the other end of the phone to purchase the flight  |
-- |     |         |      |       |     | ticket.                                                      |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 191 | Lily    | 2021 | 7     | 28  | Our neighboring courthouse has a very annoying rooster that  |
-- |     |         |      |       |     | crows loudly at 6am every day. My sons Robert and Patrick to |
-- |     |         |      |       |     | ok the rooster to a city far, far away, so it may never both |
-- |     |         |      |       |     | er us again. My sons have successfully arrived in Paris.     |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+

-- #4 investigate closely interviews from Ruth, Eugene, Raymond
SELECT * FROM interviews
WHERE month = 7
AND day = 28
AND name LIKE 'Ruth';

SELECT * FROM interviews
WHERE month = 7
AND day = 28
AND name LIKE 'Eugene';

SELECT * FROM interviews
WHERE month = 7
AND day = 28
AND name LIKE 'Raymond';

-- +-----+------+------+-------+-----+--------------------------------------------------------------+
-- | id  | name | year | month | day |                          transcript                          |
-- +-----+------+------+-------+-----+--------------------------------------------------------------+
-- | 161 | Ruth | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief ge |
-- |     |      |      |       |     | t into a car in the bakery parking lot and drive away. If yo |
-- |     |      |      |       |     | u have security footage from the bakery parking lot, you mig |
-- |     |      |      |       |     | ht want to look for cars that left the parking lot in that t |
-- |     |      |      |       |     | ime frame.                                                   |
-- +-----+------+------+-------+-----+--------------------------------------------------------------+

-- +-----+--------+------+-------+-----+--------------------------------------------------------------+
-- | id  |  name  | year | month | day |                          transcript                          |
-- +-----+--------+------+-------+-----+--------------------------------------------------------------+
-- | 159 | Eugene | 2021 | 7     | 28  | “I suppose,” said Holmes, “that when Mr. Windibank came back |
-- |     |        |      |       |     |  from France he was very annoyed at your having gone to the  |
-- |     |        |      |       |     | ball.”                                                       |
-- +-----+--------+------+-------+-----+--------------------------------------------------------------+
-- | 162 | Eugene | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recogniz |
-- |     |        |      |       |     | ed. Earlier this morning, before I arrived at Emma's bakery, |
-- |     |        |      |       |     |  I was walking by the ATM on Leggett Street and saw the thie |
-- |     |        |      |       |     | f there withdrawing some money.                              |
-- +-----+--------+------+-------+-----+--------------------------------------------------------------+

-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | id  |  name   | year | month | day |                          transcript                          |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+
-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who |
-- |     |         |      |       |     |  talked to them for less than a minute. In the call, I heard |
-- |     |         |      |       |     |  the thief say that they were planning to take the earliest  |
-- |     |         |      |       |     | flight out of Fiftyville tomorrow. The thief then asked the  |
-- |     |         |      |       |     | person on the other end of the phone to purchase the flight  |
-- |     |         |      |       |     | ticket.                                                      |
-- +-----+---------+------+-------+-----+--------------------------------------------------------------+

-- leads:
-- 1. check bakery parking lot
-- 2. check ATM on Legget St., close to "Emma's bakery", where the thief withdrew cash
-- 3. check for earliest flight on 7/29; thief asked accomplice to purchase ticket via phone

-- #5 check security footage from bakery parking lot for cars that left the parking lot after 10:15am (within 10 minutes after robbing; so cutoff is 10:25)
SELECT * FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10
AND minute < 30 AND minute >= 15
AND activity = 'exit';

-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- +-----+------+-------+-----+------+--------+----------+---------------+

-- #6 check ATM on Legget St. for cash withdrawal on 7/28 before 10:15am
SELECT * FROM atm_transactions
WHERE month = 7
AND day = 28
AND atm_location LIKE 'Legget%';

-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 275 | 86363979       | 2021 | 7     | 28  | Leggett Street | deposit          | 10     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+

-- #7 check bank accounts related to Leggett Street ATM withdrawals
SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 28500762;

-- +----------------+-----------+---------------+--------+------+----------------+-----------------+---------------+
-- | account_number | person_id | creation_year |   id   | name |  phone_number  | passport_number | license_plate |
-- +----------------+-----------+---------------+--------+------+----------------+-----------------+---------------+
-- | 28500762       | 467400    | 2014          | 467400 | Luca | (389) 555-5198 | 8496433585      | 4328GD8       |
-- +----------------+-----------+---------------+--------+------+----------------+-----------------+---------------+

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 28296815; -- Kenny @ LP: 30G67EN

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 76054385; -- Taylor @ LP: 1106N58

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 49610011; -- Bruce @ LP: 94KL13X

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 16153065; -- Brooke @ LP: QX4YZN3

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 25506511; -- Iman @ LP: L93JTIZ

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 81061156; -- Benista @ LP: 8X428L0

SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 26013199; -- Diana @ LP: 322W7JE

-- After cross-checking License Plates from people, we can deduce there are a few suspects:
-- #1: Taylor @ LP: 1106N58 -> left parking @ 10:35 -> late already
-- #2: Iman @ LP: L93JTIZ (829-555-5269) -> left parking @ 10:21
-- #3: Diana @ LP: 322W7JE (770-555-1861) -> left parking @ 10:23
-- #4: Bruce @ LP: 94KL13X (367-555-5533) -> left parking @ 10:18
-- #5: Luca @ LP: 4328GD8 (389-555-5198) -> left parking @ 10:19

-- #8 check phone logs for calls on 7/28; filter duration in ascending order
-- Diana made contact to 725-555-3243 -> Philip
-- Bruce made contact to 375-555-8161 -> Robin
SELECT * FROM phone_calls
WHERE month = 7
AND day = 28
ORDER BY duration ASC;

-- #9 check people with phone number 725-555-3243 & 375-555-8161
SELECT * FROM people
WHERE phone_number LIKE '(725)%555-3243';

-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       |
-- +--------+--------+----------------+-----------------+---------------+

SELECT * FROM people
WHERE phone_number LIKE '(375)%555-8161';

-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
-- +--------+-------+----------------+-----------------+---------------+

-- #10 check airports, flights and passengers that are connected to Diana & Bruce
SELECT * FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.month = 7
AND flights.day = 29;

-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18        | 2835165196      | 9C   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 6131360461      | 2C   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 3231999695      | 3C   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 3592750733      | 4C   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 2626335085      | 5D   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 6117294637      | 6B   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 2996517496      | 7A   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 18        | 3915621712      | 8D   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 23        | 4149859587      | 7D   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 9183348466      | 8A   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 7378796210      | 9B   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 7874488539      | 2C   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 4195341387      | 3A   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 6263461050      | 4A   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 3231999695      | 5A   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 23        | 7951366683      | 6B   | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 36        | 7214083635      | 2A   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 1695452385      | 3B   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 5773159633      | 4A   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 1540955065      | 5C   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 8294398571      | 6C   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 1988161715      | 6D   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 9878712108      | 7A   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 36        | 8496433585      | 7B   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43        | 7597790505      | 7B   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 43        | 6128131458      | 8A   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 43        | 6264773605      | 9A   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 43        | 3642612721      | 2C   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 43        | 4356447308      | 3B   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 43        | 7441135547      | 4A   | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 53        | 7894166154      | 9B   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 6034823042      | 2C   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 4408372428      | 3D   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 2312901747      | 4D   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 1151340634      | 5A   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 8174538026      | 6D   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 1050247273      | 7A   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 53        | 7834357192      | 8C   | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+

-- #11 narrow down passport_number for Diana & Bruce
-- Diana: 3592750733
-- Bruce: 5773159633
-- we can deduce Bruce is taking the earliest flight compared to Diana...

SELECT * FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.month = 7
AND passport_number LIKE '3592750733';

-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18        | 3592750733      | 4C   | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 24        | 3592750733      | 2C   | 24 | 7                 | 8                      | 2021 | 7     | 30  | 16   | 27     |
-- | 54        | 3592750733      | 6C   | 54 | 8                 | 5                      | 2021 | 7     | 30  | 10   | 19     |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+

SELECT * FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.month = 7
AND passport_number LIKE '5773159633';

-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36        | 5773159633      | 4A   | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+

-- #12 check where this flight is headed to
SELECT * FROM flights
JOIN airports on flights.destination_airport_id = airports.id
WHERE destination_airport_id = 4
AND day = 29
AND minute = 20;

-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-------------------+---------------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | id | abbreviation |     full_name     |     city      |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-------------------+---------------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     | 4  | LGA          | LaGuardia Airport | New York City |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+----+--------------+-------------------+---------------+