#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "freq.h"

extern int getch(void);
extern void ungetch(int);
static int getword(char *, int);
static int binsearch(char *, struct key *, int);

static struct key keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

int main (void)
{
	int n;
	incomment = 0;
	inconst = 0;
	inpreproc = 0;
	char word[MAXWORD];

	/* read through the input one token at a time and increment results */
	while (getword(word, MAXWORD) != EOF) {
		if (word[0] == '#') {
			inpreproc = 1;
			continue;
		} else if (word[0] == '/' && word[1] == '*') {
			incomment = 1;
			continue;
		} else if (word[0] == '*' && word[1] == '/') {
			incomment = 0;
			continue;
		} else if (word[0] == '"') {
			inconst = !inconst;
		} else if (!incomment && !inpreproc && !inconst) {
			if (isalpha(word[0])) {
				if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
					keytab[n].count++;
				}
			}
		}
	}

	/* print the results */
	for (n = 0; n < NKEYS; n++) {
		if (keytab[n].count > 0) {
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}
	return 0;
}

static int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0) {
			high = mid - 1;
		} else if (cond > 0) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

static int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch())) {
		if (c == '\n' && inpreproc) {
			inpreproc = 0;
		}
	}
	if (c != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
