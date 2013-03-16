#include "demo.h"

extern pthread_mutex_t mutex1;		// a mutext variable
extern int  counter;			// shared memory 

void * producer(void * arg)
{
	int num, i;
	int *p = (int*) malloc(sizeof(int));

	num = *(int *)arg;
	for (i=0; i< 20; i++)
	{
		sleep(1);
		inc();
	}
	
	*p = num;
	return p;
}

void inc()
{
   pthread_mutex_lock( &mutex1 );
   if (counter < 8)
   	counter++;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock( &mutex1 );
}
