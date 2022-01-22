%{
	/*
		2) Write a Lex program to identify 
		a word entered by user is verb or not. 
		- Written By Anshul Verma for
			University of Delhi
	*/
%}

%%
is|am|are|were|do|shall|will {printf("%s is a verb.", yytext);}
[A-Za-z]+ {printf("%s is not a verb.", yytext);}
%%
int main()
{
	printf("Enter a word: ");
	yylex();
	return 1;
}
int yywrap()
{
	return 1;
}
