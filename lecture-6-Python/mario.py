# Mario

# 1
# for i in range(3):
#     print("#")

# from cs50 import get_int

# while True:
#     n = get_int("Height: ")
#     if n > 0:
#         break
# for i in range(n):
#     print("#")

# def main():
#     """Print out # based on height"""
#     height = get_height()
#     for i in range(height):
#         print("#")
# # helper function
# def get_height():
#     """Get user input for height and returning it"""
#     while True:
#         # use try/except block in case valueError gets triggered
#         try:
#             n = int(input("Height: "))
#             if n > 0:
#                 return n
#         except ValueError:
#             print("Not an integer")
# # execute main function
# main()

# for i in range(4):
#     # when adding an additional argument we can print "horizontally"
#     # default value of "end" is \n
#     print("?", end="")
# print()

# multiply ? times 4
# print("?" * 4)

# 2 dimensional (grid) of bricks?
for i in range(3):
    # for j in range(3):
    #     print("#", end="")
    # print()
    # OR
    print("#" * 3)

