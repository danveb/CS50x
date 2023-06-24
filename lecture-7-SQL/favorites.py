# write a python program to read a "csv" file, reads it and print something out

# import csv program (natively from Python)
import csv

# #1
# open csv file in "read" mode (explicitly)
# with open("favorites.csv", "r") as file: # file can by any name, just "file" is OK
#     # initialize reader variable and set to opened "file"
#     reader = csv.reader(file)
#     # skip header row
#     next(reader)
#     # iterate over csv file, printing each favorite
#     for row in reader:
#         # print(row[1]) # prints out programming language -> C, Python, Python, Python, etc.
#         # initialize favorites variable as row[1] so we can print it out
#         favorites = row[1]
#         print(favorites) # prints out programming language -> C, Python, Python, Python, etc.

# #2
# with open("favorites.csv", "r") as file:
#     # set reader to DictReader, that returns a dictionary
#     reader = csv.DictReader(file)
#     scratch, c, python = 0, 0, 0 # set all variables start at 0
#     for row in reader:
#         # read from "language" column
#         favorite = row["language"]
#         # check: if favorite is "Scratch"? we'll increase by 1
#         if favorite == "Scratch":
#             scratch += 1
#         # else if, "C"? we'll increase by 1
#         elif favorite == "C":
#             c += 1
#         # else if, "Python"? we'll increase by 1
#         elif favorite == "Python":
#             python += 1

# print(f"Scratch: {scratch}") # Scratch: 0
# print(f"C: {c}") # C: 1
# print(f"Python: {python}") # Python: 4

# #3
# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     # initialize counts as {}
#     counts = {}
#     for row in reader:
#         favorite = row["language"]
#         if favorite in counts:
#             counts[favorite] += 1
#         else:
#             counts[favorite] = 1

# for favorite in counts:
#     print(f"{favorite}: {counts[favorite]}")
# # C: 1
# # Python: 4

# def get_value(language):
#     return counts[language]

# for favorite in sorted(counts, key=get_value, reverse=True):
#     print(f"{favorite}: {counts[favorite]}")
# # Python: 4
# # C: 1

# #4
# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     counts = {}
#     for row in reader:
#         favorite = row["problem"]
#         if favorite in counts:
#             counts[favorite] += 1
#         else:
#             counts[favorite] = 1

# for favorite in sorted(counts):
#     print(f"{favorite}: {counts[favorite]}")
# Credit: 1
# Mario: 1
# Readability: 1
# Runoff: 1
# Scratch: 1

# #5
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        favorite = row["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1
favorite = input("Favorite: ") # use any of the "problems" in CSV to return the count of this "problem"
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")


# execute current file
# python favorites.py