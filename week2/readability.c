#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letter(string string);

int main(void) {
    int grade = 0;
    string text = get_string("Text: ");

    int letters = count_letter(text);

    printf("%d\n", letters);
}

int count_letter(string string) {
    int letters = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(string[i])) {
            letters++;
        }
    }

    return letters;
}
