/* System includes */
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

/* User includes */
#include "process.h"

/* Local prototypes */
void runProcess(struct timeval startTime);

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
            runProcess(startTime);
            break;
        }
        else if (pid == -1)
        {
            /* error in fork */
        }
    }

    return 0;
}

void runProcess(struct timeval startTime)
{
    struct timeval endTime;
    
    /* Call function here */
    
    /* Get end time */
    gettimeofday(&endTime, NULL);
    printf("hello from a process!\n");
}
