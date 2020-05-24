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

print(letters)
print(words)
print(sentences)