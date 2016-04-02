/* Page 49: Write a function invert(x, p, n) that returns x with the n bits
** that begin at position p inverted, leaving the others unchanged
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {

	unsigned int input_x = 055;
	printf("Running invert(101101, 3, 2)\n");
	printf("Result should be 100001 which is 041 in octal\n");
	printf("Actual result is %o\n", invert(input_x, 3, 2));
}

unsigned int invert(unsigned int x, int p, int n) {

	//create mask to erase the bits in x that will change
	unsigned int x_mask = ~(~(~0 << n) << (p + 1 - n));

	//invert all of x
	unsigned int x_inverted = ~x;

	//create mask to erase all but the inverted bits of x we need
	unsigned int x_inverted_mask = ~x_mask;

	//combine the two masked bit patterns
	return ((x & x_mask) | (x_inverted & x_inverted_mask));
}

