/* Page 118: Modify the programs entab and detab (from exercises
** 1-20 and 1-21) to accept a list of tab stops as arguments. Use
** the default tab settings if there are no arguments.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100
#define TABSTOP 8

void detab(char *, char *, int, int, char **);
void entab(char *, char *, int, int, char **);

int main(int argc, char *argv[])
{
	char selection[MAXLINE], input[MAXLINE], output[MAXLINE];

	printf("Choose detab or entab (d/e): ");
	fgets(selection, MAXLINE, stdin);
	selection[strcspn(selection, "\n")] = 0;
	if (strcmp(selection, "d") == 0) {
		printf("Input a line with tabs: ");
		fgets(input, MAXLINE, stdin);
		input[strcspn(input, "\n")] = 0;
		detab(output, input, TABSTOP, argc, argv);
		printf("Output with spaces is: %s\n", output);
	} else if (strcmp(selection, "e") == 0) {
		printf("Input a line with spaces: ");
		fgets(input, MAXLINE, stdin);
		input[strcspn(input, "\n")] = 0;
		entab(output, input, TABSTOP, argc, argv);
		printf("Output with tabs is: %s\n", output);
	} else {
		printf("%s is not a valid selection.\n", selection);
	}
}

void detab(char *output, char *input, int default_tabstop, int num_custom, char *custom_tabstops[])
{
	int char_count = 0, tabstop_count = 0;
	int tabstop;

	while (*input  != '\0') {
		tabstop = tabstop_count < num_custom - 1 ? atoi(custom_tabstops[tabstop_count + 1]) : default_tabstop;
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

void entab(char *output, char *input, int default_tabstop, int num_custom, char *custom_tabstops[])
{
	int char_count = 0, tabstop_count = 0, tabs = 0, spaces = 0;
	int tabstop;
	char tabstr[2] = {'\t', '\0'};

	while (*input  != '\0') {
		tabstop = tabstop_count < num_custom - 1 ? atoi(custom_tabstops[tabstop_count + 1]) : default_tabstop;
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
