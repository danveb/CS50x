from cs50 import SQL

# initialize db as SQL("sqlite:///name_of_database")
db = SQL("sqlite:///favorites.db")

# prompt user a question
favorite = input("Favorite: ")

# select from "favorites.db" where students find the most favorite problem
# SQL -> SELECT * FROM favorites WHERE problem = 'Mario';
# Python -> variable = db.execute("SQL_query")
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = 'Mario'")

# iterate over rows
# for row in rows:
#   print(row["n"])

row = rows[0]
print(row["n"])

# execute