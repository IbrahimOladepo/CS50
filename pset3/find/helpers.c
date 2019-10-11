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
    int start = 1;
    int end = n;
    int middle = (start + end) / 2;
    int iter = 0;
    
    while(middle != 0)
    {
        if (value == values[middle - 1])
        {
            found = true;
        }
        else if (value > values[middle - 1])
        {
            start = middle + 1;
            middle = (start + end) / 2;
        }
        else
        {
            end = middle - 1;
            middle = (start + end) / 2;
        }
        
        if (start == end && value != values[middle - 1])
        {
            middle = 0;
        }
        else if (start == end && value == values[middle - 1])
        {
            found = true;
            middle = 0;
        }
        iter++;
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
