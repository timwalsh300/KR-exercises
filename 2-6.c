/* Page 49: Write a function setbits(x, p, n, y) that returns x with the n bits that
** begin at position p set to the rightmost n bits of y, leaving the other
** bits unchanged. Positioning is like 543210.
**
** compile along with shortbinaryio.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 17

unsigned short bin_to_dec(char in[]);
void dec_to_bin(char output[], unsigned short input);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void)
{
	char input_x[MAXLINE];
	char input_y[MAXLINE];
	char input_p[MAXLINE];
	char input_n[MAXLINE];
	char output[MAXLINE];
	printf("Running setbit(x, p, n, y) that returns x with the n bits\n");
	printf("beginning at position p set to the rightmost n bits of y,\n");
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
	printf("Enter 16-bit y: ");
	fgets(input_y, MAXLINE, stdin);
	input_y[strcspn(input_y, "\n")] = 0;
	dec_to_bin(output, setbits(bin_to_dec(input_x), atoi(input_p), atoi(input_n), bin_to_dec(input_y)));
	printf("Result is %s\n", output);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	//create mask to get rightmost n bits of y
	unsigned int y_mask = ~(~0 << n);
	//apply mask to y
	unsigned int y_masked = y & y_mask;
	//shift rightmost n bits of y to the desired starting position p
	unsigned int y_masked_and_shifted = y_masked << (p + 1 - n);
	//create mask to erase targeted positions of x
	unsigned int x_mask = ~((~(~0 << n)) << (p + 1 - n));
	//apply mask to x
	unsigned int x_masked = x & x_mask;
	//combine x_masked with y_masked_and_shifted
	return (x_masked | y_masked_and_shifted);
}

