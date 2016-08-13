#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop (char s[])
{
	if (strlen(s) == 1 && !isdigit(s[0])) {
		return s[0];
	} else if (strlen(s) >= 1 && (isdigit(s[0]) || isdigit(s[1]))) {
		return NUMBER;
	} else {
		return COMMAND;
	}
}
