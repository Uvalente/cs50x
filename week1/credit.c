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
    numbers[pointer] = digit;
    card_number /= 10;
    pointer++;
  }

  int checksum = 0;
  for (int i = 1; i <= length; i += 2)
  {
    numbers[i] *= 2;
    if (numbers[i] < 10)
    {
      checksum += numbers[i];
    }
    else
    {
      checksum += numbers[i] % 10;
      checksum += numbers[i] / 10;
    }
  }

  for (int i = 0; i <= length; i += 2)
  {
    checksum += numbers[i];
  }
  printf("checksum: %d\n", checksum);
}
