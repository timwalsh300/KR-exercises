#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"

extern int getch(void);
extern void ungetch(int);

int main(void)
{
	while (gettoken() != EOF) {
		if (strcmp(token, "static") == 0) {
			staticfun = 1;
		} else {
			staticfun = 0;
			strcpy(datatype, token);
		}
		if (gettoken() == NAME) {
			strcat(datatype, " ");
			strcat(datatype, token);
		} else {
			for (int i = strlen(token) - 1; i >= 0; i--) {
				ungetch(token[i]);
			}
		}
		out[0] = '\0';
		dcl();
		if (tokentype != '\n') {
			gettoken();
			printf("syntax error before token %s\n", token);
			while ((tokentype = gettoken()) != '\n')
				;
			*datatype = '\0';
			continue;
		}
		printf("%s: %s %s\n", name, out, datatype);
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
		} else if (isalnum(c)) {
			*p++ = '(';
			for (*p++ = c; (*p++ = getch()) != ')'; )
				;
			*p = '\0';
			return tokentype = PARENS;
		} else {
			ungetch(c);
			*p++ = '(';
			*p = '\0';
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
		*p++ = c;
		*p = '\0';
		return tokentype = c;
	}
}
