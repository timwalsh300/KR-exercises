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

Design... There will be a binary tree to store word and a running count
of how many times the word has appeared. The tree will be sorted alphabetically.
After reading the through the input and building the complete tree, each node
in the tree will be copied into an array and the array will be sorted by word
count. The program will then iterate through the sorted array to print the results.

Analysis... Reading the input and building the binary tree will take O(N*log(N)) time.
Copying the tree into an array will be O(N). Sorting the array will be O(N*log(N))
using quicksort. Printing the results will be O(N), where N is the number of words in
the input. The total time complexity will be O(N*log(N)).
