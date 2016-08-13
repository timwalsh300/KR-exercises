Page 118: Write a program that evaluates a reverse Polish
expression from the command line, where each operator or
operand is a separate argument. For example...
"2 3 4 + *" evaluates 2 x (3 + 4)

Note: I am building this using the solution from exercise 4-5,
so you have to put a '=' at the end to get some output, which
allows the 'peek' and 'swap' commmands to function properly

I also replaced the '*' operator with 'x' because '*' caused
weird behavior, sending the output of 'ls' in the current
directory through the program...

Compile with... gcc calc.h getop.c main.c stack.c -lm

