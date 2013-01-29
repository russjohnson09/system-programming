// Project: 	Caesar Ciphers
// Author:	Yonglei Tao

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*Load array given with the letter frequencies for English from file LetFreq.txt */
void readFreq ( float given[] );
 

/* Read the encoded text from an input file and accumulate the letter frequency data for the encoded text. Store the frequency data in array found. */
void calcFreq ( float found[] );

/* Compare the data in array found with the frequency data in array given, looking for a key that will give you the best match. To do this, try each of the 26 rotations, and remember which gives the smallest difference between the frequencies you observed and the frequencies given. Return the key. */
int findKey ( float given[], float found[] );

/* Decrypt the encoded text in the input file using the key and display the decoded text */
void decrypt ( int key );

/**
	Decrypts a character using the Caesar cipher.
	@param key the encryption key
	@return the encrypted character
*/
void decrypt(int key)
{
}
/*
void readFreq(float given[]) {

    char ch;
    float f;

    while (fscanf(fin, "%c", &ch) != EOF) {
        printf("%c",ch);
    }
}
*/

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
