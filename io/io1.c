#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{  
	int choice, key;
	char ch;
    int i;
    float f;
	FILE *fin, *fout;

	float *list = (float*) malloc (26 * sizeof (float));
    float *tmp;
	
    fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

    tmp = list;
	while ( fscanf(fin, "%c %f\n",&ch, &f) != EOF )
	{
        *tmp = f;
        tmp++;
	}

    for ( i = 0; i < 26; i++)
        fprintf(fout, "%f\n", *(list+i));

	fclose(fin);
	fclose(fout);

	return 0;
}
