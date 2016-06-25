/* Page 107: Write the function strend(s,t) which returns 1 if the string
** t occurs at the end of s, and 0 otherwise
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

int strend(char *, char *);

int main(void)
{
	char string1[MAXLINE];
	char string2[MAXLINE];
	printf("Enter the string to search: ");
	mygetline(string1, MAXLINE);
	printf("Enter the target string: ");
	mygetline(string2, MAXLINE);
	if (strend(string1, string2)) {
		printf("Yes, the first string ends with the target string.\n");
	} else {
		printf("No, the first string does not end with the target string.\n");
	}
}

int strend(char *s, char *t)
{
	int length_s = 0;
	int length_t = 0;
	while (*s != '\0') {
		s++;
		length_s++;
	}
	while (*t != '\0') {
		t++;
		length_t++;
	}
	if (length_t > length_s) {
		return 0;
	} else {
		for (int i = length_t - 1; *(--s) == *(--t); i--) {
			if (i == 0) {
				return 1;
			}
		}
	}
	return 0;
}
