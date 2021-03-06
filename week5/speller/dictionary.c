// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65535;

// Hash table
node *table[N];

// Dictionary word count
unsigned int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    
    for (node *temp = table[index]; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        c = tolower(c);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return (unsigned int)(hash % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(dictionary_file, "%s", word) != EOF)
    {
        // Hash the word and return table index
        unsigned int index = hash(word);
        // Allocate memory for the node
        node *n = malloc(sizeof(node));
        // change to !n
        if (n == NULL)
        {
            return 1;
        }

        // Copy word to node
        strcpy(n->word, word);
        // Link new node to existing one or link to NULL and link table to it
        n->next = table[index];
        table[index] = n;
        word_count++;
    }

    fclose(dictionary_file);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
    }
    return true;
}
