/* Page 73: Extend atof on page 71 to handle scientific notation of
** the form 123.45e-6 where a floating point number may be followed
** by e or E and an optionally signed exponent
*/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]);

int main(void)
{
	char input_string[MAXLINE];
	printf("Enter a number of the form XX.XX or X.Xe-XX: ");
	fgets(input_string, MAXLINE, stdin);
	printf("The float version is %f\n", atof(input_string));
}

double atof(char s[])
{
	double val, power;
	int i, sig_sign, exp;
	int negative_exp = 0;
	for (i = 0; isspace(s[i]); i++)
		;
	sig_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
		for (power = 1.0; isdigit(s[i]); i++) {
			val = 10.0 * val + (s[i] - '0');
			power *= 10.0;
		}
	}
	val = sig_sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		if (s[i] == '-') {
			negative_exp = 1;
			i++;
		}
		//parse the digits after e/E
		for (exp = 0; isdigit(s[i]); i++) {
			exp = 10 * exp + (s[i] - '0');
		}
		//10 ^ e/E
		power = 1.0;
		for (int k = 0; k < exp; k++) {
			power *= 10.0;
		}
		//multiply or divide significand by (10 ^ e/E)
		if (negative_exp) {
			val /= power;
		}
		else {
			val *= power;
		}
	}

	return val;
}
