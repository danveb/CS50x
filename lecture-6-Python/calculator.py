# # Calculator
# from cs50 import get_int

# # Prompt user for "x"
# x = get_int("What's x? ")
# # Prompt user for "y"
# y = get_int("What's y? ")

# # Perform addition
# print(x + y)

# Without training wheels...

x = int(input("x: ")) # convert default "input" from string to int
y = int(input("y: "))
print(x + y)

z = x / y
print(f"{z:.50f}") # Floating-point imprecision

# Integer overflow
# Python counts as much as we want as it can dynamically keep expanding memory, but it limits the number of digits we can code