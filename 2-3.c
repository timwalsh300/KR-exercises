/* Page 46: Write a function htoi(s) which converts a string of hexadecimal digits
** (including an option '0x' or '0X') into its equivalent integer value. The allowable
** digits are '0' through '9', 'a' through 'f', and 'A' through 'F'
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

int htoi(char s[]);

int main() {

	char line[MAXLINE];
	printf("Enter a hexadecimal value: ");
	//printf("Number of characters input: %d\n", mygetline(line, MAXLINE));
	printf("\nThe integer value is %d\n", htoi(line));
}

int htoi(char s[]) {

	int v = 0;
	
	return v;
}
