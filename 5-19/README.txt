Page 126: Modify the undcl program so that it does not add
redundant parentheses to declarations.

Input function declarations such as "x is a function returning
a pointer to an array of pointers to functions returning char"
like this... x () * [] * () char

compile with gcc main.c undcl.c getch.c undcl.h
