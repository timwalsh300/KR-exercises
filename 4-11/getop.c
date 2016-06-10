#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;
	static int ungot = -1;

	while ((s[0] = c = (ungot == -1 ? getch() : ungot)) == ' ' || c == '\t') {
		/* resetting ungot to -1 is like emptying the buffer */
		printf("getop reading %c.\n", c);
		ungot = -1;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-') {
		printf("getop reading %c.\n", c);
		return c;
	}
	i = 0;
	if (isdigit(c) || c == '-') {
		printf("getop reading %c.\n", c);
		while (isdigit(s[++i] = c = getch())) {
			printf("getop reading %c.\n", c);
		}
	}
	if (c == '.') {
		printf("getop reading %c.\n", c);
		while(isdigit(s[++i] = c = getch())) {
			printf("getop reading %c.\n", c);
		}
	}
	s[i] = '\0';
	if (s[0] == '-' && strlen(s) == 1) {
		printf("putting back %c.\n", c);
		ungot = c;
		return '-';
	}
	printf("putting back %c.\n", c);
	/* the following line will set ungot to -1 if c = EOF, like skipping ungetch */
	ungot = c;
	return NUMBER;
}
