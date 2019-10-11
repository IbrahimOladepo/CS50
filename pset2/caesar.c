/**
* caesar.c
*
* Ibrahim O. Oladepo
*
* Enciphers user's input
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check validity of command-line arguements
    if (argc != 2)
    {
        printf("Improper key.\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]);     
        k = k % 26;
        
        // check k for validity
        if (k > 0)
        {
            // get line of text
            string p = GetString();
            
            // encipher text
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if (isdigit((int) p[i]))
                {
                    printf("%c", p[i]);
                }
                if (ispunct((int) p[i]))
                {
                    printf("%c", p[i]);
                }
                if (isspace((int) p[i]))
                {
                    printf(" "); 
                } 
                if (isupper((int) p[i]))
                {
                    int x = p[i] + k;
                    if (x > 90)
                    {
                        x = x % 90;
                        printf("%c", 64 + x);
                    }
                    else
                        printf("%c", x);
                }
                if (islower((int) p[i]))
                {
                    int x = p[i] + k;
                    if (x > 122)
                    {
                        x = x % 122;
                        printf("%c", 96 + x);
                    }
                    else
                        printf("%c", x);
                }
            }
        }       
        printf("\n");
    }
}
