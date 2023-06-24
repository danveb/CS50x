# Intro to Python

# Compiling in C
# $ make hello
# $ ./hello

# Compiling in C (continued)
# $ clang -o hello hello.c -lcs50
# $ ./hello

# C is a compiling language, where we convert source code into machine code (0/1's)
# Python doesn't require any compiling, we run an "INTERPRETER"

# "Interpreting" in Python (no need for compiling)
# $ python hello.py

# print("hello, world")

# For header files in Python we can use:
# $ import cs50 (library)

# we can import specific functions from libraries
from cs50 import get_string

# Functions in Python
answer = get_string("What's your name? ")
print("hi, " + answer) # concatenates + answer (dynamically based on variable "answer")
print("hi, ", answer)
print(f"hello, {answer}")

# Data Types in Python
# -> Python uses more memory compared to C so we can have various data types
# bool
# float
# int
# str
# range
# list
# tuple
# dict - key/value pair
# set

# Higher-level languages (like Python) allow to write code more succinctly
# C is more memory-efficient, resulting in code compiling faster
# However, Python is a more english-like language where syntax is much clearer compared to C

# CS50 Library
# just like in C, we can import libraries to be utilized with Python
### get_float
### get_int
### get_string
# Optionally we can import specific functions from CS50 library
### from CS50 import get_float, get_int, get_string

# Conditionals
if x < y:
    print("x is less than y")

# Variables
counter = 0
counter = counter + 1
counter += 1

# Loops

## While Loop
i = 0
while i < 3:
    print("meow")
    i += 1

# while True:
#     print("meow")

## For Loop
for i in [0, 1, 2]:
    print("hello world")

for i in range(3):
    print("hellow world")

# Object-oriented programming
## Paradigm based on the concept of "objects", which contain data and code that manipulates the data.
## In JS objects can be created using object literal or using constructor functions
## In JS objects have properties (key/value pairs) and methods (functions that operate on object's properties)

const person = {
    first_name: "John",
    last_name: "Doe",
    full_name: function() {
        return this.first_name + " " + this.last_name;
    }
}

# Try/Except Block tests for "one line" of code that will fail; when it fails we can throw an error

# Lists (Arrays) are a data structure within Python
# Lists have built-in methods or functions within them

# SYS Library
# default Python library that comes with built-in functionality for command-line arguments
from sys import argv

# Dictionaries (Objects) are a data structure within Python
# Dictionaries take in key/value pairs

# Strings in python are immutable, but can be returned as copies, like when we capitalize a word.