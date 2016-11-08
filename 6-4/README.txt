Page 143: Write a program that prints the distinct words of its input
sorted in decreasing order of frequency of occurrence. Precede each word
by its count.

Assumptions...

1. Input will be in a sentence and paragraph style with no more than 10000 tokens
2. Words should be treated in a case-insensitive manner
3. Words will only contain ASCII letters and possibly hyphens or apostrophes 
4. Output should be as follows
	5 cat
	5 hat
	3 in
	2 the
	2 sat
	1 now
	.
	.
	.

Design... There will be a binary search tree to store each word and a running count
of how many times the word has appeared. The tree will be sorted alphabetically. When
inserting a new word/node into the tree, we will also store a pointer to that node in
an array. After reading the through the input and building the complete tree and array,
we will sort the array by word count and print the sorted result.

Analysis... Reading the input and building the tree and array will take O(N*log(N)) time.
Sorting the array will be O(N*log(N)) using quicksort. Printing the results will be O(N),
where N is the number of words in the input. The total time complexity will be O(N*log(N)).

compile with gcc main.c tree.c getch.c qsort.c freq.h

This program has a known issue involving the incompatibility of ASCII and UNICODE character
sets, namely with smart quotes or apostrophes vs single quotes, so for example,
"president's" may be broken into two tokens ("president" and "s") if the text is copied
and pasted from the web as with the provided test case.
