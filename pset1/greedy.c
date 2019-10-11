#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float change_f;
    int change;
    bool carry = true;
    int counter = 0;
    
    printf("O hai! ");
    // This loop checks if the user input is in not negative
    do
    {
        printf("How much change is owed?\n");
        change_f = GetFloat();
    }
    while (change_f < 0);
    
    change_f = change_f*100; //convert dollar to cent
    change = (int) round(change_f); //changes change to integer
     
    while (carry == true)
    {
        if ((change - 25) >= 0)
        {
            change = change - 25;
            counter = counter + 1;
        }
        else if ((change - 10) >= 0)
        {
            change = change - 10;
            counter = counter + 1;
        }
        else if ((change - 5) >= 0)
        {
            change = change - 5;
            counter = counter + 1;
        }
        else if ((change - 1) >= 0)
        {
            change = change - 1;
            counter = counter + 1;
        }
        else
        {
            carry = false;
        }
    }
    printf("%i\n", counter);
}
