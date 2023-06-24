# # Implement a program that computes the approximate grade level needed to comprehend some text
# # A program first asks the user to type in some text, then outputs the grade level for the text
# # Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
# # L = avg number of letters per 100 words in text
# # S = avg number of sentences per 100 words in text

from cs50 import get_string


def main():
    input = get_string("Text: ")

    # coleman-liau index
    letters_per_word = count_letters(input) / count_words(input) * 100
    sentences_per_word = count_sentences(input) / count_words(input) * 100
    formula = round(0.0588 * letters_per_word - 0.296 * sentences_per_word - 15.8)

    """Conditions for formula"""
    if formula > 16:
        print("Grade 16+")
    elif formula < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {formula}")


def count_letters(text):
    """Function that counts alphanumeric chars by iterating over each character in string"""
    count = 0
    for char in text:
        if char.isalnum():
            count += 1
    # print(count)
    return count


def count_words(text):
    """Function that counts number of words in string"""
    if len(text) == 0:
        return 0

    # initialize count as 1 because a word is already 1
    count = 1
    for i in text:
        # check: if any spaces we know it's a word
        if i == " ":
            count += 1
    # print(count)
    return count


def count_sentences(text):
    """Function that counts number of sentences in string."""
    count = 0
    for i in text:
        # check: if there's a dot, ! or ? we know it's end of sentence so we can increase its count by 1
        if i == "." or i == "!" or i == "?":
            count += 1
    # print(count)
    return count


main()

# count_letters("hello")
# count_words("hello world")
# count_sentences("hello world. what is that?")

# test - $ check50 cs50/problems/2023/x/sentimental/readability
# style - $ style50 readability.py
# submit - $ submit50 cs50/problems/2023/x/sentimental/readability
