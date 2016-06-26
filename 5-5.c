/* Page 107: Write versions of the libary functions strncpy, strncat,
** and strncmp which operate on, at most, the first n characters in
** their argument strings. See descriptions of expected behavior
** in Appendix B page 249.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mygetline.h"
#define MAXLINE 100

char *strncpy(char *, char *, int);
char *strncat(char *, char *, int);
int strncmp(char *, char *, int);

int main(void)
{
	char str1[MAXLINE];
	char str2[MAXLINE];
	char n_input[MAXLINE];
	char selection[MAXLINE];

	printf("Input string 1: ");
	mygetline(str1, MAXLINE);
	printf("Input string 2: ");
	mygetline(str2, MAXLINE);
	printf("Input n: ");
	mygetline(n_input, MAXLINE);
	printf("Select a function:\n");
	printf("1. strncpy, 2. strncat, 3. strncmp\n");
	printf("Selection: ");
	mygetline(selection, MAXLINE);
	switch (atoi(selection)) {
		case (1):	printf("Output of strncpy is ");
				printf("%s\n", strncpy(str1, str2, atoi(n_input)));
				break;
		case (2):	printf("Output of strncat is ");
				printf("%s\n", strncat(str1, str2, atoi(n_input)));
				break;
		case (3):	break;
		default:	printf("%d is not a valid selection\n", atoi(selection));
				break;
	}
}

/* copy first n characters of ct into s */
char *strncpy(char *s, char *ct, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if ((*s++ = *ct++) == '\0') {
			i++;
			break;
		}
	}
	return (s - i);
}

/* concatenate the first n characters of ct onto s */
char *strncat(char *s, char *ct, int n)
{
	int i, j;
	for (j = 0; *s != '\0'; s++, j++)
		;
	for (i = 0; i < n; i++) {
		if ((*s++ = *ct++) == '\0') {
			i++;
			break;
		}
	}
	*s = '\0';
	return (s - j - i);
}


/* compare the first n characters of cs to ct, returning
** <0 if cs < ct, 0 if cs == ct, and >0 if cs > ct
*/
