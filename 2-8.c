/* Page 49: Write a function rightrot(x, n) that returns the value of the
** integer x rotated to the right by n bit positions
*/

#include <stdio.h>
#include <stdlib.h>
#include "mygetline.h"
#include "shortbinaryio.h"
#define MAXLINE 17

unsigned short rightrot(unsigned short x, int n);

int main() {

	char input_x[MAXLINE];
	char input_n[MAXLINE];
	char output[MAXLINE];
	printf("Running rightrot(x, n) that returns x rotated\n");
	printf("to the right by n bit positions\n");
	printf("Enter 16-bit x: ");
	mygetline(input_x, MAXLINE);
	printf("Enter n: ");
	mygetline(input_n, MAXLINE);
	dec_to_bin(output, rightrot(bin_to_dec(input_x), atoi(input_n)));
	printf("Result is %s\n", output);
}

unsigned short rightrot(unsigned short x, int n) {

	//reduce n to a manageable size < 16
	int n_reduced = n % 16;

	//move the piece of x being shifted "over the edge" all the way to the left
	unsigned short x_left = x << (16 - n_reduced);

	//shift x to the right discarding bits going "over the edge"
	x >>= n_reduced;

	//combine the previous two results
	return (x | x_left);
}
