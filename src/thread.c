/* User includes */
#include "thread.h"
#include "pthread.h"
#include "prime.h"

/* Local prototypes */
void *runThread();

int startThreads(long numberOfThreads)
{
    pthread_t *threads = malloc(numberOfThreads * sizeof(pthread_t));
    struct timeval *startTime = malloc(numberOfThreads * 
                                       sizeof(struct timeval));
    long int *endTime = malloc(numberOfThreads * sizeof(long int));    
    long count = 0;
    int result = 0;
    pthread_attr_t attr;
    
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
                                (void *)count);
    }
    
    /* Reclaim some memory */
    pthread_attr_destroy(&attr);
    
    /* Reap the threads as they finish */
    for (count = 0; count < numberOfThreads; count++)
    {
        result = pthread_join(threads[count], (void*)&endTime[count]);
    }
    
    /* Print results to screen for now */
    for (count = 0; count < numberOfThreads; count++)
    {
        if (endTime[count] == -1)
        {
            printf("Error in Thread\n");
        }
        else
        {
            printf("%ld\n", endTime[count] - (startTime[count].tv_sec +
                                  startTime[count].tv_usec / 1000000));
        }
    }
    
    /* Free memory and return */
    free(threads);
    free(startTime);
    free(endTime);
    
    return 0;
}

void *runThread(void *number)
{
    struct timeval endTime;
    long int time = 0;
    
    /* Make sure there were no errors in the prime function */
    if (prime('t', (long)number, 0, 20000) == -1)
    {
        time = -1;
    }
    else
    {
        gettimeofday(&endTime, NULL);
        time = endTime.tv_sec + endTime.tv_usec / 1000000; 
    }
    
    pthread_exit((void*)time);
}
