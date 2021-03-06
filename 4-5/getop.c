#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop (char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	i = 0;
	while ((s[++i] = c = getch()) != ' ' && c != '\t' && c != '\n')
		;
	if (c != '\n') {
		ungetch(c);
	}
	s[i] = '\0';
	if (strlen(s) == 1 && !isdigit(s[0])) {
		return s[0];
	} else if (strlen(s) >= 1 && (isdigit(s[0]) || isdigit(s[1]))) {
		return NUMBER;
	} else {
		return COMMAND;
	}
}
