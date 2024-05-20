%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
%}
%%
[a-z]*	{return NAME;}
[0-9]*	{yylval = atoi(yytext); return NUMBER;}
[ \t]	;
"\n"	return 0;
.	return yytext[0];
%%
int yywrap()
{	
	return 1;
}
