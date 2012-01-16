/* System includes */
#include <pthread.h>

/* User includes */
#include "thread.h"

/* Local prototypes */
void *run(void *threadId);

int startThreads(long numberOfThreads)
{
    pthread_t threads[numberOfThreads];
    long count = 0;
    int result = 0;
    
    for (count = 0; count < numberOfThreads; count++)
    {
        result = pthread_create(&thread[count], NULL, run, (void *)count);
    }
    
    pthread_exit(NULL);
}

void *run(void *threadId)
{
    /* Call the prime number function. */
    
    pthread_exit(NULL);
}
