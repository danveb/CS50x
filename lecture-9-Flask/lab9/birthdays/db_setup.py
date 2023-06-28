# open birthdays.db
# $ sqlite3 birthdays.db
# sqlite> .schema

CREATE TABLE birthdays (
    id INTEGER,
    name TEXT,
    month INTEGER,
    day INTEGER,
    PRIMARY KEY(id)
);

# grab all data from birthdays table
SELECT * FROM birthdays;

# insert name, month and day to birthdays table
INSERT INTO birthdays (name, month, day)
VALUES ("So", 8, 7);

