#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {

	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("error: stack full. can't push\n");
	}
}

double pop(void) {

	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double peek(void) {

	return val[sp - 1];
}

void duplicate_top_element(void) {

	push(peek());
}

void swap_top_two_elements(void) {

	double temp1 = pop();
	double temp2 = pop();
	push(temp1);
	push(temp2);
}

void clear(void) {

	sp = 0;
}
