/* Project: Caesar Ciphers
// Author:	Russ Johnson
 * Date: 2/01/2013
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void readFreq(float given[]);
void calcFreq(float found[]);
int findKey(float given[], float found[]);
void decrypt(int key);

FILE *fin;

int main(int argc, char* argv[])
{

    char ch;
	float given[26];
	float found[26];
    float f;
    int i, count, key;
    float tmp;

    fin = fopen(argv[1], "r");

    readFreq(given);
    printf("1");
    calcFreq(found);
        printf("1");
    key = findKey(given, found);

    printf("1");
    

    rewind(fin);
    while (fscanf(fin,"%c", &ch) != EOF) {
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

int findKey(float given[], float found[]) {
    float sum = 0;
    float min = 0;
    int key,k,i;
    float tmp;
    for (i=0;i<26;i++) {
        tmp = given[i]-found[i];
        min += (tmp<0)? -tmp:tmp;
    }

    k = 1;
    for (k=1;k<26;k++) {
        sum = 0;
        for (i=0;i<26;i++) {
            tmp = given[(i+k)%26]-found[i];
            sum += (tmp<0)? -tmp:tmp;
        }

        if (sum < min) {
            min = sum;
            key = k;
        }
        sum = 0;
    }
    return key;
}

void readFreq(float given[]) {
    float f;
    char ch;
    FILE* letFreq = fopen("LetFreq.txt", "r");
    int i = 0;
    while (fscanf(letFreq, "%c %f\n", &ch, &f) != EOF) {
        given[i] = f;
        i++;
    }
}

void calcFreq(float found[]){
    char ch;
    int count = 0;
    int i;
    while (fscanf(fin,"%c", &ch) != EOF) {
        if (isalpha(ch)) {
            count++;
            if (islower(ch)) {
                found[ch-'a']++;
            }
            else {
                found[ch-'A']++;
            }
        }
    }
    for (i=0;i<26;i++){
        found[i] /= count;
    }
}
