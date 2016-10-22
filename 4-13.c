/* Page 88: Write a recursive version of the function reverse(s) which
** reverses the string s in place.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 10

void reverse(char s[], int, int);

int main(void)
{
	char input[MAXLINE];

	printf("Enter a string to reverse: ");
	fgets(input, MAXLINE, stdin);
	input[strcspn(input, "\n")] = 0;
	reverse(input, 0, strlen(input) - 1);
	printf("The reversed string is: %s\n", input);
}

void reverse(char s[], int left, int right)
{
	if (left >= right) {
		return;
	} else {
		char tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		reverse(s, (left + 1), (right - 1));
	}
}
