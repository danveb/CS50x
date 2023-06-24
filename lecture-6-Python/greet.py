from sys import argv

# if len(argv) == 2:
#     print(f"hello, {argv[1]}")
# else:
#     print("hello, world")

# for i in range(len(argv)):
#     print(argv[i])

# for arg in argv:
#     print(arg)

# slice argv from 1st element until end
for arg in argv[1:]:
    print(arg)

for arg in argv[0:1]:
    print(arg)