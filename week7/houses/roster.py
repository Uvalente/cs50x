from sys import argv, exit
import sqlite3

if not len(argv) == 2:
    print("Usage: python roster.py houseName")
    exit(1)

connection = sqlite3.connect("students.db")
db = connection.cursor()

for row in db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first;", (argv[1],)):
    print(row[1], row[2], row[3], end=", ") if row[2] else print(
        row[1], row[3], end=', ')
    print("born", row[5])

connection.close()
