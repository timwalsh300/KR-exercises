#include <stdio.h>
#include "linesort.h"
#define MAXSTORAGE 10000
#define MAXLINES 5000

char *lineptr1[MAXLINES];
char *lineptr2[MAXLINES];

static char storage[MAXSTORAGE];

int main(void)
{
	int nlines = 0;

	printf("\nEnter lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines1(lineptr1, MAXLINES)) >= 0) {
		qsort(lineptr1, 0, nlines - 1);
		printf("\nThe sorted sequence of lines is...\n\n");
		writelines(lineptr1, nlines);
	} else {
		printf("error: input too big to sort\n");
	}

	nlines = 0;
	printf("\nEnter the same lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines2(lineptr2, MAXLINES, storage)) >= 0) {
		qsort(lineptr2, 0, nlines - 1);
		printf("\nThe sorted sequence of lines is...\n\n");
		writelines(lineptr2, nlines);
	} else {
		printf("error: input too big to sort\n");
	}
}
