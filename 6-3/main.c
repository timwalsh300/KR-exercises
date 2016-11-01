#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "freq.h"

int getch(void);
void ungetch(int);
static int getword(char *, int, int *);
static int isblacklisted(char *);
static int binsearch(char *, char list[][10], int);

int main(void)
{
	char word[MAXWORD], temp[MAXWORD];
	struct tnode *root = NULL;
	int line_num = 1;

	/* read through the input one token at a time and build the tree */
	while (getword(word, MAXWORD, &line_num) != EOF) {
		if (isalpha(*word)) {
			int i = 0;
			for ( ; i < strlen(word); i++) {
				temp[i] = tolower(word[i]);
			}
			temp[i] = '\0';
			if (!isblacklisted(temp)) {
				root = addtree(root, temp, line_num);
			}
		}
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

static int isblacklisted(char *word)
{
	char blacklist[][10] =	{"a",
				"all",
				"also",
				"am",
				"an",
				"and",
				"are",
				"as",
				"at",
				"be",
				"by",
				"can",
				"could",
				"couldn't",
				"did",
				"didn't",
				"do",
				"does",
				"doesn't",
				"don't",
				"each",
				"every",
				"few",
				"got",
				"has",
				"have",
				"he",
				"her",
				"hers",
				"him",
				"his,"
				"i",
				"if",
				"in",
				"is",
				"isn't",
				"it",
				"lot",
				"may",
				"me",
				"might",
				"mine",
				"more",
				"much",
				"my",
				"none",
				"not",
				"of",
				"off",
				"on",
				"or",
				"really",
				"said",
				"say",
				"says",
				"she",
				"should",
				"shouldn't",
				"so",
				"that",
				"the",
				"their",
				"there",
				"this",
				"those",
				"they",
				"they're",
				"to",
				"told",
				"very",
				"was",
				"wasn't",
				"we",
				"were",
				"weren't",
				"with",
				"would",
				"you"};

	if (binsearch(word, blacklist, (sizeof(blacklist)/sizeof(*blacklist))) == -1) {
		return 0;
	} else {
		return 1;
	}
}

static int binsearch(char *word, char list[][10], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, list[mid])) < 0) {
			high = mid - 1;
		} else if (cond > 0) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}
