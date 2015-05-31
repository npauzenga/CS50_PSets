#include <stdio.h>
#include <cs50.h>

// user enters cc#, app reports it's validity, and it's type if
// it is valid

int main(void)
{
    int oddEven = 1;
    int rightDigit;
    int numbersToMultiply;
    int numbersToAdd = 0;
    int ccDigitOne = 0;
    int ccDigitTwo = 0;

    printf("Please enter your card number: ");
    long long int cardNumber = GetLongLong();

    // reverse the digits in cardNumber
    while(cardNumber != 0)
    {
        rightDigit = cardNumber % 10;
        
        // if this is even repetition of the loop, multiply the digit
        // by 2 and add the sum of the product's digits to numbersToAdd
        if (oddEven % 2 == 0)
        {   
            ccDigitTwo = rightDigit;   
            rightDigit = rightDigit * 2;

            while(rightDigit != 0)
            {         
                numbersToAdd += rightDigit % 10;
                rightDigit = rightDigit / 10;
            }
        }
        
        // otherwise add the odd repetitions together
        else
        {
            ccDigitOne = rightDigit;
            numbersToAdd += rightDigit;
        }
             
        cardNumber = cardNumber / 10;

        oddEven++;
    }
    
    if (numbersToAdd % 10 == 0)
    {
        if (ccDigitOne == 5 || ccDigitTwo == 5)
        {
            // if first digits are 51, 52, 53, 54, or 55 return MasterCard
            printf("MASTERCARD\n");
        }
        else if (ccDigitOne == 3 || ccDigitTwo == 3)
        {
            // if first digits are 34 or 37 return Amex
            printf("AMEX\n");
        }
        else if(ccDigitOne == 4 || ccDigitTwo == 4)
        {
            // if first digit is 4, return visa
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else 
    {
        printf("INVALID\n");
    }
      
    return 0;
}
