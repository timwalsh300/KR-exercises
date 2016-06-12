/* Page 91: Define a macro swap(t,x,y) that interchanges two arguments of type t. */

#include <stdio.h>
#define swap(t,x,y) ({	\
	t tmp = x;	\
	x = y;		\
	y = tmp; })

int main(void)
{
	int num1 = 41;
	int num2 = 8;
	printf("num1 is %d and num2 is %d\n", num1, num2);
	printf("running swap macro...\n");
	swap(int, num1, num2);
	printf("now num1 is %d and num2 is %d\n", num1, num2);

	char *str1 = "foo";
	char *str2 = "test";
	printf("str1 is %s and str2 is %s\n", str1, str2);
	printf("running swap macro...\n");
	swap(char*, str1, str2);
	printf("now str1 is %s and str2 is %s\n", str1, str2);
}
