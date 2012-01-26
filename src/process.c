/* System includes */
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

/* User includes */
#include "process.h"
#include "prime.h"

int startProcesses(long numberOfProcesses)
{
    int pid = 0;
    long count = 0;
    struct timeval startTime;
    struct timeval endTime;
    
    for (count = 0; count < numberOfProcesses; count++)
    {
        /* Get time before fork */
        gettimeofday(&startTime, NULL);
        
        /* Fork, run process, print time, exit */
        if ((pid = fork()) == 0)
        {
            if (prime('p', count, 0, 50000) == -1)
            {
                printf("Error in Process\n");
            }
            else
            {
                gettimeofday(&endTime, NULL);
                printf("%ld\n", (endTime.tv_sec * 1000000 + endTime.tv_usec) -
                       (startTime.tv_sec * 1000000 + startTime.tv_usec));                
            }

            return 0;
        }
        else if (pid == -1)
        {
            /* error in fork */
        }
    }

    return 0;
}
