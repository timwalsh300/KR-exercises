#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freq.h"

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s: %d\n", p->word, p->count);
		treeprint(p->right);
	}
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = malloc(sizeof(struct tnode));
		p->word = malloc(strlen(w) + 1);
		p->word = strcpy(p->word, w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		(p->count)++;
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	} else {
		p->right = addtree(p->right, w);
	}
	return p;
}

void freetree(struct tnode *p)
{
	if (p != NULL) {
		freetree(p->left);
		freetree(p->right);
		free(p->word);
		free(p);
		p == NULL;
	}
}
