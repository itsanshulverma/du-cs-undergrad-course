%{
	/*
		Write a Lex program that implements the Caesar cipher
		- Written By Anshul Verma for
		  University of Delhi
	*/
	int key = 5;
	int encrypt = 1;
%}

%%
[a-z] {
	char ch = yytext[0];
	if(encrypt){
		ch += key;
		if(ch > 'z')
			ch -= ('z' + 1 - 'a');
	} else {
		ch -= key;
		if(ch < 'a')
			ch +=('z' + 1 - 'a');
	}
	printf("%c",ch);
	yytext[0] = ch;
}

[A-Z] {
	char ch = yytext[0];
	if(encrypt){
		ch += key;
		if(ch > 'Z')
			ch -= ('Z' + 1 - 'A');
	} else {
		ch -= key;
		if(ch < 'A')
			ch +=('Z' + 1 - 'A');
	}
  printf("%c",ch);
	yytext[0] = ch;
}       
%%

int main(){
	int n;
	printf("\nEncrypt(1) or Decrypt(0)? Enter choice: ");
	scanf("%d", &n);
	if(n==0){
		encrypt = 0;
		printf("Enter the encrypted message:\n(Decrypted message will be printed on next line)");
	} else {
		printf("Enter the message:\n(Encrypted message will be printed on next line)");
	}
	yylex();

	return 1;
}
int yywrap(){
	return 1;
}