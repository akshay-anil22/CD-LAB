%{
#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9]*    { return VALID; }
[ \t\n]                 ;
.                       { return INVALID; }

%%

int yywrap()
{
    return 1;
}