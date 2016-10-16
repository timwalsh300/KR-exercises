#include <stdio.h>
#include <string.h>
#include "dcl.h"

void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) {
		ns++;
	}
	dirdcl();
	while (ns-- > 0) {
		strcat(out, " pointer to");
	}
}

void dirdcl(void)
{
	int temp;
	char tempstr[MAXTOKEN];

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("error: missing )\n");
		}
	} else if (tokentype == NAME) {
		strcpy(name, token);
	} else {
		printf("error: expected name or (dcl)\n");
	}
	while ((temp = gettoken()) == PARENS || temp == BRACKETS) {
		if (temp == PARENS) {
			if (staticfun) {
				sprintf(tempstr, " static function%s returning", token);
			} else {
				sprintf(tempstr, " function%s returning", token);
			}
			strcat(out, tempstr);
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
