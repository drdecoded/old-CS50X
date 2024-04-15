# TODO

from cs50 import get_int

# ask user for input

height = get_int("Height: ")

# setting counter variables

counter = 1
counter2 = 1

# setting up a while loop to add height

while (height > 8) or (height < 1):
    height = get_int("Height: ")

# setting up for loop for variable i in height to create the mario pyramide

for i in range(height):
      for k in range(height - counter):
          print(" ", end="")

      for e in range(counter):
          print("#", end="")

      print("  ", end="")

      for v in range(counter2):
          print("#", end="")

      print ("\n", end="")

      counter += 1

      counter2 += 1

