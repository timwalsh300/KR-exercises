/* Page 64: Write a function itob(n, s, b) which converts an integer n into a base-b
** character representation in the string s. For example, itob(n, s, 16) formats n
** as a hexadecimal string in s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 10

int itob(int n, char s[], int b);

int main(void)
{
	char integer_input_string[MAXLINE];
	char base_string[MAXLINE];
	char output_string[MAXLINE];

	printf("Enter a decimal integer to convert: ");
	fgets(integer_input_string, MAXLINE, stdin);
	printf("Enter the new base: ");
	fgets(base_string, MAXLINE, stdin);
	itob(atoi(integer_input_string), output_string, atoi(base_string));
	printf("The new representation is: %s\n", output_string);
}

void reverse(char s[]);

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
	reverse(s);
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

