/**
* mario.c
*
* Ibrahim O. Oladepo
*
* Prints out mario-like pyramid 
*/


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int pyraheight;
    int pyrawidth;
    bool condition = false;
    
    // check validity of user input
    do
    {
        printf("Height: ");
        pyraheight = GetInt();
        
        if (pyraheight >= 0 && pyraheight < 24)
        {
            condition = true;
        }
    }
    while (condition == false);
    pyrawidth = pyraheight + 1;
    
    // print pyramid
    for (int row = 1; row <= pyraheight; row++)
    {
        for (int column = 1; column <= pyrawidth; column++)
        {
            if (column == pyrawidth) 
            {
                printf("#\n");
            }
            else if (column >= (pyrawidth - row))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
