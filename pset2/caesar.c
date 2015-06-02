#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

/* 
*  prompt user for text to encrypt via a key provided by parameter
*/

void encypher(int key, char origLetter);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please run again with one key argument\n");
        return 1;
    }
    
    // get the key parameter and convert to int
    int key = atoi(argv[1]);
    string userString = GetString();

    for (int i = 0, n = strlen(userString); i < n; i++)
    {
        if (isalpha(userString[i]))
            encypher(key, userString[i]);          

        else
            printf("%c", userString[i]);
    }
    
    printf("\n");
       
    return 0;
}

// given the key and original letter, convert to encyphered letter
void encypher(int key, char origLetter)
{
    int alphaIndex;
    char cipherText;
    char ascIndex = 'a';
    
    if (isupper(origLetter))
        ascIndex = toupper(ascIndex);
    
    // using the original letter and 'a' or 'A'
    // get the alphabetical index
    alphaIndex = origLetter - ascIndex;
    
    // convert back to ASCII & print
    cipherText = ((alphaIndex + key) % 26) + ascIndex; 
    printf("%c", cipherText);  
}

