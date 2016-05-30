Page 79: Getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back and implement your
design.

My implementation will simply ignore pushed back EOFs as well as other whitespace
characters like newlines, tabs, spaces, and null characters.

Note: I am breaking the program up into multiple files as shown later in
the book on page 82.

Compile with... gcc main.c getch.c

