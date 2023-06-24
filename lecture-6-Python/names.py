import sys
# from sys import exit

names = ["Bill", "Charlie", "Fred", "George", "Jinny", "Percy", "Ron"]
name = input("Name: ")
# Linear search over names "list"
# iterate over each of the names
# for n in names:
#     if name == n:
#         print("Found")
#         sys.exit(0)
# print("Not found")
# sys.exit(1)

for name in names:
    print("Found")
    sys.exit(0)
print("Not found")
sys.exit(1)