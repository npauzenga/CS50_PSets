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
    char wordBucket[LENGTH + 1];
    
    // for each word's array index
    int index;
    
    // initialize each element to a new node called head
    for(i = 0, j = TABLE_SIZE; i < j; i++)
    {
        node* head = malloc(sizeof(node));
        hashTable[i] = head
        hashTable[i]->word = NULL;
        hashTable[i]->next = NULL;
    }
    
    // for every element in the dict, store to wordBucket
    while(fscanf(dict, "%s", wordBucket)) //!= EOF?
    {
        // hash the word to get it's index
        index = hash_function(new_node->word, TABLE_SIZE);
        
        // TODO if there's already a node at this index
        // with a word not set to NULL, malloc a new node
        // and assign the word to it
        node* new_node = malloc(sizeof(node));
        
        // copy the string to the node
        strcpy(new_node->word, wordBucket);
        
        
        
        // set the head node to point to this one
        new_node->next = hashTable[index];
        hashTable[index]->next = new_node

        
        //hash the word and insert into table
        hashTable[index] = new_node;
        
        // TODO count how many words have been added
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
