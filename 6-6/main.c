#include "table.h"

static int getword(char *, int);
int getch(void);
void ungetch(int);
static void collectdef(struct nlist *t[], char *, char *);

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
				collectdef(table, name, defn);
				install(table, name, defn);
				defn[0] = '\0';
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

	printf("\n\nOutput: \n\n%s\n\n", output);

	/* print the contents of the table */

	for (int i = 0; i < HASHSIZE; i++) {
		for (struct nlist *p = table[i]; p != NULL; p = p->next) {
			printf("list %d... %s: %s\n", i, p->name, p->defn);
		}
	}

	return 0;
}

static void collectdef(struct nlist *t[], char *n, char *d)
{
	int c;
	struct nlist *p;
	char temp[MAXWORD];

	while (isspace(c = getch()))
		;
	ungetch(c);

	getword(n, MAXWORD);

	while (isspace(c = getch()))
		;
	ungetch(c);

	while (getword(temp, MAXWORD) != EOF) {
		if (temp[0] == '\n' && c != '\\') {
			return;
		} else if (temp[0] == '\\' || temp[0] == '\t' || temp[0] == '\n') {
			c = temp[0];
			continue;
		} else {
			if ((p = lookup(t, temp)) != NULL) {
				strcat(d, p->defn);
			} else {
				strcat(d, temp);
			}
			c = temp[0];
		}
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

