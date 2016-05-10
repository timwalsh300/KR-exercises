/* Page 48: Write a function squeeze(char s1[], char s2[]) that deletes each
** character in s1 that matches any character in s2
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[MAXLINE], s2[MAXLINE];
	printf("Enter string #1: ");
	mygetline(s1, MAXLINE);
	printf("Enter string #2: ");
	mygetline(s2, MAXLINE);
	squeeze(s1, s2);
	printf("String #1 is now %s\n", s1);
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	for (int k = 0; s2[k] != '\0'; k++) {
		for (i = j = 0; s1[i] != '\0'; i++) {
			if (s1[i] != s2[k]) {
				s1[j++] = s1[i];
			}
		}
		s1[j] = '\0';
	}
}
