#include "table.h"

static int getword(char *, int);
int getch(void);
void ungetch(int);
static void collectdef(char *, char *);

int main(void)
{
	static struct nlist *table[HASHSIZE];
	struct nlist *p;
	char word[MAXWORD], temp[MAXWORD], output[MAXINPUTLEN] = "";
	int inliteral = 0;

	while (getword(word, MAXWORD) != EOF) {
		if ((word[0] == '#') && !inliteral) {
			getword(word, MAXWORD);
			if (strcmp(word, "define") == 0) {
				/* call function to collect definition
				** and install it in the table
				*/
				char name[MAXWORD];
				char defn[MAXWORD];
				collectdef(name, defn);
				install(table, name, defn);
			} else {
				/* write #word to the output */
				sprintf(temp, "#%s", word);
				strcat(output, temp);
			}
		} else {
			/* call lookup function and write word or
			** appropriate definition to output
			*/
			if (!inliteral && (p = lookup(table, word)) != NULL) {
				strcat(output, p->defn);
			} else {
				strcat(output, word);
				if (word[0] == '"') {
					inliteral = !inliteral;
				}
			}
		}
	}

	printf("\n\nOutput: \n\n%s\n", output);

	/* print the contents of the table */
	/*
	for (int i = 0; i < HASHSIZE; i++) {
		for (struct nlist *p = table[i]; p != NULL; p = p->next) {
			printf("list %d... %s: %s\n", i, p->name, p->defn);
		}
	}
	*/
	return 0;
}

static void collectdef(char *n, char *d)
{
	int c;
	char temp[MAXWORD];

	while (isspace(c = getch()))
		;
	ungetch(c);

	getword(n, MAXWORD);

	while (isspace(c = getch()))
		;
	ungetch(c);

	while (getword(temp, MAXWORD) != '\n') {
		strcat(d, temp);
	}
}

static int getword(char *word, int lim)
{
	int c;
	char *w = word;

	if ((c = getch()) != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		if (!isalpha(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

