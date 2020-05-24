## Hello

Write, in a file called hello.py in ~/pset6/hello, a program that prompts a user for their name, and then prints hello, so-and-so, where so-and-so is their provided name, exactly as you did in Problem Set 1, except that your program this time should be written (a) in Python and (b) in CS50 IDE.

## Mario

- Write, in a file called mario.py in ~/pset6/mario/more/, a program that recreates these half-pyramids using hashes (#) for blocks, exactly as you did in Problem Set 1, except that your program this time should be written (a) in Python and (b) in CS50 IDE.
- To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive. (The height of the half-pyramids pictured above happens to be 4, the width of each half-pyramid 4, with a gap of size 2 separating them).
- If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
- Then, generate (with the help of print and one or more loops) the desired half-pyramids.
- Take care to align the bottom-left corner of your pyramid with the left-hand edge of your terminal window, and ensure that there are two spaces between the two pyramids, and that there are no additional spaces after the last set of hashes on each row.

## Credit

- In credit.py in ~/pset6/credit/, write a program that prompts the user for a credit card number and then reports (via print) whether it is a valid American Express, MasterCard, or Visa card number, exactly as you did in Problem Set 1, except that your program this time should be written (a) in Python and (b) in CS50 IDE.
- So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.
- For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
- Best to use get_int or get_string from CS50’s library to get users’ input, depending on how you to decide to implement this one.