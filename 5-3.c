/* Page 107: Write a pointer version of the function strcat shown
** chapter 2. strcat(s,t) copies the string t to the end of s
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

int strcat(char *, char *);

int main(void)
{
	char str1[MAXLINE];
	char str2[MAXLINE];

	printf("Enter the first string: ");
	mygetline(str1, MAXLINE);
	printf("Enter the second string: ");
	mygetline(str2, MAXLINE);
	if (strcat(str1, str2)) {
		printf("The concatenated string is %s\n", str1);
	} else {
		printf("Not enough memory allocated for the concatenation\n");
	}
}

int strcat(char *s, char *t)
{
/*	int i, j;
**	i = j = 0;
**	while (s[i] != '\0') {
**		i++;
**	}
**	while ((s[i++] = t[j++]) != '\0')
**		;
*/
	int count = 0;
	for ( ; *s != '\0'; s++) {
		count++;
	}
	for ( ; (*s = *t) != '\0'; s++, t++) {
		if (++count == MAXLINE) {
			return 0;
		}
	}
	return 1;
}
