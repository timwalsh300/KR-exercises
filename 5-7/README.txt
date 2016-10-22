Page 110: Rewrite readlines to store lines in an array supplied by main
rather than calling alloc to maintain storage. How much faster is the
program?

Testing on a small set of 45 lines, I found no consistent performance
difference between the two versions of the program.

compile with... gcc main.c qsort.c lines.c alloc.c linesort.h

enter the EOF signal with CTRL-D after entering the lines to be sorted
