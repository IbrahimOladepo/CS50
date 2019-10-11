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
    // TODO: implement a searching algorithm
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int itercount = 0;
    int swapcount = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int value = values[i];
        for(int j = 1; j < n - itercount; j++)
        {
            if(value > values[j])
            {
                int store = values[j];
                values[j] = value;
                values[j - 1] = store;
                value = values[j];
                swapcount++;
            }
        if(swapcount == 0)
            break;
        itercount++;
        }
    }
    return;
    

}
