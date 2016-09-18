#include <stdio.h>
#include <string.h>
#include "flags.h"
#define MAXLINES 5000

static char *lineptr[MAXLINES];

static int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int nlines = 0;
	int numeric = 0;
	int reverse = 0;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-n") == 0) {
				numeric = 1;
			} else if (strcmp(argv[i], "-r") == 0) {
				reverse = 1;
			}
		}
	}

	printf("\nEnter lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort((void **) lineptr, 0, nlines - 1,
			(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		printf("\n");
		writelines(lineptr, nlines, reverse);
		return 0;
	} else {
		printf("Error: input too big to sort\n");
		return 1;
	}
}

static int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 > v2) {
		return -1;
	} else if (v1 > v2) {
		return 1;
	} else {
		return 0;
	}
}
