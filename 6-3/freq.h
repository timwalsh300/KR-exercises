#define MAXWORD 100
#define MAXTOKENS 10000

struct tnode {
	char *word;
	char *lines;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);

void treeprint(struct tnode *);
