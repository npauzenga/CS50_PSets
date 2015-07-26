#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int value = 5;
    int* ptr = &value; // assigns the address of value to ptr;
    printf("%i%i\n", value, *ptr); //prints the data stored at ptr's address
    
    typedef struct name
    {
        char firstName[5];
        int length;
    }
    name;
    
    name* nate = malloc(sizeof(name));
    nate->length = 4;
    strcpy(nate->firstName, "Nate");
    
    char* lastName[9];
    *lastName = "fuzzypants";
    printf("%s\n", *lastName);
    
    


    
    return 0;
}

/*bool load(const char* dictionary)*/
/*{*/
/*    FILE* dict = fopen(dictionary, "r");*/
/*    */
/*    if (dict == NULL)*/
/*    {*/
/*        printf("dictionary failed to open\n");*/
/*        return -1;*/
/*    }*/
/*    */
/*    // define node for linked list*/
/*    typedef struct node*/
/*    {*/
/*        char word[LENGTH + 1];*/
/*        struct node* next;*/
/*    }*/
/*    node;*/
/*    */
/*    // grab space for 2 nodes*/
/*    node* node1 = malloc(sizeof(node));*/
/*    node* node2 = malloc(sizeof(node));*/
/*    */
/*    // scan the first word in dict and put it in node1's word*/
/*    fscanf(dict, "%s", node1->word);*/

/*    */
/*    // hash the word*/
/*    */
/*    return false;*/
/*}*/


