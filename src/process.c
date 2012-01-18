/* System includes */
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

/* User includes */
#include "process.h"

/* Local prototypes */
void runProcess(long starttime);

int startProcesses(long numberOfProcesses)
{
    int pid = 0;
    int count = 0;
    struct timeval startTime;
    
    for (count = 0; count < numberOfProcesses; count++)
    {
        /* Get time before fork */
        gettimeofday(&startTime, NULL);
        if ((pid = fork()) == 0)
        {
            runProcess(startTime.tv_sec * 1000000 + startTime.tv_usec);
            break;
        }
        else if (pid == -1)
        {
            /* error in fork */
        }
    }

    return 0;
}

void runProcess(long startTime)
{
    struct timeval endTime;
    long runTime = 0;
    
    /* Call function here */
    
    /* Get end time */
    gettimeofday(&endTime, NULL);
    runTime = (endTime.tv_sec * 1000000 + endTime.tv_usec) - startTime;
    printf("hello from a process!\n");
}
