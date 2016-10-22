/* Page 71: Write the function strrindex(s, t) which returns the
** position of the rightmost occurrence of t in s, or -1 if there is none
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int strrindex(char s[], char t[]);

int main(void)
{
	char target_string[MAXLINE];
	char search_string[MAXLINE];
	int found;
	printf("Enter a string: ");
	fgets(target_string, MAXLINE, stdin);
	printf("Enter a substring to find: ");
	fgets(search_string, MAXLINE, stdin);
	search_string[strcspn(search_string, "\n")] = 0;
	found = strrindex(target_string, search_string);
	if (found == -1) {
		printf("Substring does not exist\n");
	}
	else {
		printf("Rightmost occurrence begins at index %d\n", found);
	}
}

int strrindex(char s[], char t[])
{
	int i = strlen(s) - strlen(t);
	for ( ; i >= 0; i--) {
		for (int j = 0, k = i; s[k] == t[j]; j++, k++) {
			if ((j + 1) == strlen(t)) {
				return i;
			}
		}
	}
	return -1;
}
