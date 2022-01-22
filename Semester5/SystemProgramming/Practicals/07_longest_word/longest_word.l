%{
	/*
		7) Write a Lex program that finds the longest word in the input.
		- Written By Anshul Verma for
		  University of Delhi
	*/
	#include<stdio.h>
	#include<stdlib.h>
  #include<string.h>
  int longest = 0;
  int x=0;
  char longWord[20][100];  
%}
%%
[a-zA-Z]+  { 
	          if(yyleng > longest){
	          	memset(longWord, 0, sizeof longWord);
	          	x=0;
	          	longest = yyleng;
	          	
	          	strcpy(longWord[x],yytext);

	          }

	          else if(yyleng == longest){
	          	strcpy(longWord[++x],yytext);
	          }

			}
%%
int main(){
	printf("\nInput : ");
	yylex();

	printf("Length of longest word : %d\n",longest);
	printf("Longest word : ");
	for (int i = 0; i <=x; i++) {
    printf("%s", longWord[i]);
  }
	printf("\n\n");
       
	return 1;
}

int yywrap(){
	return 1;
}
