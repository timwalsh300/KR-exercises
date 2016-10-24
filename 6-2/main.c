#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "freq.h"

int getch(void);
void ungetch(int);
static int getword(char *, int);
static int isvartype(char *);
static int atfunction(void);
static int incomment, inconst, inpreproc, invarlist, inarray, nprefix;

int main (int argc, char *argv[])
{
	incomment = 0;
	inconst = 0;
	inpreproc = 0;
	invarlist = 0;
	inarray = 0;
	if (argc > 1) {
		nprefix = atoi(argv[1]);
	} else {
		nprefix = 6;
	}
	char word[MAXWORD];
	struct tnode *root = NULL;

	/* read through the input one token at a time and build the tree */
	while (getword(word, MAXWORD) != EOF) {
		if (word[0] == '#') {
			inpreproc = 1;
		} else if (word[0] == '/' && word[1] == '*') {
			incomment = 1;
		} else if (word[0] == '*' && word[1] == '/') {
			incomment = 0;
		} else if (word[0] == '"') {
			inconst = !inconst;
		} else if (word[0] == '[' && !inarray) {
			inarray = 1;
		} else if (word[0] == ']' && inarray) {
			inarray = 0;
		} else if (isvartype(word) && !invarlist) {
			invarlist = 1;
		} else if ((word[0] == ';' || word[0] == '{') && invarlist) {
			invarlist = 0;
		} else if (!incomment && !inpreproc && !inconst && !inarray &&
				invarlist && (islower(word[0]) || word[0] == '_') &&
				!isvartype(word) && !atfunction()) {
			/* insert word into the tree */
			root = addtree(root, word, 0, nprefix);
		}
	}

	/* print the results; traverse in order */
	treeprint(root);
	return 0;
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
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

static int isvartype(char *word)
{
	if (strcmp(word, "int") == 0 || strcmp(word, "char") == 0 ||
			strcmp(word, "float") == 0 || strcmp(word, "double") == 0 ||
			strcmp(word, "struct") == 0 || strcmp(word, "void") == 0 ||
			strcmp(word, "short") == 0 || strcmp(word, "long") == 0) {
		return 1;
	} else {
		return 0;
	}
}

static int atfunction(void)
{
	int c;
	if ((c = getch()) == '(') {
		ungetch(c);
		return 1;
	} else {
		ungetch(c);
		return 0;
	}
}
