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

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // linear search
    bool found = false;
    if (n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if (value == values[i])
            {
                found = true;
            }
        }    
    }
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort
    int itercount = 0;
    int swapcount;
    for(int i = 0; i < n - 1; i++)
    {
        swapcount = 0;
        for(int j = 0; j < n - 1 - itercount; j++)
        {
            if (values[j] > values[j + 1])
            {
                int store = values[j];
                values[j] = values[j + 1];
                values[j + 1] = store;
                swapcount++;
          
            }
        }
        if (swapcount == 0)
        {
            break;
        }
        itercount++;        
    }
    return;
}
