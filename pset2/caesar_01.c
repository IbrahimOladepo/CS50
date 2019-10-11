#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
        return 1;
    else
    {
        int k = atoi(argv[1]); // Second command line arg
        
        k = k % 26;
        printf("Smallest k is: %d\n", k);
        // The above does the wrapping around of k and gives the smallest k
        
        // Checking if k is a valid key
        if (k > 0)
        {
            printf("Enter text to be encrypted: ");
            string p = GetString();
            
            // loop to encipher the text....
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if (isdigit((int) p[i]))
                    printf("%c", p[i]);
                if (ispunct((int) p[i]))
                    printf("%c", p[i]);
                if (isspace((int) p[i]))
                    printf(" ");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
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
