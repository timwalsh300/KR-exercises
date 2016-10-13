#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 100

extern int getch(void);
extern void ungetch(int);

int gettoken(void);

enum {NAME, PARENS, BRACKETS};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main(void)
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS) {
				strcat(out, token);
			} else if (type == '*') {
				if (gettoken() == NAME) {
					sprintf(temp, "*%s", out);
				} else {
					sprintf(temp, "(*%s)", out);
				}
				strcpy(out, temp);
				for (int i = strlen(token) - 1; i >= 0; i--) {
					ungetch(token[i]);
				}
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else {
				printf("invalid input at %s\n", token);
			}
		}
		printf("%s\n", out);
	}
	return 0;
}

int gettoken(void)
{
	int c;
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); ) {
			*p++ = c;
		}
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
