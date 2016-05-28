#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}

int ungets(char s[])
{
	int cntr = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] != '\n') {
			ungetch((int) s[i]);
			cntr++;
		}
	}
	return cntr;
}
