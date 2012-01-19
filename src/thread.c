/* System includes */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/* User includes */
#include "thread.h"

/* Local prototypes */
void *runThread();

int startThreads(long numberOfThreads)
{
    pthread_t *threads = malloc(numberOfThreads * sizeof(pthread_t));
    struct timeval *startTime = malloc(numberOfThreads * 
                                       sizeof(struct timeval));
    struct timeval *endTime = malloc(numberOfThreads * sizeof(struct timeval));
    long runTime = 0;
    pthread_attr_t attr;
    long count = 0;
    int result = 0;
    
    /* Create the reusable thread attributes. */
    pthread_attr_init(&attr);
    
    /* Set the thread to joinable (implementation safe) */
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE) != 0)
    {
        /* error */
    }
    
    /* Set the thread for kernel management. This means that system calls will
     not block all threads in the process and that individual threads can be
     assigned to indiviudal processors in the system. */
    if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0)
    {
        /* error */
    }
    
    /* Make the threads and get their start time */
    for (count = 0; count < numberOfThreads; count++)
    {
        gettimeofday(&startTime[count], NULL);
        result = pthread_create(&threads[count], &attr, runThread, 
                                (void *)&endTime[count]);
    }
    
    /* Reclaim some memory */
    pthread_attr_destroy(&attr);
    
    /* Reap the threads as they finish */
    for (count = 0; count < numberOfThreads; count++)
    {
        result = pthread_join(threads[count], NULL);
    }
    
    /* Print results to screen for now */
    for (count = 0; count < numberOfThreads; count++)
    {
        runTime = (endTime[count].tv_sec * 1000000 + endTime[count].tv_usec) -
                    (startTime[count].tv_sec * 1000000
                     + startTime[count].tv_usec);
        printf("Thread %lu runtime: %ld\n", count, runTime);
    }
    
    /* Free memory and return */
    free(threads);
    free(startTime);
    free(endTime);
    
    return 0;
}

void *runThread(void *endTime)
{
    struct timeval *time = endTime;
    
    /* Call the prime number function. */
    
    gettimeofday(time, NULL);
    pthread_exit(NULL);
}
