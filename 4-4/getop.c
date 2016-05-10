#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop (char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}
	i = 0;
	if (isdigit(c) || c == '-') {
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.') {
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if (s[0] == '-' && strlen(s) == 1) {
		ungetch(c);
		return '-';
	}
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}
