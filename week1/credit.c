#include <stdio.h>

int main(void)
{
  long card_number;
  int numbers[15];
  int pointer = 0;
  printf("Number: ");
  scanf("%ld", &card_number);
  while (card_number > 0)
  {
    int digit = card_number % 10;
    card_number /= 10;
    numbers[pointer] = digit;
    pointer++;
  }
}
