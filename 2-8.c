/* Page 49: Write a function rightrot(x, n) that returns the value of the
** integer x rotated to the right by n bit positions
*/

#include <stdio.h>

unsigned short rightrot(unsigned short x, int n);

int main() {

	printf("Running rightrot(0000000101101101, 4)\n");
	printf("Result should be 1101000000010110 which is 0150026 in octal\n");
	printf("Actual result is %o\n", rightrot(0555, 4));
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
