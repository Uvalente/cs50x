#include <stdio.h>

int main(void)
{
  long card_number;
  int pointer = 0;
  int length = 0;
  printf("Number: ");
  scanf("%ld", &card_number);
  long counter = card_number;
  while (counter != 0)
  {
    counter /= 10;
    length++;
  }

  int numbers[length];

  while (card_number > 0)
  {
    int digit = card_number % 10;
    card_number /= 10;
    numbers[pointer] = digit;
    pointer++;
  }
}
