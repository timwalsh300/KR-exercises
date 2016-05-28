#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
#define TRUE 1
#define FALSE 0

static int buf;
static int available = FALSE;

int getch(void)
{
	if (available) {
		available = FALSE;
		return buf;
	} else {
		return getchar();
	}
}

void ungetch(int c)
{
	if (available) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf = c;
		available = TRUE;
	}
}
