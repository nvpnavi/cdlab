%{
#include "y.tab.h"
%}

%%
[0-9]+ { return DIGIT; }
[a-z|A-Z]+ { return LETTER; }
[\t] { ; }
"\n" { return 0; }
. { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}
