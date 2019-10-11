/**
* vigenere.c
*
* Ibrahim O. Oladepo
*
* Encipher user's input using vigenere 
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
        printf("Improper declaration of arguement.\n");
        return 1;
    }    
    else
    {
        // get line of text
        string k = argv[1];
        
        // check k for validity
        int check_k = 0;
        int j = 0;
        do
        {
            if (isalpha((int) k[j]) == 0)
            {
                check_k = 1;
                printf("Improper key.");
                return 1;
            }
            j++;
        }
        while (check_k == 0 && j < strlen(k));
        
        // Making sure valid k is used
        if (check_k == 0)
        {
            // get line of text
            string p = GetString();
            
            int keylenght = strlen(k);
            int j_not = 0;
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                int j = i % keylenght;
                int k_real[keylenght];
                
                if (isdigit((int) p[i]) || ispunct((int) p[i]) 
                || isspace((int) p[i]))
                {
                    k_real[j] = 0;
                    j_not++;
                }
                
                j = (i - j_not) % keylenght;
                k[j] = toupper(k[j]);
                k_real[j] = k[j] - 65;
                
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
                    int x = p[i] + k_real[j];
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
                    int x = p[i] + k_real[j];
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
