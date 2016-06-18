#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main(void)
{
	float *input_as_float = malloc(sizeof(float));
	int successful;

	printf("Enter a floating point number: ");
	if (getfloat(input_as_float)) {
		printf("Your input was %f\n", *input_as_float);
	} else {
		printf("Your input was not a floating point number\n");
	}
}


int getfloat(float *pn)
{
	int c, sign, pow;
	int dec_point_captured = 0, dec_places = 0;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
	if (!isdigit(c) && c != '.') {
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
		if (c == '.') {
			dec_point_captured = 1;
		} else {
			*pn = 10 * (*pn) + (c - '0');
			if (dec_point_captured) {
				dec_places++;
			}
		}
	}

	pow = 1;
	for (int k = 0; k < dec_places; k++) {
		pow *= 10;
	}
	*pn /= pow;

	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return 1;
}
