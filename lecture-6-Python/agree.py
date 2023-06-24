# Logical operators

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
# if s == "Y" or s == "y":
#     print("Agreed")
# elif s == "N" or s == "n":
#     print("Not agreed")

# using methods
s = s.lower()
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")