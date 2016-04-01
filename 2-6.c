/* Page 49: Write a funtion setbits(x, p, n, y) that returns x with the n bits that
** begin at position p set to the rightmost n bits of y, leaving the other
** bits unchanged. Positioning is like 543210.
*/

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {

	//010101 in binary
	unsigned int input_x = 025;

	//101101 in binary
	unsigned int input_y = 055;

	printf("Running setbit(010101, 4, 2, 101101)\n");
	printf("Result in binary should be 001101 which is 015 in octal\n");
	printf("Actual result in octal is %o\n", setbits(input_x, 4, 2, input_y));
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {

	//create mask 000011 to get rightmost n bits of y
	unsigned int y_mask = ~(~0 << n);
	printf("y_mask = %o\n", y_mask);
	//apply mask to y... 101101 & 000011 = 000001
	unsigned int y_masked = y & y_mask;
	printf("y_masked = %o\n", y_masked);
	//shift rightmost n bits of y to the desired starting position p... 001000
	unsigned int y_masked_and_shifted = y_masked << (p + 1 - n);
	printf("y_masked_and_shifted = %o\n", y_masked_and_shifted);
	//create mask 100111 to erase positions 4 and 3 of x
	unsigned int x_mask = ~((~(~0 << n)) << (p + 1 - n));
	printf("x_mask = %o\n", x_mask);
	//apply mask to x... 010101 & 100111 = 000101
	unsigned int x_masked = x & x_mask;
	printf("x_masked = %o\n", x_masked);
	//combine x_masked with y_masked_and_shifted
	return (x_masked | y_masked_and_shifted);
}

