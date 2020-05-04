#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// refactor to struct, array or pointer

int count_letters(string string);
int count_words(string string);
int count_sentences(string string);

int main(void)
{
  string text = get_string("Text: ");

  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  float average_letters = (letters * 100) / (float)words;
  float average_sentences = (sentences * 100) / (float)words;

  int grade = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

  if (grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %d\n", grade);
  }
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

int count_sentences(string string)
{
  int sentences = 0;
  int length = strlen(string);

  for (int i = 0; i < length; i++)
  {
    int value = string[i];
    if (value == 33 || value == 46 || value == 63)
    {
      sentences++;
    }
  }

  return sentences;
}
