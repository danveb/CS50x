import sys

# check: if length of command-line argument is NOT 2
if len(sys.argv) != 2:
    # print out error message
    print("Missing command-line argument")
    # exit with status 1 (error)
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
# exit with status 0 (success)
sys.exit(0)

# check error code?
# $ echo $? 0 or 1 based on exit status 