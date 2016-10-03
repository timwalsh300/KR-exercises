#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "flags.h"
#define MAXLINES 5000

static char *lineptr[MAXLINES];

static int numcmp(const char *, const char *);
static int folded_strcmp(const char *, const char *);

int main(int argc, char *argv[])
{
	int nlines = 0;
	int numeric = 0;
	int reverse = 0;
	int fold = 0;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-n") == 0) {
				numeric = 1;
			} else if (strcmp(argv[i], "-r") == 0) {
				reverse = 1;
			} else if (strcmp(argv[i], "-f") == 0) {
				fold = 1;
			}
		}
	}

	if (fold && numeric) {
		printf("Error: -f and -n flags cannot be used together\n");
		return 1;
	}

	printf("\nEnter lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if (numeric) {
			myqsort((void **) lineptr, 0, nlines - 1,
				(int (*)(const char *, const char *)) numcmp);
		} else if (fold) {
			myqsort((void **) lineptr, 0, nlines - 1,
				(int (*)(const char *, const char *)) folded_strcmp);
		} else {
			myqsort((void **) lineptr, 0, nlines - 1,
				(int (*)(const char *, const char *)) strcmp);
		}
		printf("\n");
		writelines(lineptr, nlines, reverse);
		return 0;
	} else {
		printf("Error: input too big to sort\n");
		return 1;
	}
}

static int numcmp(const char *s1, const char *s2)
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

static int folded_strcmp(const char *s1, const char *s2)
{
	char lower_c1, lower_c2;

	while (*s1 != '\0' && *s2 != '\0') {
		lower_c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + 32 : *s1;
		lower_c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + 32 : *s2;
		if (lower_c1 == lower_c2) {
			s1++;
			s2++;
		} else {
			return lower_c1 - lower_c2;
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
