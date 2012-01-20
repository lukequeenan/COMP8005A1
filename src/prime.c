#include "prime.h"

/* Find out the prime factors
 * of a given number and print
 * them on the screen 
 * Author: Mathias Van Malderen */
void factorize (long n, FILE *file)
{
    long d = 2;
    
    if (n < 2) 
    {
        return;
    }
    
    /* while the factor being tested
     * is lower than the number to factorize */
    while (d < n)
    {
        /* if valid prime factor */
        if (n % d == 0)
        {
            fprintf(file, "%lu x ", d);
            n /= d;
        }
        /* else: invalid prime factor */
        else
        {
            if (d == 2)
            {
                d = 3;
            }
            else
            {
                d += 2;
            }
        }
    }
    
    /* print last prime factor */
    fprintf(file, "%lu\n", d);
}

int prime(char type, long number, long start, long end)
{
    char *name = malloc((sizeof(char) * 9) + sizeof(long));
    FILE *file;
    sprintf(name, "../dmp/%c%lu", type, number);
    if ((file = fopen(name, "a+")) == NULL)
    {
        return -1;
    }
    for (; start < end; start++)
    {
        factorize(start, file);
    }
    fclose(file);
    free(name);
    return 0;
}
