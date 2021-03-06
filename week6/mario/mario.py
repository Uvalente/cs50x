def main():
    height = getHeight()
    printPyramid(height)


def getHeight():
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            print("Not an integer! Try again.")
            continue
        if height > 0 and height < 9:
            return height


def printPyramid(height, spaces = 0):
    if height == 0:
        return
    printPyramid(height - 1, spaces + 1)
    print(" " * spaces + "#" * height, end="")
    print(" ", "#" * height)


main()
