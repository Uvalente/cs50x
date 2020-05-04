#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// refactor to struct, array or pointer

int count_letters(string string);
int count_words(string string);

int main(void)
{
  int grade = 0;
  string text = get_string("Text: ");

  int letters = count_letters(text);
  int words = count_words(text);

  printf("%d\n", letters);
  printf("%d\n", words);
}

int count_words(string string)
{
  int words = 1;
  int length = strlen(string);

  for (int i = 0; i < length; i++)
  {
    if (isspace(string[i]))
    {
      words++;
    }
  }

  return words;
}

int count_letters(string string)
{
  int letters = 0;
  int length = strlen(string);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(string[i]))
    {
      letters++;
    }
  }

  return letters;
}
