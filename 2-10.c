/* Page 52: Write a function lower(char s[]) which converts upper case letters to lower case
** using a conditional expression, assuming character set is ASCII
*/

#include <stdio.h>
#define MAXLINE 100

int lower(char out[], char s[]);

int main(void)
{
	char input[MAXLINE];
	char converted_input[MAXLINE];
	printf("Enter a string: ");
	fgets(input, MAXLINE, stdin);
	printf("Converted %d characters to lower case\n", lower(converted_input, input));
	printf("Converted string is: %s\n", converted_input);
}

int lower(char out[], char upper[])
{
	int counter = 0;
	int i = 0;
	while(upper[i] != '\0') {
		out[i] = (upper[i] >='A' && upper[i] <='Z') ? (upper[i] + 'a' - 'A') : upper[i];
		if (upper[i] != out[i]) {
			counter++;
		}
		i++;
	}
	out[i] = '\0';
	return counter;
}
