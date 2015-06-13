/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

bool binary_search (int values[], int value, int upper, int lower)
{
        int middle = (lower + upper) / 2;
        
        if (lower > upper)
            return false;
        
        if (values[middle] == value)
            return true;
     
        else if (values[middle] > value)
        {
            //upper = middle - 1;
            if (binary_search(values, value, (middle - 1), lower))
            {
                return true;
            }
        }

        else if (values[middle] < value)
        {
            //lower = middle + 1;
            if (binary_search(values, value, upper, (middle + 1)))
            {
                return true;
            }
        }  
        
        return false;    
}


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implement a binary search that returns true
    // if value is in values, false if not or if n is not positive

    int lower = 0;
    int upper = n - 1;
    
    if (n > 0)
    {
        if (binary_search(values, value, upper, lower))
        {
            return true;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Bubble sort - O(n^2) sorting algorithm
    int counter;
    int temp;
    
    do
    {
        counter = 0;
        
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                temp = values[i];
                values [i] = values[i+1];
                values[i+1] = temp;
                counter++;
            }
        }
    }
    while (counter > 0);
    return;
}

