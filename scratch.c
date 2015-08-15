#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
    char* word = "NaTe";
    char lowerWord[strlen(word)];
    
    for(int i = 0, j = strlen(word); i <= j; i ++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    printf("%s", lowerWord);
    
    return 0;

}
