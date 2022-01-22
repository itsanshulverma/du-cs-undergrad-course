%{
	#include <stdlib.h>
	int num=0, hex=0;
	int i, r;
%}
%%
[01]+ {
	hex = 0;
	i = 1;
	num = atoi(yytext);
	while(num != 0){
		r = num%10;
		hex = hex + r*i;
		i = i*2;
		num = num/10;
	}
	if (hex >=10) {
		if (hex == 10) printf("Hex value - A");
		if (hex == 11) printf("Hex value - A");
		if (hex == 12) printf("Hex value - A");
		if (hex == 13) printf("Hex value - A");
		if (hex == 14) printf("Hex value - A");
		if (hex == 15) printf("Hex value - A");
	}
	else
		printf("Hex value - %d", hex);
}
%%
int main()
{
	yylex();
	return 1;
}
int yywrap()
{
	return 1;
}