/* Page 63: Write a function expand(s1, s2) that expands shorthand notation like
** a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow
** for letters of either case and digits, and be prepared to handle cases like
** a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

int expand(char s1[], char s2[]);

int main() {

	char input[MAXLINE];
	char expanded_input[MAXLINE];
	printf("Enter a shorthand string (e.g. a-z): ");
	mygetline(input, MAXLINE);
	expand(input, expanded_input);
	printf("Expanded string is %s\n", expanded_input);
}

int expand(char s1[], char s2[]) {

	int i = 0;
	int j = 0;
	int expansions = 0;
	while (s1[i] != '\0') {
		if (s1[i] == '-' && s1[i + 1] != '\0' && i != 0) {
			for (char c = s1[i - 1]; c < s1[i + 1]; j++) {
				s2[j] = ++c;
			}
			expansions++;
			i += 2;
		}
		else {
			s2[j++] = s1[i++];
		}
	}
	s2[j] = '\0';
	return expansions;
}
