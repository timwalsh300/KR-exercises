#include <string.h>

static void swap(char *v[], int i, int j);

void myqsort(char *v[], int left, int right,
		int (*comp)(const char *, const char *))
{
	int i, last;

	if (left >= right) {
		return;
	}
	swap(v, left, ((left + right) / 2));
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	myqsort(v, left, last - 1, comp);
	myqsort(v, last + 1, right, comp);
}

static void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

