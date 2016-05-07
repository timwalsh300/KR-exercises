Page 79: Given the same calculator program in exercise 4-3, add commands
to print the top element of the stack without popping, to duplicate it,
and to swap the top two elements. Add a command to clear the stack.

Commands are as follows:
'p' = peek
'd' = duplicate
's' = swap
'c' = clear

Now entering '=' will pop the result

Note: I am breaking the program up into multiple files as shown later in
the book on page 82.

Compile with... gcc calc.h getch.c getop.c main.c stack.c

