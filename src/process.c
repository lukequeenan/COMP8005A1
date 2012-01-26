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
            prime('p', count, 0, 5000);
            gettimeofday(&endTime, NULL);
            printf("%ld\n", (endTime.tv_sec + endTime.tv_usec / 1000000) -
                             (startTime.tv_sec + startTime.tv_usec / 1000000));
            return 0;
        }
        else if (pid == -1)
        {
            /* error in fork */
        }
    }

    return 0;
}
