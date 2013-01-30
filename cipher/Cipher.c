/* Project: Caesar Ciphers
// Author:	Russ Johnson
 * Date: 2/01/2013
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cipher.h"

int main(int argc, char* argv[])
{

    /*fin encryted file fout decrypted file*/
    FILE *fin, *fout;

    float given[26];
    float found[26];
    char ch;

    fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

    if (fin ==  NULL || fout == NULL) {
		printf("File could not be opened\n");
		exit(1);
	}

    while (fscanf(fin, "%c", &ch) != EOF) {
        printf("%c", ch);
    }

//    readFreq(given);

	fclose(fin);
	fclose(fout);

	return 0;
}


char decrypt(int key,char ch)
{
	if (isupper(ch))
		return (ch - 'A' - key) % 26 + 'A';

	if (islower(ch))
		return (ch - 'a' - key) % 26 + 'a';

	return ch;
}


void readFreq(FILE* fin) {

    char ch;
    float f;

    while (fscanf(fin, "%c", &ch) != EOF) {
        printf("%c",ch);
    }
}
