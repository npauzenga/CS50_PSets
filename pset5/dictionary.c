/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define TABLE_SIZE 5

/**
 * Has function based on the first letter of string
 */
int hash_function(char* key, const int SIZE)
{
    int hash = toupper(key[0]) - 'A';
    return hash % SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 * For each word in dictionary, store word in hash table (or trie)
 */
bool load(const char* dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    
    if (dict == NULL)
    {
        printf("dictionary failed to open\n");
        return false;
    }
    
    // define node for linked list
    typedef struct node
    {
        char word[LENGTH + 1];
        struct node* next;
    }
    node;
    
    node* hashTable[TABLE_SIZE];
    
    // temp storage for each word
    char* wordBucket[LENGTH + 1];
    
    // for every element in the dict, store to wordBucket
    // TODO seg fault here
    while(fscanf(dict, "%s", *wordBucket))
    {
        // grab space for a new node
        node* new_node = malloc(sizeof(node));
        
        strcpy(new_node->word, *wordBucket);

        hashTable[hash_function(new_node->word, TABLE_SIZE)] = new_node;
        
        // count how many words have been added
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
