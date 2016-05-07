#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main() {

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
			case 'p':	printf("top of stack is %.8g\n", peek());
					break;
			case 's':	swap_top_two_elements();
					break;
			case 'd':	duplicate_top_element();
					break;
			case 'c':	clear();
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
