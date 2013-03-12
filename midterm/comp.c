// Simple data-compression program. Assumes ASCII characters.
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MINSIZE     3         // smallest group to compress
#define HIGHBIT  0x80         // high bit indicates compressed char 

int main()  {
  int c, newc, cntc;          

  c = getchar();
  while (c != EOF)  {
    cntc = 1; 
    while (cntc < UCHAR_MAX && (newc = getchar()) == c)
      cntc++;
    if (cntc >= MINSIZE)  {   	// write count (high bit on)
      putchar(c | HIGHBIT);
      putchar(cntc);
    }
    else                     		// write chars (high bit off) 
      while (cntc-- > 0)
        putchar(c);
    c = newc;
  }
  return EXIT_SUCCESS;
}
