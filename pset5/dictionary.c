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

// keep track of how many words are added
int wordCount = 0;

 
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
    int wordLength = strlen(word);
    
    // convert word to lowercase
    char lowercaseWord[wordLength];
    
    for(int i = 0; i <= wordLength; i ++)
    {
        lowercaseWord[i] = tolower(word[i]);
    }
    
    // hash the word to find it's index and put our cursor there
    node* current = hashTable[hash_function(lowercaseWord, TABLE_SIZE)];
    
    // search the linked list at that index
    while (current != NULL)
    {
        if (strcmp(lowercaseWord, current->word) == 0)
        {
            return true;
        }
        else
        {
            current = current->next;
        }
    }

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

    
    // for each word's array index
    int index;
    
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
            free(new_node);
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
/*    for(int i = 0, j = TABLE_SIZE; i <= j; i++)*/
/*    {*/
/*        node * current = hashTable[i];*/
/*        */
/*        while (current != NULL)*/
/*        {*/
/*            printf("%s\n", current->word);*/
/*            current = current->next;*/
/*        }*/
/*    }*/
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{

    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i <= TABLE_SIZE; i++)
    {
        node* cursor = hashTable[i];
        
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    
    return true;
}
