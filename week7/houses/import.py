from sys import argv, exit
import csv
import sqlite3

if not len(argv) == 2:
    print("Usage: python import.py characters.csv")
    exit(1)

open("students.db", "w").close()
connection = sqlite3.connect("students.db")
db = connection.cursor()
db.execute("CREATE TABLE students (id INTEGER PRIMARY KEY, first TEXT NOT NULL, middle TEXT, last TEXT NOT NULL, house TEXT NOT NULL, birth INTEGER NOT NULL);")
connection.commit()

with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        name = row["name"].split()
        first = name[0]
        last = name[-1]
        if len(name) == 3:
            middle = name[1]
        else:
            middle = None

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?);",
                   (first, middle, last, row["house"], row["birth"]))
        connection.commit()

connection.close()
