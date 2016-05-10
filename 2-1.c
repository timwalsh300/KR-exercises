/* Page 36: Write a program to determine the ranges of char, short, int, and long variables,
** both signed and unsigned... determine the ranges of the various floating-point types...
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("\n\nRange of numerical data types according to the standard library...\n\n");
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

	printf("\nRange of numerical data types, computed...\n\n");
	signed char c;
	/* for some reason, this code doesn't work because (c + 1 > 0) evaluates to 'true'
	** even when c = SCHAR_MAX...
	** for (c = 1; c + 1 > 0; c++);
	** printf("Max char, signed = %d\n", c);
	** so we need to keep adding until c < 0 and then decrement before printing...
	*/
	for (c = 1; c > 0; c++);
	printf("Max char, signed = %d\n", --c);
	for (c = -1; c < 0; c--);
	printf("Min char, signed = %d\n", ++c);
	unsigned char uc;
	for (uc = 1; uc > 0; uc++);
	printf("Max char, unsigned = %u\n\n", --uc);

	signed short s;
	for (s = 1; s > 0; s++);
	printf("Max short, signed = %d\n", --s);
	for (s = -1; s < 0; s--);
	printf("Min short, signed = %d\n", ++s);
	unsigned short us;
	for (us = 1; us > 0; us++);
	printf("Max short, unsigned = %u\n\n", --us);

	signed int i;
	for (i = 1; i > 0; i++);
	printf("Max int, signed = %d\n", --i);
	for (i = -1; i < 0; i--);
	printf("Min int, signed = %d\n", ++i);
	unsigned int ui = 0;
	//for (ui = 1; ui > 0; ui++);
	//printf("Max int, unsigned = %u\n\n", --ui);
	printf("Max int, unsigned = %u\n\n", (ui - 1));

	signed long l;
	for (l = 1; l > 0; l++);
	printf("Max long, signed = %d\n", --l);
	for (l = -1; l < 0; l--);
	printf("Min long, signed = %d\n", ++l);
	unsigned long ul = 0;
	//for (ul = 1; ul > 0; ul++);
	//printf("Max long, unsigned = %u\n\n", --ul);
	printf("Max long, unsigned = %u\n\n", (ul - 1));
}
