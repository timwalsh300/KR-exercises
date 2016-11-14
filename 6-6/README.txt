Page 145: Implement a simple version of the #define
processor (i.e. no arguments) suitable for use with
C programs, based on the routines of this section.

Approach... Read tokens of the input one-by-one, calling
the lookup function each time to see if that token has
been defined. If so, append the definition to an output
array of char. If not, append the original token to the
output. If we encounter a #define token, call another
function that saves the next token (as the name), as well
as everything following the name (the definition) in the lookup
table until we reach a newline character that is not immediately
preceded by a \. While saving the definition, continue to lookup 
each token in the table and replace with previous definitions
as appropriate.
