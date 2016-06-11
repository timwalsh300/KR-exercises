/* Page 88: Write a recursive version of itoa, that is converting
* an integer into a string by calling a recursive routine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mygetline.h"
#define MAXLINE 100

void itoa(int n, char s[]);

int main(void)
{
	char integer_input_string[MAXLINE];
	char output_string[MAXLINE];

	printf("Enter an integer: ");
	mygetline(integer_input_string, MAXLINE);
	itoa(atoi(integer_input_string), output_string);
	printf("The new representation is: %s\n", output_string);
}

int itoa_helper(int n, int i, char s[]);

void reverse(char s[]);

void itoa(int n, char s[])
{
	int j = 0;
	int negative = 0;

	if (n < 0) {
		n = -n;
		negative = 1;
	}
	j = itoa_helper(n, 0, s);
	if (negative) {
		s[j++] = '-';
		s[j] = '\0';
	}
	reverse(s);
}

int itoa_helper(int n, int i, char s[])
{
	if (n == 0) {
		s[i] = '\0';
		return i;
	} else {
		s[i++] = '0' + (n % 10);
		n /= 10;
		itoa_helper(n, i, s);
	}
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[j];
		s[j] = s[i];
		s[i] = c;
	}
}
