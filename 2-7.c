/* Page 49: Write a function invert(x, p, n) that returns x with the n bits
** that begin at position p inverted, leaving the others unchanged
**
** compile along with shortbinaryio.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 17

unsigned short bin_to_dec(char in[]);
void dec_to_bin(char output[], unsigned short input);
unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
	char input_x[MAXLINE];
	char input_p[MAXLINE];
	char input_n[MAXLINE];
	char output[MAXLINE];
	printf("Running invert(x, p, n) that returns x with the n bits\n");
	printf("beginning at position p inverted, where\n");
	printf("positioning uses the form 543210.\n\n");
	printf("Enter 16-bit x: ");
	fgets(input_x, MAXLINE, stdin);
	input_x[strcspn(input_x, "\n")] = 0;
	printf("Enter p: ");
	fgets(input_p, MAXLINE, stdin);
	input_p[strcspn(input_p, "\n")] = 0;
	printf("Enter n: ");
	fgets(input_n, MAXLINE, stdin);
	input_n[strcspn(input_n, "\n")] = 0;
	dec_to_bin(output, invert(bin_to_dec(input_x), atoi(input_p), atoi(input_n)));
	printf("Result is %s\n", output);
}

unsigned int invert(unsigned int x, int p, int n)
{
	/* create mask to erase the bits in x that will change */
	unsigned int x_mask = ~(~(~0 << n) << (p + 1 - n));

	/* invert all of x */
	unsigned int x_inverted = ~x;

	/* create mask to erase all but the inverted bits of x we need */
	unsigned int x_inverted_mask = ~x_mask;

	/* combine the two masked bit patterns */
	return ((x & x_mask) | (x_inverted & x_inverted_mask));
}

