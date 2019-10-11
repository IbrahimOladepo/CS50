#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Enter your name:");
    string name = GetString();
    int condition = 0;
    
    //Checking for error by counting the number of characters
    //I'm still gonna delete this block
    int a = 0;
    for(int i = 0,n = strlen(name); i < n; i++)
    {
        a++;
    }
    printf("Number of characters is: %d\n", a);
    
    
    //This loop checks for the validity of the name
    for(int i = 0,n = strlen(name); i < n; i++)
    {
        int a = name[i];
        int x = 46; int y = 45; int z = 39;      
        if (a == x || a == y || a == z)
            condition = 1;
    }
    printf("Condition is: %d\n", condition); 
    
    //This loop prints out the initials
    if (condition == 0)
    {
        for(int i = 0,n = strlen(name); i < n; i++)
        {
            if (i == 0)
            {
                printf("%c", toupper(name[i]));
            }
            else if ((int) name[i-1] == 32)
            {
                printf("%c", toupper(name[i]));
            }
        }   
    }
    printf("\n");   
}
