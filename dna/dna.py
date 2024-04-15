import sys
import csv
import re
import string

if len(sys.argv) != 3:
    print( "Error ,need only 2 args")

seq = open (sys.argv[2], "r").read()
max_seq = 0
counter = 0
longest = " "
sequences = ["AGATC","TTTTTTCT","AATG","TCTAG","GATA","TATC","GAAA","TCTG" ]
found = True

for i in range(len(sequences)):
    search  = sequences [i]
    temp = sequences [i]
    while re.search(search, seq):
        counter += 1
        search += temp

    if counter >  max_seq:
        max_seq = counter
        longest = sequences[i]
    counter = 0
found  = False

try:
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            if re.search(str(max_seq),row[longest]) and (found == False):

                found = True
                print( str(dict(row)).split(",")[0][10:len(str(dict(row)).split(",")[0]) - 1])
                break

except:
    found = True
    print("No match")

if found == False:
    print("No match")
