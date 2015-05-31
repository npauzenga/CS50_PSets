#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

// encrypt a user-proved string via a key provided by parameter

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
        
    // iterate over the userString, adding key to each char
    // and storing in new string
    for (int i = 0, int n = strlen(userString); i < n; i++)
    {
        // check if the char is a letter, then determine case
        if (isalpha(userString[i]))
        {
            if (isupper(userString[i]))
            {
                
            }
            else if (islower(userString[i]))
            {
            
            }
        }
        
    }
       
    return 0;

}
