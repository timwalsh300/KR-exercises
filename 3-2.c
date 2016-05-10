/* Page 60: Write a function escape(s, t) that converts tabs and newlines into
** visible escape sequences like '\t' and '\n' as it copies the string from t
** to s using a switch. Write a function for the other direction as well.
*/

#include <stdio.h>
#include "mygetline.h"
#define MAXLINE 100

void make_escapes_visible(char s[], char t[]);

void make_escapes_invisible(char s[], char t[]);

int main(void)
{
	char t1[MAXLINE], s1[MAXLINE], t2[MAXLINE], s2[MAXLINE];
	printf("Enter string with tabs in it: ");
	mygetline(t1, MAXLINE);
	make_escapes_visible(s1, t1);
	printf("With visible escape characters that is: %s\n", s1);

	printf("Enter string with \\t characters: ");
	mygetline(t2, MAXLINE);
	make_escapes_invisible(s2, t2);
	printf("Without visible escape characters that is: %s\n", s2);
}

void make_escapes_visible(char s[], char t[])
{
	int j = 0;
	for (int i = 0; t[i] != '\0'; i++, j++) {
		switch (t[i]) {
			case '\t': s[j] = '\\';
				   s[++j] = 't';
				   break;
			default: s[j] = t[i];
		}
	}
	s[j] = '\0';
}

void make_escapes_invisible(char s[], char t[])
{
	int j = 0;
	for (int i = 0; t[i] != '\0'; i++, j++) {
		switch (t[i]) {
			case '\\': switch (t[i + 1]) {
					case 't': s[j] = '\t';
						  i++;
						  break;
					default: s[j] = t[i];
						 break;
				   }
				   break;
			default: s[j] = t[i];
				 break;
		}
	}
	s[j] = '\0';
}

