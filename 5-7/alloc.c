#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	/* check if there is free space remaining */
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		/* mark the next free space after this allocation*/
		allocp += n;
		/* return the pointer to this allocated space */
		return allocp - n;
	} else {
		/* not enough room */
		return 0;
	}
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		/* move back to mark the space as free now */
		allocp = p;
	}
}
