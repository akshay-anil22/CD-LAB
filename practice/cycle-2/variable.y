%{
#include <stdio.h>
#include <stdlib.h>
%}

%token VALID INVALID

%%

input:
      VALID   { printf("Valid variable\n"); }
    | INVALID { printf("Invalid variable\n"); }
    ;

%%

int main()
{
    printf("Enter a variable: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    return 0;
}

