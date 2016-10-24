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
		p = (struct tnode *) malloc(sizeof(struct tnode));
		p->word = (char *) malloc(sizeof(strlen(w) + 1));
		if (!inside) {
			p->word = strncpy(p->word, w, nprefix);
			p->inner = addtree(p->inner, w, 1, nprefix);
		} else {
			p->word = strcpy(p->word, w);
			p->inner = NULL;
		}
		p->left = p->right = NULL;
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
