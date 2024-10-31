%{
#include<stdio.h>
int vow,con;
%}

%%
[a,e,i,o,u,A,E,I,O,U] {vow++;}
[b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z] {con++;}
[B,C,D,F,G,H,J,K,L,M,N,P,Q,R,S,T,V,W,X,Y,Z] {con++;}
%%

int yywrap(){
    return 1;
}

void main(int argc, char* argv[1])
{
yyin = fopen(argv[1],"r");
yylex();
printf("Vowels: %d\n", vow);
printf("Consonants: %d\n", con);
}

//input
/*
abc.txt :
samplelineforvowelcheck
*/