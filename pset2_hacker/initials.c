#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{   
    string name = GetString();
    
    if (name != NULL)
    {
        for(int i = 0, n = strlen(name); i < n; i++)
        {
            if (isalpha(name[i]))
            {
               if (i == 0 || name[i - 1] == ' ')
                    printf("%c", toupper(name[i]));
            }
            
        }
        printf("\n");
     }
    
    return 0;
}


