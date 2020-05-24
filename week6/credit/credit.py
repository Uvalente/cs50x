while True:
    try:
        card = int(input("Number: "))
    except ValueError:
        print("Not a card! Try again.")
        continue
    else:
        break


checksum = 0
index = 0
firstDigit = int(str(card)[:1])
firstTwoDigits = int(str(card)[:2])

while card > 0:
    if index % 2 == 0:
        checksum += card % 10
        card = int(card / 10)
        index += 1
    else:
        value = (card % 10) * 2
        checksum += (value % 10) + int(value / 10)
        card = int(card / 10)
        index += 1


isValid = checksum % 10 == 0
isAmex = index == 15 and (firstTwoDigits == 34 or firstTwoDigits == 37)
isMastercard = index == 16 and firstTwoDigits > 50 and firstTwoDigits < 56
isVisa = index > 12 and index < 17 and firstDigit == 4


if isValid and isAmex:
    print("AMEX")
elif isValid and isMastercard:
    print("MASTERCARD")
elif isValid and isVisa:
    print("VISA")
else:
    print("INVALID")
