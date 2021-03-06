#include <stdio.h>
#include <string.h>
#include "flags.h"
#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while (fgets(line, MAXLEN, stdin)) {
		len = strlen(line);
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse)
{
	if (!reverse) {
		for (int i = 0; i < nlines; i++) {
			printf("%s\n", lineptr[i]);
		}
	} else {
		for (int i = nlines - 1; i >= 0; i--) {
			printf("%s\n", lineptr[i]);
		}
	}
}
