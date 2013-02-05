/* Project: Caesar Ciphers
// Author:	Russ Johnson
 * Date: 2/01/2013
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void readFreq(float*);
void calcFreq(float*);
int findKey(float*, float*);
void decrypt(int key);

int main(int argc, char* argv[])
{

    /*fin encryted file fout decrypted file*/
    FILE *fin;

	float *given = (float*) malloc (26 * sizeof (float));
	float *found = (float*) malloc (26 * sizeof (float));
    char ch;
    float f;
    int i, count, key, k, m;
    float sum = 0;
    float min = 0;
    float tmp;
    key = 0;

    fin = fopen(argv[1], "r");

    FILE* letFreq = fopen("LetFreq.txt", "r");

    if (fin ==  NULL) {
		printf("File could not be opened\n");
		exit(1);
	}

    //initilize found to zero
    for (i=0; i++; i<26) 
        *(found+i) = 0;

    i = 0;
    while (fscanf(letFreq, "%c %f\n", &ch, &f) != EOF) {
        *(given+i) = f;
        i++;
    }

    //add count to found and average based on count
    count = 0;
    while (fscanf(fin, "%c", &ch) != EOF) {
        if (isalpha(ch)) {
            count++;
            if (islower(ch)) {
                (*(found+(ch-'a')))++;
            }
            else {
                (*(found+(ch-'A')))++;
            }
        }
    }

    for (i=0;i<26;i++){
        *(found+i) /= count;
    }


    //find key
    for (i=0;i<26;i++) {
        tmp = *(given+i)-*(found+i);
        min += (tmp<0)? -tmp:tmp;
    }

    k = 1;
    for (k=1;k<26;k++) {
        sum = 0;
        for (i=0;i<26;i++) {
            tmp = *(given+(i+k)%26)-*(found+i);
            sum += (tmp<0)? -tmp:tmp;
        }

        if (sum < min) {
            min = sum;
            key = k;
        }
        sum = 0;
    }

    rewind(fin);

    while (fscanf(fin, "%c", &ch) != EOF) {
        printf("%c",ch);
    }
    
    rewind(fin);

    while (fscanf(fin, "%c", &ch) != EOF) {
        if (isalpha(ch)){
            if (islower(ch))
                printf("%c",((ch-'a'+key)%26)+'a');
            else
                printf("%c",((ch-'A'+key)%26)+'A');
        }
        else
            printf("%c",ch);
    }
                

	fclose(fin);
    fclose(letFreq);

	return 0;

    for (i=0;i<26;i++){
        *(found+i) /= count;
        printf("%f\n",*(found+i));
    }
}
