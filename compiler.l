%{
    #include<stdio.h>
%}

%%
[a-z|A-Z]* {
    for(int i=0; i<=yyleng; i++){
        if((yytext[i]=='a')&&(yytext[i+1]=='b')&&(yytext[i+2]=='c')){
            yytext[i]='A';
            yytext[i+1]='B';
            yytext[i+2]='C';
        }
    }
    printf("%s\n", yytext);
}
%%

int yywrap(){
    return 1;
}

int main(){
    yyin = fopen("input.txt", "r");
    yylex();

    return 0;
}
