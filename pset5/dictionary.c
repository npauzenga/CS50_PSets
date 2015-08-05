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

#define TABLE_SIZE 100


 
/**
 * Hash function based on the first letter of string
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
    
    // for each word's array index
    int index;
    
    // keep track of how many words are added
    int wordCount = 0;
    
    // initialize each element to a new node called head
    for(int i = 0, j = TABLE_SIZE; i < j; i++)
    {
        node* head = malloc(sizeof(node));
        hashTable[i] = head;
    }
    

    while(true) 
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        
        // read the word into the node, if it's at the end, kill it
        if(fscanf(dict, "%s", new_node->word) == EOF)
        {
            break;
        }
        
        // hash the word to get it's index
        index = hash_function(new_node->word, TABLE_SIZE);
        
        // put the address of the new_node into the table at index
        new_node->next = hashTable[index];
        hashTable[index] = new_node;

        
        // count how many words have been added
        wordCount += 1;
    }
    
    // print table (for testing)
    for(int i = 0, j = TABLE_SIZE; i <= j; i++)
    {
        node * current = hashTable[i];
        
        while (current != NULL)
        {
            printf("%s\n", current->word);
            current = current->next;
        }
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
