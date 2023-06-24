# import cs50
from cs50 import get_string

answer = get_string("What's your name: ")
print("hello world")
print("hi, " + answer) # concatenates + answer (dynamically based on variable "answer")
print("hi, ", answer) 
print(f"hello, {answer}") # format string (f-string)

# Run Python
# $ python hello.py