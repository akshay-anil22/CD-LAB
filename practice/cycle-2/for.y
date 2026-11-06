
%{
#include <stdio.h>
int yylex();
int yyerror(char *s);
%}

%token FOR ID NUM INC DEC RELOP

%%
statement:
    FOR '(' initialization ';' condition ';' update ')' body
    {
        printf("Valid FOR statement\n");
    }
    ;

initialization:
      ID '=' NUM
    | ID '=' ID
    ;

condition:
    ID RELOP NUM
    ;

update:
      ID INC
    | ID DEC
    | INC ID
    | DEC ID
    | ID '=' ID '+' NUM
    | ID '=' ID '-' NUM
    ;

body:
    '{' stmt_list '}'
    ;

stmt_list:
    /* epsilon */
  | expression ';'
  | stmt_list expression ';'
  ;     

expression:
    ID '=' ID '+' NUM
  | ID '=' ID '-' NUM
  | ID INC
  | ID DEC
  | ID '=' NUM
  ;

%%

int main()
{
    printf("Enter FOR statement: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid FOR statement\n");
    return 0;
}
