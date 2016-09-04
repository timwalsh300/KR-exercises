#include <stdio.h>
#include <stdlib.h>
#include "tail.h"
#define MAXLINES 5000

char *lineptr[MAXLINES];

int main(int argc, char *argv[])
{
	int nlines = 0;
	int print_lines = 10;

	if (argc > 1) {
		print_lines = atoi(argv[1]);
		if (print_lines < 0) {
			print_lines *= -1;
		}
	}

	printf("\nEnter lines of text followed by CTRL-D...\n\n");
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		printf("\nThe last %d lines are...\n\n", print_lines);
		writelines(lineptr, nlines, print_lines);
		printf("\n");
	} else {
		printf("Error: the input was invalid\n");
	}
}
