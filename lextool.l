%{
#include<stdio.h>
int vow,con;
%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern" { printf("Keyword: %s\n",yytext); }
"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct" { printf("Keyword: %s\n",yytext); }
"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" { printf("Keyword: %s\n",yytext); }
[0-9]+   { printf("Number: %s\n",yytext); }
[+*/=><%#] { printf("Operator: %s\n",yytext); }
[{(:"?/,.\)}&|$#;] { printf("Special Characters: %s\n",yytext); }    
[A-Za-z_][A-Za-z0-9_]* { printf("Identifier: %s\n",yytext); }
[ \t\n]+      //Ignore whitespace
.        { printf("Unknown Character: %s\n",yytext); }
%%

int yywrap(){
    return 1;
}

void main(int argc, char* argv[1])
{
yyin = fopen(argv[1],"r");
yylex();
}


//input
/*
void main()
{
int position,initial,rate
printf("Hello World");
position=initial+rate*60;
}
*/