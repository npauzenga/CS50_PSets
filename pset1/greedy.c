#include <stdio.h>
#include <math.h>
#include <cs50.h>

/*
//asks user how much change is owed
// returns the minimum number of coins with which change can be made
// Coins available - .25, .10, .05, .01
*/
int main(void)
{
    // global vars
    int coins = 0;
    float Change;

    do
    {
        printf("Please enter your change owed: \n");
        Change = GetFloat();
    }
        while(Change < 0.0);

    // convert ChangeOwed to int
    int ChangeOwed = round(Change * 100);
    
    while(ChangeOwed > 0)
    {  
        // if change owed is greater than 25
        // change owed / 25 rounded to whole number = coins
        // change owed = change owed mod 25 
        if (ChangeOwed >= 25)
        {
            coins = round(ChangeOwed / 25);
            ChangeOwed = ChangeOwed % 25;
        }
        
        // else if change owed is greater than 10
        // change owed / 10 rounded to whole number = coins
        // change owed = change owed mod 10
        else if(ChangeOwed >= 10)
        {
            coins += round(ChangeOwed / 10);
            ChangeOwed = ChangeOwed % 10;
        }
        
        // else if change owed is greater than 5
        // change owed / 5 rounded to whole number = coins
        // change owed = change owed mod 5
        else if(ChangeOwed >= 5)
        {
            coins += round(ChangeOwed / 5);
            ChangeOwed = ChangeOwed % 5;
        }
        
        // else if change owed is greater than 1
        // change owed / 1 rounded to whole number = coins
        // change owed = change owed mod 1
        else if(ChangeOwed >= 1)
        {
            coins += round(ChangeOwed / 1);
            ChangeOwed = ChangeOwed % 1;
        }
     }
    
    // print coins and \n
    printf("%i\n", coins);
    
}
