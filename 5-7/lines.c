#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linesort.h"
#define MAXLEN 1000

int readlines1(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	clock_t begin, end;
	int clock_started = 0;

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0) {
		if (!clock_started) {
			begin = clock();
			clock_started = 1;
		}
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	end = clock();
	clock_started = 0;
	printf("\n\nRunning time for version 1 was %g\n\n", (double) (end - begin));
	return nlines;
}

int readlines2(char *lineptr[], int maxlines, char *storagep)
{
	int len, nlines;
	char *p, line[MAXLEN];
	clock_t begin, end;
	int clock_started = 0;

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0) {
		if (!clock_started) {
			begin = clock();
			clock_started = 1;
		}
		if (nlines >= maxlines) {
			return -1;
		} else {
			p = storagep;
			storagep += len;
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	end = clock();
	clock_started = 0;
	printf("\n\nRunning time for version 2 was %g\n\n", (double) (end - begin));
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++) {
		printf("%s\n", lineptr[i]);
	}
}

