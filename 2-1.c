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

}
