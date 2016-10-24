Page 143: Write a program that reads a C program and prints in
alphabetical order each group of variable names that are identical
in the first 6 characters but different somewhere thereafter. Don't
count words within strings and comments. Make a 6 a parameter that
can be set from the command line.

Assumptions...

1. All variables will be preceded by char, int, float, double, long, short,
	struct, or void... they will also start with lowercase letters
2. Since we only care about names, I can fold together variables of 
	the same name but types or different code blocks
3. Output should be as follows, printing each group separated by blanks
	about_
	about_boo
	about_hello
	about_test

	i
	i

	isStri
	isString_boo
	isString_hello
	isString_test
	
	j
	j

	tempSt
	tempStringX
	tempStringY

	.
	.
	.

Design... There will be a binary tree with each node representing a
string of 6 (or however many) characters and containing
its own binary tree of unique strings that start with that string. After
building the trees, we will iterate through all of them in-order.

Running time will be as follows, where A is the number
of groups, and B is the number of strings in the largest group.

(A * B) for each variable * log(A) to traverse the outer binary tree * log(B)
to traverse the inner binary tree + (A * B) to print all the variables, which
simplifies to O(A * log(A) * B * log(B))

compile with gcc main.c getch.c tree.c freq.h
