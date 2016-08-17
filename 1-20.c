/* Page 34: Write a program detab that replaces tabs in
** the input with the proper number of blanks to space to
** the next tab stop. Assume a fixed set of tab stops, say
** every n columns. Should n be a variable or a symbolic
** parameter/constant?
**
** I think n should be a constant, but the function can handle
** it as a variable. I also put dashes in the output instead of
** spaces so that the results are visible.
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100
#define TABSTOP 8

extern int mygetline(char *, int);

void detab(char *, char *, int);

int main(void)
{
	char input[MAXLINE];
	char output[MAXLINE];

	printf("Input a line with tabs: ");
	mygetline(input, MAXLINE);
	detab(output, input, TABSTOP);
	printf("Line with spaces is: %s\n", output);
}

void detab(char *output, char *input, int columns)
{
	int count = 0;

	while(*input  != '\0') {
		if(*input == '\t') {
			for(int i = 0; i < columns - count; i++) {
				strcat(output, "-");
			}
			count = 0;
		} else {
			strncat(output, input, 1);
			count = (count + 1) % 8;
		}
		input++;
	}
}
