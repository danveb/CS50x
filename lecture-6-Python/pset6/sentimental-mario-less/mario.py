# Mario
# Write a program that recreates the half-pyramid using # for blocks
# prompt user with get_int for a positive integer between 1-8 inclusive
# If user fails to provide a positive integer no greater than 8 we will re-prompt user
# generate the half pyramid

from cs50 import get_int


def main():
    """Main function that takes in user input for height and prints out desired pyramid based on user height"""
    height = get_height()
    print_grid(height)


def get_height():
    """Helper function that calculates the height"""
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    return height


def print_grid(size):
    """Helper function to print the pyramid"""
    for i in range(0, size, 1):
        for j in range(0, size, 1):
            if (i + j < size - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()


main() 

# test - $ check50 cs50/problems/2023/x/sentimental/mario/less
# style - $ style50 mario.py
# submit - $ submit50 cs50/problems/2023/x/sentimental/mario/less
