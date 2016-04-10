/* Page 58: Rewrite the given binary search function (which has two tests inside
** a loop) using only one test inside, and measure the difference in runtime
*/

#include <stdio.h>
#include <stdlib.h>
#include "mygetline.h"
#define MAXLINE 10
#define ARRAY_SIZE 45

int binsearch(int x, int v[], int n);

int mybinsearch(int x, int v[], int n);

int main() {

	int array[ARRAY_SIZE];
	char find_string[MAXLINE];
	int find_int;
	int location;

	/* fill an array with the first ARRAY_SIZE fibonacci numbers */
	array[0] = 1;
	array[1] = 1;
	for (int i = 2; i < ARRAY_SIZE; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
	printf("Enter a number to find in the fibonnaci sequence: ");

	mygetline(find_string, MAXLINE);
	find_int = atoi(find_string);

	/* find index and add 1 to make it a natural number */
	if (location = binsearch(find_int, array, ARRAY_SIZE) + 1) {
		printf("Book function... location is %d\n", location); 
	}
	else {
		printf("Not found.\n");
	}
	if (location = mybinsearch(find_int, array, ARRAY_SIZE) + 1) {
		printf("My function... location is %d\n", location); 
	}
	else {
		printf("Not found.\n");
	}
}

/* This is given in the book... find x in v[] where n is the number of elements in v */
int binsearch(int x, int v[], int n) {

	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		}
		else if (x > v[mid]) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1; /* no match found */
}

/* This is my modified function */
int mybinsearch(int x, int v[], int n) {

	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high && v[mid] != x) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	if (v[mid] == x) {
		return mid;
	}
	else {
		return -1; /* no match found */
	}
}

