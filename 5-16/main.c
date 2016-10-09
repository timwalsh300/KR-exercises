#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "flags.h"
#define MAXLINES 5000

static char *lineptr[MAXLINES];

static int numcmp(const char *, const char *, int, int);
static int mystrcmp(const char *, const char *, int, int);

int main(int argc, char *argv[])
{
	int c;
	int nlines = 0;
	int numeric = 0;
	int reverse = 0;
	int fold = 0;
	int directory_order = 0;

	while (--argc > 0 && **++argv == '-') {
		while (c = *++*argv) {
			switch (c) {
				case 'n': numeric = 1;
						break;
				case 'r': reverse = 1;
						break;
				case 'f': fold = 1;
						break;
				case 'd': directory_order = 1;
						break;
				default: printf("Error: illegal option %c\n", c);
						break;
			}
		}
	}

	printf("\nEnter lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if (numeric) {
			myqsort((void **) lineptr, 0, nlines - 1,
				(int (*)(const char *, const char *, int, int)) numcmp, 0, 0);
		} else {
			myqsort((void **) lineptr, 0, nlines - 1,
				(int (*)(const char *, const char *, int, int)) mystrcmp,
				fold, directory_order);
		}
		printf("\n");
		writelines(lineptr, nlines, reverse);
		return 0;
	} else {
		printf("Error: input too big to sort\n");
		return 1;
	}
}

static int numcmp(const char *s1, const char *s2, int f, int d)
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

static int mystrcmp(const char *s1, const char *s2, int f, int d)
{
	char c1, c2;

	while (*s1 != '\0' && *s2 != '\0') {
		c1 = (*s1 >= 'A' && *s1 <= 'Z' && f) ? *s1 + 32 : *s1;
		c2 = (*s2 >= 'A' && *s2 <= 'Z' && f) ? *s2 + 32 : *s2;
		if (c1 == c2) {
			s1++;
			s2++;
		} else {
			return c1 - c2;
		}
	}
	if (*s1 == '\0' && *s2 != '\0') {
		return -1;
	} else if (*s1 != '\0' && *s2 == '\0') {
		return 1;
	} else {
		return  0;
	}
}
