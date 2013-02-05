#include <stdio.h>
#include <string.h>

#define LEN 4

int main()
{
	char line[] = "His textbook was bought from that bookstore";  
	char *p1, *p2;

	//set p1 to the beginning of string line;
    p1 = line;
	
	while (*p1 !='\0') 		// do not go beyond the ‘\0’
	{
		//set p2 to the position immediately after p1
        p2 = p1 + 1;

		while (*p2 != '\0')	// do not go beyond the ‘\0’
		{
			if (strncmp(p1,p2,4) == 0)		// use strncmp()to compare
				goto done;

            //advance p2 to the next position				
            p2++;

		}

		//advance p1 to the next position
        p1++;
	}

done:
    printf ("the first substring: %s\n", p1);
    printf ("the second substring: %s\n", p2);

	return 0;
}
