#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

int tokentype;
int staticfun;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

void dcl(void);
void dirdcl(void);
int gettoken(void);
