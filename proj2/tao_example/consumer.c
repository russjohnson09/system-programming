#include "demo.h"

extern pthread_mutex_t mutex1;		// a mutext variable
extern int  counter;			// shared memory 

void * consumer(void * arg)
{
	int num, i;
	int *p = malloc(sizeof(int));

	num = *(int *)arg;
	for (i=0; i< 20; i++)
	{
		sleep(2);
		dec();
	}

	*p = num;
	return p;
}

void dec()
{
   pthread_mutex_lock( &mutex1 );
   if (counter > 3)
	counter--;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock( &mutex1 );
}
