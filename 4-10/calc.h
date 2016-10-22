#define NUMBER '0'
#define COMMAND '$'
#define VARIABLE '#'
#define MAXLINE 100
#define MAXOP 10
#define TRUE 1
#define FALSE 0

char input[MAXLINE];
int next;

void push(double);
double pop(void);
int getop(char s[]);
double peek(void);
void swap_top_two_elements(void);
void duplicate_top_element(void);
void clear(void);
