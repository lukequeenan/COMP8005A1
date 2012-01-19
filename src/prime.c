/* Find out the prime factors
 * of a given number and print
 * them on the screen 
 * Author: Mathias Van Malderen */
void factorize(int n)
{
    int d = 2;
    
    if(n < 2) return;
    
    /* while the factor being tested
     * is lower than the number to factorize */
    while(d < n) {
        /* if valid prime factor */
        if(n % d == 0) {
            printf("%d x ", d);
            n /= d;
        }
        /* else: invalid prime factor */
        else {
            if(d == 2) d = 3;
            else d += 2;
        }
    }
    
    /* print last prime factor */
    printf("%d\n", d);
}