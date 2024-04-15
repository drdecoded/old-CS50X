# TODO

import math
from cs50 import get_string

sentence = 0
letters = 0
words = 0

text = get_string("Text: ");

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i] == ' ':
        words += 1
    elif text[i] == '!' or text[i] == '?' or text[i] == '.':
        sentence += 1

if words > 0:
    words += 1

index = round((5.88 * (letters / words)) - (29.6 * (sentence / words)) - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade", index)