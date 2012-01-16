/* System includes */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* User includes */
#include "thread.h"
#include "process.h"

/* Defines */
#define DEFAULT_WORKERS 5

/* Prototypes */
void usage(char *name);

/* Implementation */
int main (int argc, char **argv)
{
    int option = 0;
    long numberOfWorkers = DEFAULT_WORKERS;
    
    while ((option = getopt(argc, argv, "p:t:")) != -1)
    {
        switch (option)
        {
            case 'p':
                numberOfWorkers = atol(optarg);
                printf("Spawning %d processes\n", numberOfWorkers);
                /* call process program here*/
                break;
            case 't':
                numberOfWorkers = atol(optarg);
                printf("Spawning %d threads\n", numberOfWorkers);
                /* call thread program here*/
                break;
            case '?':
            default:
                usage(argv[0]);
        }
    }
    
    return 0;
}

void usage(char *name)
{
    fprintf(stderr, "Usage: %s -p [number of processes to spawn] -t [number of"
            " threads to spawn]\n", name);
}
