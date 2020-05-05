#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
  if (argc == 2)
  {
    if (strlen(argv[1]) != 26)
    {
      printf("Key must contain 26 characters.\n");
      return 1;
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
    values[i] = (int)argv[1][i];
  }

  int text_size = strlen(plain_text);

  char cipher_text[text_size];

  for (int i = 0; i < text_size; i++)
  {
    for (int j = 65; j < 91; j++)
    {
      if ((int)plain_text[i] == j)
      {
        cipher_text[i] = (char)values[j - 65];
      }
    }
  }

  printf("ciphertext: %s\n", cipher_text);

  return 0;
}
