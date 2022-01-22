%{
#include<stdio.h>
etern int yylex();
%}
%token digit letter
%%
stmt:A
     ;
A: letter B
 ;
B: digit
 ;
%%
void main(){
	printf("enter string \n");
	yyparse();
	printf("valid");
	exit(0);
}
void yyerror()
{
printf("invalid");
exit(0);
}
