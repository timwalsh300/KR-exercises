/* Page 36: Write a program to determine the ranges of char, short, int, and long variables,
** both signed and unsigned... determine the ranges of the various floating-point types...
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

	printf("\n\nRange numerical data types according to the standard library...\n\n");
	printf("Max char, signed = %d\n", SCHAR_MAX);
	printf("Min char, signed = %d\n", SCHAR_MIN);
	printf("Max char, unsigned = %u\n\n", UCHAR_MAX);
	printf("Max short, signed = %d\n", SHRT_MAX);
	printf("Min short, signed = %d\n", SHRT_MIN);
	printf("Max short, unsigned = %u\n\n", USHRT_MAX);
	printf("Max int, signed = %d\n", INT_MAX);
	printf("Min int, signed = %d\n", INT_MIN);
	printf("Max int, unsigned = %u\n\n", UINT_MAX);
	printf("Max long, signed = %d\n", LONG_MAX);
	printf("Min long, signed = %d\n", LONG_MIN);
	printf("Max long, unsigned = %u\n\n", ULONG_MAX);
	printf("Max float, signed = %e\n", FLT_MAX);
	printf("Min float, signed = %e\n\n", FLT_MIN);
	printf("Max double, signed = %e\n", DBL_MAX);
	printf("Min double, signed = %e\n\n", DBL_MIN);

	printf("\nRange numerical data types, computed...\n\n");
	signed char c;
	/* for some reason, this doesn't work because (c + 1 > 0) evaluates to 'true'
	** even when c = SCHAR_MAX...
	** for (c = 1; c + 1 > 0; c++);
	** printf("Max char, signed = %d\n", c);
	** so we need to keep adding until c < 0 and then decrement before printing
	*/
	for (c = 1; c > 0; c++);
	printf("Max char, signed = %d\n", --c);
	for (c = -1; c < 0; c--);
	printf("Min char, signed = %d\n", ++c);
	/*unsigned char uc;
	for (uc = 0; uc + 1 > 0; uc++);
	printf("Max char, unsigned = %u\n\n", uc);*/

}
