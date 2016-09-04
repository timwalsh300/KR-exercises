/* Page 118: Extend the entab/detab program to accept the
** shorthand -m +n to mean tabstops every n columns, starting
** at column m. Choose convenient (for the user) default
** behavior.
**
** I will also have the user select entab or detab as the
** first command line argument, either -e or -d
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100
#define TABSTOP 8

extern int mygetline(char *, int);

void detab(char *, char *, int, int, int);

void entab(char *, char *, int, int, int);

int main(int argc, char *argv[])
{
	char selection[MAXLINE], input[MAXLINE], output[MAXLINE] = {'\0'};
	int tabs_start, custom_tabstop;

	strcpy(selection, argv[1]);
	/* ex. get '5' from '-5' or '+5' */
	tabs_start = atoi(argv[2]);
	if (tabs_start < 0) {
		tabs_start *= -1;
	}
	custom_tabstop = atoi(argv[3]);
	if (custom_tabstop < 0) {
		custom_tabstop *= -1;
	}

	if (strcmp(selection, "-d") == 0) {
		printf("Input a line with tabs: ");
		mygetline(input, MAXLINE);
		detab(output, input, TABSTOP, tabs_start, custom_tabstop);
		printf("Output with spaces is: %s\n", output);
	} else if (strcmp(selection, "-e") == 0) {
		printf("Input a line with spaces: ");
		mygetline(input, MAXLINE);
		entab(output, input, TABSTOP, tabs_start, custom_tabstop);
		printf("Output with tabs is: %s\n", output);
	} else {
		printf("%s is not a valid selection.\n", selection);
	}
}

void detab(char *output, char *input, int default_tabstop, int tabs_start, int custom_tabstop)
{
	int char_count = 0, tabstop_count = 0;
	int tabstop;

	while (*input  != '\0') {
		tabstop = ((tabstop_count * default_tabstop) + char_count) < tabs_start ? default_tabstop : custom_tabstop;
		if (char_count == tabstop) {
			tabstop_count++;
			char_count == 0;
		}
		if (*input == '\t') {
			for (int i = 0; i < tabstop - char_count; i++) {
				strcat(output, "-");
			}
			char_count = 0;
			tabstop_count++;
		} else {
			strncat(output, input, 1);
			char_count = (char_count + 1) % tabstop;
			if (char_count == 0) {
				tabstop_count++;
			}
		}
		input++;
	}
}

void entab(char *output, char *input, int default_tabstop, int tabs_start, int custom_tabstop)
{
	int char_count = 0, tabstop_count = 0, tabs = 0, spaces = 0;
	int tabstop;
	char tabstr[2] = {'\t', '\0'};

	while (*input  != '\0') {
		tabstop = ((tabstop_count * default_tabstop) + char_count) < tabs_start ? default_tabstop : custom_tabstop;
		if (char_count == tabstop) {
			tabstop_count++;
			char_count == 0;
		}
		if (*input == ' ') {
			spaces++;
			char_count = (char_count + 1) % tabstop;
			if (char_count == 0) {
				strcat(output, tabstr);
				spaces = 0;
				tabstop_count++;
			}
		} else {
			for (int i = 0; i < spaces; i++) {
				strcat(output, "-");
			}
			spaces = 0;
			strncat(output, input, 1);
			char_count = (char_count + 1) % tabstop;
			if(char_count == 0) {
				tabstop_count++;
			}
		}
		input++;
	}
}
