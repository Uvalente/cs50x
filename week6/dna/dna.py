from sys import argv, exit

if not len(argv) == 3:
  print("Usage: python dna.py data.csv sequence.txt")
  exit(1)