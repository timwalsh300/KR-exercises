/* Page 46: Write a function htoi(s) which converts a string of hexadecimal digits
** (including an option '0x' or '0X') into its equivalent integer value. The allowable
** digits are '0' through '9', 'a' through 'f', and 'A' through 'F'
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int htoi(char s[]);

int main(void)
{
	char line[MAXLINE];
	printf("Enter a hexadecimal value: ");
	fgets(line, MAXLINE, stdin);
	line[strcspn(line, "\n")] = 0;
	if (strlen(line) > 0) {
		printf("The integer value is %d\n", htoi(line));
	}
}

int decode_digit(char c);

int htoi(char s[])
{
	int v = 0;
	int i = 0;
	/* skip over leading '0x' or '0X' */
	if (strlen(s) > 2) {
		if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
			i += 2;
		}
	}
	/* convert actual hexadecimal digits */
	for ( ; i < strlen(s); i++) {
		v = 16 * v + decode_digit(s[i]);
	}
	return v;
}

int decode_digit(char c)
{
	switch(c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': case 'A': return 10;
		case 'b': case 'B': return 11;
		case 'c': case 'C': return 12;
		case 'd': case 'D': return 13;
		case 'e': case 'E': return 14;
		case 'f': case 'F': return 15;
		default:  return -1;
	}
}
