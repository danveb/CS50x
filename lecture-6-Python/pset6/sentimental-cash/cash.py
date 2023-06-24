# Write a program that first asks the user how much change is owed and then spits out the minimum number of coins with which change can be made
# use "get_float" from cs50 library to get user's input and "print" output
# only coin denominations are 0.25, 0.10, 0.05 and 0.01
# if user fails to provide a non-negative value, program will re-prompt user for valid amount

from cs50 import get_float

while True:
    cents = get_float("Change owed: ")
    if cents > 0:
        break

cents = round(cents * 100)

count = 0

# number of quarters
while cents >= 25:
    cents = cents - 25
    count += 1

# number of dimes
while cents >= 10:
    cents = cents - 10
    count += 1

# number of nickels
while cents >= 5:
    cents = cents - 5
    count += 1

# number of penny
while cents >= 1:
    cents = cents - 1
    count += 1

print("Total coins:", count)

# test - $ check50 cs50/problems/2023/x/sentimental/cash
# style - $ style50 cash.py
# submit - $ submit50 cs50/problems/2023/x/sentimental/cash
