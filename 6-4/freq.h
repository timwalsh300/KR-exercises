#define MAXWORD 100
#define MAXTOKENS 10000

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *);

void freetree(struct tnode *);
