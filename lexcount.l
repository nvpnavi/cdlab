%{
#include<stdio.h>
int ch, wd, ln;
%}

%%
[a-z|A-Z|0-9] {ch++;}
" " {wd++;}
"\n" {ln++,wd++;}
%%

int yywrap(){
    return 1;
}

void main(int argc, char* argv[1])
{
yyin = fopen(argv[1],"r");
yylex();
printf("Characters: %d\n", ch);
printf("Words: %d\n", wd);
printf("Lines: %d\n", ln);
}

//input
/*void main()
{
int position,initial,rate
printf("Hello World");
position=initial+rate*60;
}
void main()
{
int position,initial,rate
printf("Hello World");
position=initial+rate*60;
}
*/