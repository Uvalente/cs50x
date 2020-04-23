#include <stdio.h>

int main(void)
{
  long card_number;
  int index = 0, length = 0;
  printf("Number: ");
  scanf("%ld", &card_number);
  long counter = card_number;
  while (counter > 0)
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
      int number = numbers[i] * 2;
      checksum += (number % 10) + (number / 10);
    }
  }

  int first_digit = numbers[length - 1];
  int first_two_digits = (first_digit * 10) + numbers[length - 2];

  if (checksum % 10 == 0 && length >= 13 && (first_two_digits == 34 || first_two_digits == 37))
  {
    printf("AMEX\n");
  }
  else if (checksum % 10 == 0 && length >= 13 && (first_two_digits > 50 && first_two_digits < 56))
  {
    printf("MASTERCARD\n");
  }
  else if (checksum % 10 == 0 && length >= 13 && first_digit == 4)
  {
    printf("VISA\n");
  }
  else
  {
    printf("INVALID\n");
  }
}
