#include <stdio.h>

int getch();
void ungetch(int c);

int main(void)
{
	char s[100];
	int i = 0;

	printf("Enter a line of text: ");
	while ((s[i] = getch()) != '\n') {
		i++;
	}
	s[i] = '\0';
	printf("Calling ungetch()...\n");;
	ungetch(s[--i]);
	printf("Calling ungetch() again...\n");;
	ungetch(s[--i]);
	i = 0;
	printf("Enter more text: ");
	while ((s[i] = getch()) != '\n') {
		i++;
	}
	s[i] = '\0';
	printf("Available string of input is: %s\n", s);
}
