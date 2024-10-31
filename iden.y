%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT LETTER;

%%
stmt: A;
A: LETTER B;
B: | LETTER B | DIGIT B;
%%

void main()
{
    printf("ENTER THE STRING : ");
    yyparse();
    printf("valid\n");
    exit(0);
}

void yyerror()
{
    printf("invalid\n");
    exit(0);
}
