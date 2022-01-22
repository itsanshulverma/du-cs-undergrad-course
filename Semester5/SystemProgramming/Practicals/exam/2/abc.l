
%{
  #include "abc.tab.h"
%}

%%
[a-z] return letter;
[0-9] return digit;
[ \t] {;}
\n { return 0;}
. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}