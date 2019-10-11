#include <stdio.h>
#include <cs50.h>
#include <string.h>

int* sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int itercount = 0;
    int swapcount;
    for(int i = 0; i < n - 1; i++)
    {
        swapcount = 0;
        for(int j = 0; j < n - 1 - itercount; j++)
        {
            if(values[j] > values[j + 1])
            {
                int store = values[j];
                values[j] = values[j + 1];
                values[j + 1] = store;
                swapcount++;
          
            }
        }
        if(swapcount == 0)
            break;
        itercount++;        
    }
    
    return values;
}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool found = false;
    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(value == values[i])
            {
                found = true;
            }
        }    
    }
    return found;
}

int main(void)
{
    int array[10];
    for(int i = 0; i < 10; i++)
    {
        printf("Enter array value at array[%i]: ", i);
        array[i] = GetInt();
    }
    
    int arrayn[10];
    for(int i = 0; i < 10; i++)
    {
        arrayn[i] = sort(array, 10)[i];
    }
    printf("The sorted array is now: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%i ", arrayn[i]);
    }
    printf("i want to search for %i\n", 4);
    bool check = search(4 , arrayn, 10);
    if(check == true)
    {
        printf("it contains it.");
    }
}
