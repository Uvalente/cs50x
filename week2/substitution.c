#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  if (argc == 2)
  {
    if (strlen(argv[1]) != 26)
    {
      printf("Key must contain 26 characters.\n");
      return 1;
    }

    for (int i = 0; i < 26; i++)
    {
      if (!isalpha(argv[1][i]))
      {
        printf("Must contain only alphabet letters.\n");
        return 1;
      }
      for (int j = 0; j < 26; j++)
      {
        if (i == j)
        {
          continue;
        }
        else if (argv[1][i] == argv[1][j])
        {
          printf("Can not contain duplicated characters.\n");
          return 1;
        }
      }
    }
  }
  else
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  string plain_text = get_string("plaintext: ");

  int values[26];

  for (int i = 0; i < 26; i++)
  {
    values[i] = (int)toupper(argv[1][i]);
  }

  int text_size = strlen(plain_text);

  char cipher_text[text_size];

  int letter_value;
  for (int i = 0; i < text_size; i++)
  {

    int is_lower = islower(plain_text[i]);
    if (is_lower)
    {
      letter_value = (int)plain_text[i] - 32;
    }
    else
    {
      letter_value = (int)plain_text[i];
    }

    if (letter_value < 65 || letter_value > 91)
    {
      cipher_text[i] = plain_text[i];
    }
    else
    {
      for (int j = 65; j < 91; j++)
      {
        if (letter_value == j)
        {
          if (is_lower)
          {
            cipher_text[i] = (char)(values[j - 65] + 32);
          }
          else
          {
            cipher_text[i] = (char)values[j - 65];
          }
        }
      }
    }
  }

  printf("ciphertext: %s\n", cipher_text);

  return 0;
}
