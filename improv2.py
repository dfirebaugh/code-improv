#Sentence scrambler.

import random

y = input("\n\nplease enter a sentence to be scrambled. poems that rhyme work the best.\n")

#y = "Jamie is guy who sits and acts real fly if anyone knew what would they do would they sit and watch him too?"

def words(y):
    word = ""
    words = []
    for char in y:
        if char != " ":
            word += char
        else:
            words.append(word)
            word = ""
    return words

words = words(y)

def scramble_words(words):
    new_order = []
    new_message = ""
    counter = 1
    for word in words:
        new_order.insert(random.randint(0, len(words) - counter), word)
        counter += 1
    for item in new_order:
        new_message += (" " + item)
    return new_message


print(scramble_words(words))
