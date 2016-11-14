#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 100
#define HASHSIZE 101
#define MAXINPUTLEN 100000

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
	struct nlist *p, *temp;
	unsigned int hashval = hash(name);

	if (strcmp(name, hashtab[hashval]->name) == 0) {
		temp = hashtab[hashval];
		hashtab[hashval] = temp->next;
		free(temp->name);
		free(temp->defn);
		free(temp);
		return 1;
	}
	temp = hashtab[hashval];
	p = temp->next;
	while (p != NULL) {
		if (strcmp(name, p->name) == 0) {
			temp->next = p->next;
			free(p->name);
			free(p->defn);
			free(p);
			return 1;
		}
		temp = p;
		p = p->next;
	}
	return 0;
}
