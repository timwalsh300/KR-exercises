#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void)
{
	int *input_as_integer = malloc(sizeof(int));
	int successful;

	printf("Enter an integer: ");
	if (getint(input_as_integer)) {
		printf("Your input was %d\n", *input_as_integer);
	} else {
		printf("Your input was not an integer\n");
	}
}


int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
	if (!isdigit(c)) {
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * (*pn) + (c - '0');
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return 1;
}
