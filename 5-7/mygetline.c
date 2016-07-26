#include <stdio.h>

int mygetline(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != '\n'; ++i) {
		line[i] = c;
	}
/*	if (c == '\n') {
		line[i] = c;
		++i;
	}
*/
	line[i] = '\0';
	return i;
}
