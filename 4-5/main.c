#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100

void decode_command(char s[]);

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:	push(atof(s));
					break;
			case '+':	push(pop() + pop());
					break;
			case '*':	push(pop() * pop());
					break;
			case '-':	op2 = pop();
					push(pop() - op2);
					break;
			case '/':	op2 = pop();
					if (op2 != 0.0) {
						push(pop() / op2);
					}
					else {
						printf("error: zero divisor\n");
					}
					break;
			case '%':	op2 = pop();
					push((int)pop() % (int)op2);
					break;
			case COMMAND:	decode_command(s);
					break;
			case '=':	printf("\t%.8g\n", pop());
					break;
			case '\n':	break;
			default:	printf("error: unknown command %s\n", s);
					break;
		}
	}
	return 0;
}

void decode_command(char s[])
{
	if (strcmp(s, "peek") == 0) {
		printf("top of stack is %.8g\n", peek());
	} else if (strcmp(s, "swap") == 0) {
		swap_top_two_elements();
	} else if (strcmp(s, "dup") == 0) {
		duplicate_top_element();
	} else if (strcmp(s, "clear") == 0) {
		clear();
	} else if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	} else if (strcmp(s, "cos") == 0) {
		push(cos(pop()));
	} else if (strcmp(s, "tan") == 0) {
		push(tan(pop()));
	} else if (strcmp(s, "exp") == 0) {
		push(exp(pop()));
	} else if (strcmp(s, "pow") == 0) {
		double temp = pop();
		push(pow(pop(), temp));
	} else if (strcmp(s, "sqrt") == 0) {
		push(sqrt(pop()));
	} else {
		printf("error: unknown command %s\n", s);
	}
}
