#include "freq.h"

static void swap(struct tnode *v[], int i, int j);

void myqsort(struct tnode *v[], int left, int right)
{
	int i, last;

	if (left >= right) {
		return;
	}
	swap(v, left, ((left + right) / 2));
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i]->count > v[left]->count) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	myqsort(v, left, last - 1);
	myqsort(v, last + 1, right);
}

static void swap(struct tnode *v[], int i, int j)
{
	struct tnode *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

