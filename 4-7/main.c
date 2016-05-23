#include <stdio.h>

int getch();
void ungetch(int c);
int ungets(char s[]);

int main(void)
{
	char s[100];
	int i = 0;

	printf("Enter a line of text: ");
	while ((s[i] = getch()) != '\n') {
		i++;
	}
	printf("Calling ungets(text)...\n");;
	ungets(s);
	printf("Calling getch() five times...\n");;
	for (int j = 0; j < 5; j++) {
		printf("%c ", getch());
	}
	printf("\n");
}
