#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop (char s[])
{
	int i, c;
	if (next >= strlen(input)) {
		return EOF;
	}
	while ((s[0] = c = input[next++]) == ' ' || c == '\t')
		;
	i = 0;
	while ((s[++i] = c = input[next++]) != ' ' && c != '\t' && c != '\0')
		;
	s[i] = '\0';
	if (strlen(s) == 1 && !isdigit(s[0])) {
		if (s[0] >= 'a' && s[0] <= 'z') {
			return VARIABLE;
		}
		else { /* arithmetic operator */
			return s[0];
		}
	} else if (strlen(s) >= 1 && (isdigit(s[0]) || isdigit(s[1]))) {
		return NUMBER;
	} else {
		return COMMAND;
	}
}
