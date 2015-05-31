#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

// encrypt a user-proved string via a key provided by parameter

int main(int argc, string argv[])
{
    // get the key parameter and convert to int
    int key = atoi(argv[1]);
    int alphaIndex;
    char cipherText;
    
    if (argc != 2)
    {
        printf("Please run again with one key argument\n");
        return 1;
    }
   
    string userString = GetString();
        
    // iterate over the userString, adding key to each char
    // and printing
    for (int i = 0, n = strlen(userString); i < n; i++)
    {
        // check if the char is a letter, then determine case
        if (isalpha(userString[i]))
        {
            if (isupper(userString[i]))
            {
                // letter - 'A' = alpha index (0)
                alphaIndex = userString[i] - 'A';
                cipherText = ((alphaIndex + key) % 26) + 'A'; 
                printf("%c", cipherText);
            }
            else if (islower(userString[i]))
            {
                // letter - 'a' = alpha index (0)
                alphaIndex = userString[i] - 'a';
                cipherText = ((alphaIndex + key) % 26) + 'a'; 
                printf("%c", cipherText);
            }   
        }
        else
        {
            printf("%c", userString[i]);
        } 
        
    }
    
    printf("\n");
       
    return 0;
}

char encypher()

