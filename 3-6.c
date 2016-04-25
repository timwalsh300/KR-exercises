/* Page 64: Write a version of itoa() from exercise 3-4 that accepts three arguments
** instead of two. The third argument is a minimum field width; the converted number
** must be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define WIDTH 11

void itoa(int n, char s[], int width);

int main() {
	int n = 86112;
	char s[WIDTH];
	printf("Converting %d to a string...\n", n);
	itoa(n, s, WIDTH);
	printf("String is %s\n", s);
}

void reverse(char s[], int length);

void itoa(int n, char s[], int width) {

	int i, sign;
	int max_negative = FALSE;

	if ((sign = n) < 0) {
		if (n == INT_MIN) {
			n++;
			max_negative = TRUE;
		}
		n = -n;
	}

	i = 0;

	do {
		if (i == 0 && max_negative) {
			s[i++] = n % 10 + '0' + 1;
		}
		else {
			s[i++] = n % 10 + '0';
		}
	} while ((n /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';
	}
	while (i < WIDTH) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s, i);
}

void reverse(char s[], int length) {

	int c;
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
