#include "table.h"

int main(void)
{
	static struct nlist *table[HASHSIZE];

	/* insert definitions into the table to create
	** several test cases... the head of a list, middle
	** of a list, and the end of a list
	*/
	install(table, "TEST1", "hello");
	install(table, "TEST2", "world");
	install(table, "TEST3", "anna");
	install(table, "TEST4", "rosie");
	install(table, "TEST5", "boston");
	install(table, "TEST6", "washington");
	install(table, "TEST7", "seoul");
	install(table, "TEST8", "hooksett");

	/* call undef to remove some definitions from the table */

	/* print the contents of the table */
	for (int i = 0; i < HASHSIZE; i++) {
		for (struct nlist *p = table[i]; p != NULL; p = p->next) {
			printf("list %d... %s: %s\n", i, p->name, p->defn);
		}
	}

	return 0;
}
