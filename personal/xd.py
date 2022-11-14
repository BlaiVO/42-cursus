import string
import time
import sys

abc = list(string.printable)
i = 0
j = 0
word = ""
try:
    target = sys.argv[1]
except IndexError:
    target = "Hello World!"
while word != target:
    print(f"{word}{abc[j]}")
    if abc[j] == target[i]:
        word += abc[j]
        i += 1
        j = 0
    else:
        j += 1
    time.sleep(0.01)
