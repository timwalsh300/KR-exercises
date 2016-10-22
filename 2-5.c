/* Page 48: Write a function any(char s1[], char s2[]) that returns the first
** location in s1 where any character from s2 occurs, or -1 if there is no match
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int any(char s1[], char s2[]);

int main(void)
{
	char s1[MAXLINE], s2[MAXLINE];
	printf("Enter string #1: ");
	fgets(s1, MAXLINE, stdin);
	s1[strcspn(s1, "\n")] = 0;
	printf("Enter string #2: ");
	fgets(s2, MAXLINE, stdin);
	s2[strcspn(s2, "\n")] = 0;
	printf("The first position of any match is %d\n", any(s1, s2));
}

int any(char s1[], char s2[])
{
	for (int i = 0; s2[i] != '\0'; i++) {
		for (int j = 0; s1[j] != '\0'; j++) {
			if (s1[j] == s2[i]) {
				return j;
			}
		}
	}
	return -1;
}

