/* Page 64: The given function itoa(int n, char s[]) converts integer n to string format in s[]
** but it fails to handle the largest negative integer because the range is -2147483648 to
** 2147483647 so we can't simply flip the sign. That produces an overflow. Fix this.
*/

#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

void itoa(int n, char s[]);

int main(void)
{
	int n = -2147483648;
	char s[11];
	itoa(n, s);
	printf("String version of -2147483648 is: %s\n", s);
}

void reverse(char s[], int length);

void itoa(int n, char s[])
{
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
	s[i] = '\0';
	reverse(s, i);
}

void reverse(char s[], int length)
{
	int c;
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
