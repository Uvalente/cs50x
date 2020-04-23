#include <stdio.h>

int main(void)
{
  long card_number;
  int index = 0, length = 0;
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
    numbers[index] = card_number % 10;
    card_number /= 10;
    index++;
  }

  int checksum = 0;
  for (int i = 0; i < length; i++)
  {
    if (i % 2 == 0)
    {
      checksum += numbers[i];
    }
    else
    {
      int number = numbers[i];
      number *= 2;
      if (number < 10)
      {
        checksum += number;
      }
      else
      {
        checksum += number % 10;
        checksum += number / 10;
      }
    }
  }

  if (checksum % 10 == 0 && length >= 13)
  {
    switch (numbers[length - 1])
    {
    case 3:
      numbers[length - 2] == 4 || numbers[length - 2] == 7 ? printf("AMEX\n") : printf("INVALID\n");
      break;
    case 4:
      printf("VISA\n");
      break;
    case 5:
      numbers[length - 2] < 6 ? printf("MASTERCARD\n") : printf("INVALID\n");
      break;
    default:
      printf("INVALID\n");
      break;
    }
  }
  else
  {
    printf("INVALID\n");
  }
}
