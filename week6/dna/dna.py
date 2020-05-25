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


def counting(text, word):
    max_count = 0
    word_length = len(word)

    for i in range(len(text)):
        current_count = 0
        while text[i:i + word_length] == word:
            current_count += 1
            i += word_length
        if current_count > max_count:
            max_count = current_count

    return max_count


main()
