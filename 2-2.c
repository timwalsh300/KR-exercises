/* Page 42: Write a loop equivalent to the 'for' loop below without using && or ||...
** for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
*/

#include <stdio.h>

int main(void)
{
	char c;
	int lim = 100;
	int i;

	/* This is the example code */
	printf("Type something and press 'enter': ");
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		printf("\n%c", c);
	printf("\n\n");

	/* Here is my solution */
	printf("Now do it again: ");
	i = 0;
	while (i < lim - 1) {
		if ((c = getchar()) != '\n') {
			if (c != EOF) {
				printf("\n%c", c);
				i++;
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}
	printf("\n");
}
