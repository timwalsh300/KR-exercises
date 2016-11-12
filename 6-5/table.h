#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 3

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

unsigned int hash(char *s)
{
	unsigned int hashval;

	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

struct nlist *lookup(struct nlist *hashtab[HASHSIZE], char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
}

struct nlist *install(struct nlist *hashtab[HASHSIZE], char *name, char *defn)
{
	struct nlist *np;
	unsigned int hashval;

	if ((np = lookup(hashtab, name)) == NULL) {
		np = malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {
		free(np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL) {
		return NULL;
	}
	return np;
}

int undef(struct nlist *hashtab[HASHSIZE], char *name)
{
	return 0;
}
