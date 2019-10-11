/**
* initials.c
*
* Ibrahim O. Oladepo
*
* Prints out users initials
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get line of text
    string name = GetString();
    int condition = 0;
    
    // check if name is allowed
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if ((int) name[i] == 46 || (int) name[i] == 45 || (int) name[i] == 39)
        {
            condition = 1;
        }
    } 
    
    // print out initials
    if (condition == 0)
    {
        for(int i = 0, n = strlen(name); i < n; i++)
        {
            if (i == 0)
            {
                printf("%c", toupper(name[i]));
            }
            else if ((int) name[i - 1] == 32)
            {
                printf("%c", toupper(name[i]));
            }
        }   
    }
    printf("\n");   
}
