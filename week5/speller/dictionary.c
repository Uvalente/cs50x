// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Initial simple hash, return first letter value
    return (int)word[0] % 97;
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
        node *n = malloc(sizeof(word));
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
    }
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
