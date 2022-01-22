
%%
[\t" "]+ {fprintf(yyout," ");}		
.|\n {fprintf(yyout,"%s",yytext);}	
%%

int yywrap(){
	return 1;
}

int main(){
	yyin=fopen("input.txt","r");		
	yyout=fopen("output.txt","w");
	yylex();
	fclose(yyin);
	fclose(yyout);

	return 1;
}