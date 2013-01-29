// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printTime(clock_t,clock_t);

int main ()
{
	const int MaxSize = 25000;
	int i, j, temp;

	clock_t begin1;
    clock_t end1;
    clock_t begin2;
    clock_t end2;

	// Part one: processing a statically allocated array

    begin1 = clock();

	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}

    end1 = clock();


	// Part two: processing a dynamically allocated array

    begin2 = clock();

    int * temp2;
    int * temp3;
    int * temp4;
	int * list;
	list = (int*) malloc (MaxSize * sizeof (int));
	
	for ( i = 0; i < MaxSize; i++ )
        *(list+i) = MaxSize-i;

	for (i=0; i<MaxSize-1; i++) {
		for (j=MaxSize-1; j>i; j--) {
			if (*(list + (j-1)) > *(list + j))
			{
				*temp2 = *(list + (j-1));
				*(list + (j-1)) = *(list + j);
				*(list + j) = *temp2;
			}
        }
    }


	free(list);

    end2 = clock();

	// Display the amount of time used for each part above

    
    printTime(begin1, end1);

    printTime(begin2, end2);


	return 0;
}

void printTime(clock_t begin, clock_t end) {
   printf("Time used: %lf%s\n",(double)(end-begin)/CLOCKS_PER_SEC,
            " seconds");
}


