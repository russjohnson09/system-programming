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

    char ch;
	float *given = (float*) malloc (26 * sizeof (float));
	float *found = (float*) malloc (26 * sizeof (float));
    float f;
    int i, count, key, k, m;
    float sum = 0;
    float min = 0;
    float tmp;
    key = 0;

    readFreq(given);
    calcFreq(found);

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


    while (scanf("%c", &ch) != EOF) {
        printf("%c",ch);
    }
    

    while (scanf("%c", &ch) != EOF) {
        if (isalpha(ch)){
            if (islower(ch))
                printf("%c",((ch-'a'+key)%26)+'a');
            else
                printf("%c",((ch-'A'+key)%26)+'A');
        }
        else
            printf("%c",ch);
    }

	return 0;
}

void readFreq(float* given) {
    float f;
    char ch;
    FILE* letFreq = fopen("LetFreq.txt", "r");
    int i = 0;
    while (fscanf(letFreq, "%c %f\n", &ch, &f) != EOF) {
        *(given+i) = f;
        i++;
    }
}

void calcFreq(float* found){
    char ch;
    int count = 0;
    int i;
    while (scanf("%c", &ch) != EOF) {
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
}
