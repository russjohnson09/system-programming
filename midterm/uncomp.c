// Simple uncompress program.

#include <stdio.h>
#include <stdlib.h>

#define HIGHBIT   0x80    // high bit on indicates compressed char 
int getCount(int c);

int main()  {
  int c;
  int cntc;               

  while ((c = getchar()) != EOF && (cntc = getCount(c)) != 0)
    while (cntc-- > 0)
      putchar(c & ~HIGHBIT);

  return EXIT_SUCCESS;
}

int getCount(int c)  {    // determine # of times to write char 

  if (! (c & HIGHBIT))
    return 1; 		    // once - not compressed 
                       
  return ((c = getchar()) == EOF) ? 0 : c;
}
