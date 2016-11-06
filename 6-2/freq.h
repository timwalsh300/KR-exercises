#define MAXWORD 100

struct tnode {
	char *word;
	struct tnode *inner;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int, int);

void treeprint(struct tnode *);

void freetree(struct tnode *);
