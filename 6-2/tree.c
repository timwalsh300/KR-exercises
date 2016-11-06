#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freq.h"

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->inner);
		treeprint(p->right);
	}
}

struct tnode *addtree(struct tnode *p, char *w, int inside, int nprefix)
{
	int cond;

	if (p == NULL) {
		p = malloc(sizeof(struct tnode));
		if (!inside) {
			p->word = malloc(nprefix + 1);
			p->word = strncpy(p->word, w, nprefix);
			p->left = p->right = NULL;
			p->inner = addtree(p->inner, w, 1, nprefix);
		} else {
			p->word = malloc(strlen(w) + 1);
			p->word = strcpy(p->word, w);
			p->inner = p->left = p->right = NULL;
		}
	} else if ((cond = strncmp(w, p->word, nprefix)) == 0) {
		if(strcmp(w, p->word) != 0) {
			p->inner = addtree(p->inner, w, 1, nprefix);
		}
	} else if (cond < 0) {
		p->left = addtree(p->left, w, inside, nprefix);
	} else {
		p->right = addtree(p->right, w, inside, nprefix);
	}
	return p;
}

void freetree(struct tnode *p)
{
	if (p != NULL) {
		freetree(p->left);
		freetree(p->inner);
		freetree(p->right);
		free(p->word);
		free(p);
		p == NULL;
	}
}
