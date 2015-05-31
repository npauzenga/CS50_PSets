#include <stdio.h>
#include <cs50.h>

// number -> symbol
// user inputs a number, a right-aligned half-pyramid is displayed with 
// a height corresponding to the user's number

int main(void)
{

    int height;
    
    do
    {
        printf("Please enter a number: ");
        height = GetInt();
    } 
    while ((height < 0) || (height > 23));
 
    for (int i = 0; i < height; i++) 
    {
        // print a space height - i times
        for(int j = 1; j < (height - i); j++)
        {
            printf(" ");
        }    
        // print a hash i + 2 times
        for(int k = 0; k < (i + 2); k++)
        {
            printf("#");
        }
        
        printf("  ");
        for(int k = 0; k < (i + 2); k++)
        {
            printf("#");
        }
        
        printf("\n");
    }    
}

