Page 143: Write a cross-referencer that prints a list of all words in a
document, and, for each word, a list of the line numbers on which it occurs.
Remove noise words like "the," "and," and so on.

Assumptions...

1. Input will be in a sentence and paragraph style with no more than 10000 tokens
2. Words should be treated in a case-insensitive manner
3. Words will only contain ASCII letters and possibly hyphens or apostrophes 
4. Each line will end with a newline character
5. Output should be as follows, printing words alphabetically followed by an
ordered list of line numbers
	after 3
	all 4
	binary 1,3
	building 4
	characters 2
	containing 2
	each 1
	in-order 4
	iterate 4
	node 1
	.
	.
	.

Design... There will be a binary tree with each word and a string of 
line numbers where the word is found. The program will take each token and
insert to the binary tree if the word is not in a blacklist (containing constant
strings like "the," "and,"...) along with the line number where it was found, and
simply appending to the list of line numbers if the word is found in the tree. A
line number counter will increment upon reading each newline character. Upon
reaching EOF, the program will print the tree in-order, producing an alphabetically
sorted list.

Running time will be O(N*log(N)) where N is the number of tokens in the input, ignoring
the coefficient in 2N due to reading and writing the whole list. I could do this in O(N)
by using a hash table instead of a binary tree, but then it would not print in alphabetical
order.

Compile with gcc main.c getch.c tree.c freq.h
