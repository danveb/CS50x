# Words in dictionary

# define a variable and set to a set (collection of values without duplicates)
words = set()

# initialize functions: check, load, size, unload
def check(word):
    """Return true if word is in dictionary else false"""
    if word.lower() in words: # handle a lowercase word
        return True
    else:
        return False

def load(dictionary):
    """Load dictionary into memory, returning true if successful, else false"""
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip() # reverse strip to cut off trailing \n
        words.add(word) # .add() method for a set
    file.close()
    return True

def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words) # returns length of the word

def unload():
    """Unloads dictionary from memory, returns true if successful, else false"""
    return True