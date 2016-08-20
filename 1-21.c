/* Page 34: Write a program entab that replaces strings of
** blanks with by the minimum number of tabs and blanks to
** achieve the same spacing. Use the same tab stops as for
** detab (exercise 1-20). When either a tab or a single
** blank would suffice to reach a tab stop, which one should
** be given preference?
**
** I am giving preference to tabs for the sake of an elegant
** algorithm. This way I don't need to know how many spaces
** the tab is replacing, just that some space or number of
** spaces ran into the next tabstop.
**
** I'm also writing '-' instead of ' ' to the output just
** to be able to see the results of the program.
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100
#define TABSTOP 8

extern int mygetline(char *, int);

void entab(char *, char *, int);

int main(void)
{
	char input[MAXLINE];
	char output[MAXLINE];

	printf("Input a line with a bunch of spaces: ");
	mygetline(input, MAXLINE);
	entab(output, input, TABSTOP);
	printf("Line with tabs and spaces is: %s\n", output);
}

void entab(char *output, char *input, int columns)
{
	int count = 0, tabs = 0, spaces = 0;
	char tabstr[2] = {'\t', '\0'};

	while (*input  != '\0') {
		if (*input == ' ') {
			spaces++;
			count = (count + 1) % columns;
			if (count == 0) {
				strcat(output, tabstr);
				spaces = 0;
			}
		} else {
			for (int i = 0; i < spaces; i++) {
				strcat(output, "-");
			}
			strncat(output, input, 1);
			count = (count + spaces + 1) % columns;
			spaces = 0;
		}
		input++;
	}
}
