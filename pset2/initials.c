#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char firstInit;
    char secondInit;
    char thirdInit;
    
    string name = GetString();
    
    if (name != NULL)
    {
    
        // extract the first character of the string for the first name
        firstInit = toupper(name[0]);
        printf("%c", firstInit);
        
        // look for spaces and take the next letter
        for(int i = 0, n = strlen(name); i < n; i++)
        {
            if (name[i] == ' ' && secondInit != name[i + 1])
            {
                secondInit = toupper(name[i + 1]);
                printf("%c", secondInit);
            }
            else if (name[i] == ' ' && thirdInit != name[i + 1])
            {
                thirdInit = toupper(name[i + 1]);
                printf("%c", thirdInit);
            }
        }
        printf("\n");
     }
    
    return 0;
}


