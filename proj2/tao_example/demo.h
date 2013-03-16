#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void inc();
void dec();
void * producer(void * arg);
void * consumer(void * arg);
