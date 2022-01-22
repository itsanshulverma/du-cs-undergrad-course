%{
	/*
		2) Write a Lex program to count the number of 
		integers, operators, keywords, floats, identifiers, comments 
		in a c program
		- Written By Anshul Verma for
			University of Delhi
	*/
	#include <stdlib.h>
	int count_int = 0;
	int count_op = 0;
	int count_keywrd = 0;
	int count_float = 0;
	int count_id = 0;
	int count_comment = 0;
	int count_multicomment = 0;
%}

%%
#include|main|printf|scanf {;}
([<][A-Za-z]*.h[>]) {;}
(["'][a-zA-Z: %\\n]*["']) {;}
[(){};,&\n\ ] {;}
[0-9]+ { count_int++;}
\+|\-|\+\+|\*|\/|\-\-|=|==|%|^|<|>|<=|>=|!=|&&|\|\||!|&|~|\||<<|>> { count_op++;}
(void|int|float|double|string|return|bool|char|for|if|do|else|while|exit"("[0-9]+")"|case|break|continue|goto|switch|enum|struct|sizeof) { count_keywrd++;}

([0-9]+.[0-9]+) { count_float++;}
[_a-zA-Z]+[_a-zA-Z0-9]* { count_id++;}
"//".*[\n] { count_comment++;}
"/*".*"*/" { count_multicomment++;}
%%

int main(){
	yyin = fopen("input.c","r");
	yylex();
	printf("\n=============== 'input.c' ==============\n");
	printf("No. of integers: %d\n", count_int);
	printf("No. of operators: %d\n", count_op);
	printf("No. of keywords: %d\n", count_keywrd);
	printf("No. of floats: %d\n", count_float);
	printf("No. of identifiers: %d\n", count_id);
	printf("No. of single-line comments: %d\n", count_comment);
	printf("No. of multi-line comments: %d\n\n", count_multicomment);
	fclose(yyin);
	return 1;
}
int yywrap(){
	return 1;
}