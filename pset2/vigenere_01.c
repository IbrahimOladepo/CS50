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
        string k = argv[1]; // Second command line arg
        
        // Checking if k is a valid k...
        int check_k = 0;
        int j = 0;
        do
        {
            if (isalpha((int) k[j]) == 0)
                check_k = 1;
            j++;
        }
        while (check_k == 0 && j < strlen(k));
        printf("check is now: %i\n", check_k);
        
        // Making sure valid k is used
        if (check_k == 0)
        {
            printf("Ciphertext: ");
            string p = GetString();
            
            int m = strlen(k);
            printf("Plaintext: ");
            int j_not = 0;
            for (int i = 0, n = strlen(p); i < n; i++)
            {                                                                                                                                                                 
                int j = i % m;
                int k_real[m];
                
                if (isdigit((int) p[i]) || ispunct((int) p[i]) || isspace((int) p[i]))
                {
                    k_real[j] = 0;
                    j_not++;
                }
                
                j = (i - j_not) % m;
                k[j] = toupper(k[j]);
                k_real[j] = k[j] - 65; // Corresponds to 0 to 2
                
                if (isdigit((int) p[i]))
                    printf("%c", p[i]);
                if (ispunct((int) p[i]))
                    printf("%c", p[i]);
                if (isspace((int) p[i]))
                    printf(" ");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
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
