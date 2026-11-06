%{
#include <stdio.h>
#include <string.h>
%}

%%

.*[Aa][Kk][Ss][Hh].*    { printf("String contains 'Aksh' -> Rejected\n"); }
.*                       { printf("String does not contain 'Aksh' -> Accepted\n"); }

%%

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}