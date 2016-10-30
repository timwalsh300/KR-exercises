#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "freq.h"

int getch(void);
void ungetch(int);
static int getword(char *, int, int *);

int main(void)
{
	char word[MAXWORD];
	struct tnode *root = NULL;
	int line_num = 1;

	/* read through the input one token at a time and build the tree */
	while (getword(word, MAXWORD, &line_num) != EOF) {
		root = addtree(root, word, line_num);
	}

	/* print the results; traverse in order */
	treeprint(root);
	return 0;
}

static int getword(char *word, int lim, int *line_num)
{
	int c;
	char *w = word;

	while (isspace(c = getch())) {
		if (c == '\n') {
			(*line_num)++;
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
		if (!isalpha(*w = getch()) && *w != '\'' && *w != '-') {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
