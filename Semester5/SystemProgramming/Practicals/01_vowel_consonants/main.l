%{
	/*
		1) Write a Lex program to count number of 
		vowels and consonants from text file
		- Written By Anshul Verma for
			University of Delhi
	*/
	#include <stdlib.h>
	int vowel_count=0;
	int const_count =0;
%}

%%
[aeiouAEIOU] {vowel_count++;}
[a-zA-Z] {const_count++;}
%%
int main()
{
	yyin = fopen("input.txt","r");
	yylex();
	printf("\nNumber of vowels: %d\n", vowel_count);
	printf("Number of consonants: %d\n\n", const_count);
	fclose(yyin);
	return 1;
}
int yywrap()
{
	return 1;
}
