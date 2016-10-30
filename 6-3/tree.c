#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freq.h"

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s: %s\n", p->word, p->lines);
		treeprint(p->right);
	}
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
	int cond;
	char line_str[MAXWORD];

	if (p == NULL) {
		p = (struct tnode *) malloc(sizeof(struct tnode));
		p->word = (char *) malloc(sizeof(strlen(w) + 1));
		p->lines = (char *) malloc(1000);
		p->word = strcpy(p->word, w);
		sprintf(line_str, "%d", line);
		p->lines = strcpy(p->lines, line_str);
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		sprintf(line_str, ", %d", line);
		p->lines = strcat(p->lines, line_str);
	} else if (cond < 0) {
		p->left = addtree(p->left, w, line);
	} else {
		p->right = addtree(p->right, w, line);
	}
	return p;
}
