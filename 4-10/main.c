#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

static double last_result;
static int fresh_result = 0;
static double variables[26];

static void parse_line(void);
static void decode_command(char s[]);

int main(void)
{
	next = 0;
	while (fgets(input, MAXLINE, stdin)) {
		input[strcspn(input, "\n")] = 0;
		parse_line();
		next = 0;
	}
	return 0;
}

void parse_line(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:	push(atof(s));
					fresh_result = 0;
					break;
			case '+':	push(pop() + pop());
					fresh_result = 0;
					break;
			case '*':	push(pop() * pop());
					fresh_result = 0;
					break;
			case '-':	op2 = pop();
					push(pop() - op2);
					fresh_result = 0;
					break;
			case '/':	op2 = pop();
					if (op2 != 0.0) {
						push(pop() / op2);
					}
					else {
						printf("error: zero divisor\n");
					}
					fresh_result = 0;
					break;
			case '%':	op2 = pop();
					push((int)pop() % (int)op2);
					fresh_result = 0;
					break;
			case COMMAND:	decode_command(s);
					fresh_result = 0;
					break;
			case VARIABLE:	if (fresh_result) {
						variables[s[0] - 'a'] = last_result;
						printf("%.8g stored in %c\n", variables[s[0] - 'a'], s[0]);
						fresh_result = 0;
					}
					else {
						push(variables[s[0] - 'a']);
					}
					break;
			case '=':	printf("\t%.8g\n", peek());
					last_result = pop();
					fresh_result = 1;
					break;
			case '\n':	break;
			default:	printf("error: unknown command %s\n", s);
					break;
		}
	}
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
	} else if (strcmp(s, "last") == 0) {
		push(last_result);
	} else {
		printf("error: unknown command %s\n", s);
	}
}
