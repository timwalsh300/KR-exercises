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
		printf("shifting everything to the right and inserting negative sign\n");
		for (int k = j; k >= 0; k--) {
			s[k + 1] = s[k];
		}
		s[0] = '-';
	}
}

int itoa_helper(int n, int i, char s[])
{
	int j, m;
	if (n == 0) {
		printf("inserting NULL CHAR at index %d\n", i);
		s[i] = '\0';
		return i;
	} else {
		m = n % 10;
		n /= 10;
		j = itoa_helper(n, (i + 1), s);
		printf("inserting %c at index %d\n", '0' + m, (j - i - 1));
		s[j - i - 1] = '0' + m;
		return j;
	}
}
