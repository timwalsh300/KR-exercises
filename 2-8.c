/* Page 49: Write a function rightrot(x, n) that returns the value of the
** integer x rotated to the right by n bit positions
**
** compile along with shortbinaryio.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 17

unsigned short bin_to_dec(char in[]);
void dec_to_bin(char output[], unsigned short input);
unsigned short rightrot(unsigned short x, int n);

int main(void)
{
	char input_x[MAXLINE];
	char input_n[MAXLINE];
	char output[MAXLINE];
	printf("Running rightrot(x, n) that returns x rotated\n");
	printf("to the right by n bit positions\n");
	printf("Enter 16-bit x: ");
	fgets(input_x, MAXLINE, stdin);
	input_x[strcspn(input_x, "\n")] = 0;
	printf("Enter n: ");
	fgets(input_n, MAXLINE, stdin);
	input_n[strcspn(input_n, "\n")] = 0;
	dec_to_bin(output, rightrot(bin_to_dec(input_x), atoi(input_n)));
	printf("Result is %s\n", output);
}

unsigned short rightrot(unsigned short x, int n)
{
	/* reduce n to a manageable size < 16 */
	int n_reduced = n % 16;

	/* move the piece of x being shifted "over the edge" all the way to the left */
	unsigned short x_left = x << (16 - n_reduced);

	/* shift x to the right discarding bits going "over the edge" */
	x >>= n_reduced;

	/* combine the previous two results */
	return (x | x_left);
}
