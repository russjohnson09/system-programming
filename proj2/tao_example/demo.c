#include "demo.h"

/* a mutex variable to ensure correct access to shared memory */
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

/* memory shared by both threads */
int counter = 0;

int main()
{
   int rc1, rc2;
   int x = 1, y = 2;
   pthread_t thread1, thread2;

   /* create two threads, each runing a different function */

   if( (rc1=pthread_create( &thread1, NULL, producer, &x)) )
   {
      printf("Thread creation failed: %d\n", rc1);
   }

   if( (rc2=pthread_create( &thread2, NULL, consumer, &y)) )
   {
      printf("Thread creation failed: %d\n", rc2);
   }

   /* wait till each thread is complete before main continues */

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL); 

   printf("\nValue of the Counter is %d\n", counter);

   return 0;
}

