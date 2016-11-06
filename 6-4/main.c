#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "freq.h"

int getch(void);
void ungetch(int);
static int getword(char *, int);

int main(void)
{
	char word[MAXWORD], temp[MAXWORD];
	struct tnode *root = NULL;

	/* read through the input one token at a time and build the tree */
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(*word)) {
			int i = 0;
			for ( ; i < strlen(word); i++) {
				temp[i] = tolower(word[i]);
			}
			temp[i] = '\0';
			root = addtree(root, temp);
		}
	}

	/* copy all the nodes of the tree into an array */

	/* sort the array by word count */

	/* print the contents of the array */

	treeprint(root);
	freetree(root);
	return 0;
}

static int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		if (!isalpha(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
