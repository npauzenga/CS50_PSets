#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

 
/* 
    loop through the key string, converting each char to an
    alphabetical, 0-based index (from ASCII) and passing to
    encypher()  
*/

void encypher(int key, char origLetter);

int main(int argc, string argv[])
{
    int keyChar;
    
    // check if there is an argument supplied
    if (argc != 2)
    {
        printf("Please run again with one key argument\n");
        return 1;
    }
    
    // check if the keyword contains illegal chars
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
            continue;
            
        else
        {
            printf("Keywork must only contain letters\n");
            return 1;
        }
    }
    
    // get the key parameter as a string and the text to encypher
    string key = argv[1];
    string userString = GetString(); 
   
    for (int i = 0, j= 0, n = strlen(userString); i < n; i++, j++)
    {
        if (isalpha(userString[i]))
        {  
            // using j % strlen(key) with j incrementing to
            // wrap around
            keyChar = toupper(key[j % strlen(key)]) - 'A';
            encypher(keyChar, userString[i]); 
        }         

        else
        {
            j--;
            printf("%c", userString[i]);
        }
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

