Page 79: Given getch from the calculator program, write a routine ungets()
that pushes an entire string back onto the input.

ungets() should not have access to buf and bufp, only ungetch() because
otherwise I would just be duplicating the functionality of ungetch() inside
ungets()

Note: I am breaking the program up into multiple files as shown later in
the book on page 82.

Compile with... gcc main.c getch.c

