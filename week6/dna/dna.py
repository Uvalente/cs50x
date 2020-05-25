from sys import argv, exit
import csv


def main():
    if not len(argv) == 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    dataset = {}
    with open(argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row["name"]
            del row["name"]
            dataset[name] = row

   
main()
