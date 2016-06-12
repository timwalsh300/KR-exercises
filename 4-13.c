/* Page 88: Write a recursive version of the function reverse(s) which
** reverses the string s in place.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mygetline.h"
#define MAXLINE 10

int itob(int n, char s[], int b);

int main(void)
{
	char integer_input_string[MAXLINE];
	char base_string[MAXLINE];
	char output_string[MAXLINE];

	printf("Enter a decimal integer to convert: ");
	mygetline(integer_input_string, MAXLINE);
	printf("Enter the new base: ");
	mygetline(base_string, MAXLINE);
	itob(atoi(integer_input_string), output_string, atoi(base_string));
	printf("The new representation is: %s\n", output_string);
}

void reverse(char s[], int left, int right);

int itob(int n, char s[], int b)
{
	char charset[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = charset[n % b];
	} while ((n /= b) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s, 0, (strlen(s) - 1));
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
