# from cs50 import get_string

# initialize a dictionary
# people = dict()

# people = {
#     # key / value
#     "Carter": "+1-617-495-1000",
#     "David": "+1-949-468-2750"
# }

# # Search for name
# name = get_string("Name: ")
# if name in people:
#     print(f"Number: {people[name]}")

import csv

# # open a file
# file = open("phonebook.csv", "a") # use append mode

# # prompt user for name and number
# name = input("Name: ")
# number = input("Number: ")

# # write in CSV
# writer = csv.writer(file)
# writer.writerow([name, number])

# # close the file
# file.close()

# with open("phonebook.csv", "a") as file:
#     name = input("Name: ")
#     number = input("Number: ")

#     writer = csv.writer(file)
#     writer.writerow([name, number])

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
