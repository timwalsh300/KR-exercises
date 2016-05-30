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
	if (c == EOF || c == '\0' || c == '\n' || c == '\t' || c == ' ') {
		printf("White space pushed back... doing nothing\n");
	} else if (available) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf = c;
		available = TRUE;
	}
}
