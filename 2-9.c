/* Page 51: In a two's complement number system, x & (x - 1) deletes
** the rightmost 1-bit in x. Use this observation to write a fast
** routine which counts the number of 1-bits in an integer
*/

#include <stdio.h>
#include <stdlib.h>
#include "mygetline.h"
#include "shortbinaryio.h"
#define MAXLINE 17

int bitcount(unsigned short x);

int main(void)
{
	char decimal_string[MAXLINE];
	int decimal_int;
	char binary_string[MAXLINE];

	printf("Enter an integer: ");
	mygetline(decimal_string, MAXLINE);
	decimal_int = atoi(decimal_string);
	dec_to_bin(binary_string, decimal_int);
	printf("In binary that is %s\n", binary_string);
	printf("Number of 1-bits is %d\n", bitcount(decimal_int));
}

int bitcount(unsigned short x)
{
	int counter = 0;
	while (x != 0) {
		x &= (x - 1);
		counter++;
	}
	return counter;
}
