text = input("Text: ")
words = 0
letters = 0
sentences = 0

for word in text.split():
    words += 1
    for letter in word:
        if letter.isalpha():
            letters += 1
        elif letter in [".", "!", "?"]:
            sentences += 1

avg_letters = (letters * 100) / words
avg_sentences = (sentences * 100) / words

grade = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
