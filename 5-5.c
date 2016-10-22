/* Page 107: Write versions of the libary functions strncpy, strncat,
** and strncmp which operate on, at most, the first n characters in
** their argument strings. See descriptions of expected behavior
** in Appendix B page 249.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100

char *mystrncpy(char *, char *, int);
char *mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

int main(void)
{
	char str1[MAXLINE];
	char str2[MAXLINE];
	char n_input[MAXLINE];
	char selection[MAXLINE];
	int result;

	printf("Input string 1: ");
	fgets(str1, MAXLINE, stdin);
	str1[strcspn(str1, "\n")] = 0;
	printf("Input string 2: ");
	fgets(str2, MAXLINE, stdin);
	str2[strcspn(str2, "\n")] = 0;
	printf("Input n: ");
	fgets(n_input, MAXLINE, stdin);
	printf("Select a function:\n");
	printf("1. mystrncpy, 2. mystrncat, 3. mystrncmp\n");
	printf("Selection: ");
	fgets(selection, MAXLINE, stdin);
	switch (atoi(selection)) {
		case (1):	printf("Output of mystrncpy is ");
				printf("%s\n", mystrncpy(str1, str2, atoi(n_input)));
				break;
		case (2):	printf("Output of mystrncat is ");
				printf("%s\n", mystrncat(str1, str2, atoi(n_input)));
				break;
		case (3):	result = mystrncmp(str1, str2, atoi(n_input));
				if (result < 0) {
					printf("%s < %s\n", str1, str2);
				} else if (result == 0) {
					printf("%s == %s\n", str1, str2);
				} else {
					printf("%s > %s\n", str1, str2);
				}
				break;
		default:	printf("%d is not a valid selection\n", atoi(selection));
				break;
	}
}

/* copy first n characters of ct into s */
char *mystrncpy(char *s, char *ct, int n)
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
char *mystrncat(char *s, char *ct, int n)
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
int mystrncmp(char *cs, char *ct, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (*cs == *ct) {
			cs++;
			ct++;
			continue;
		} else {
			return (*cs - *ct);
		}
	}
	return 0;
}
