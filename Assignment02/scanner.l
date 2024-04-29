%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
ERRORtypes error = noerror;
%}
%%
"const"	return(TCONST);
"else"	return(TELSE);
"if" 	return(TIF);
"int" 	return(TINT);
"return"	return(TRETURN);
"void"	return(TVOID);
"while"	return(TWHILE);
"=="	return(TEQUAL);
"!="	return(TNOTEQU);
"<"	return(TLESS);
">"	return(TGREAT);
"<="	return(TLESSE);
">="	return(TGREATE);
"!"	return(TNOT);
"&&" 	return(TAND);
"||" 	return(TOR);
"++"	return(TINC);
"--" 	return(TDEC);
"+"	return(TADD);
"-"	return(TSUB);
"*"	return(TMUL);
"/"	return(TDIV);
"%"	return(TMOD);
"="	return(TASSIGN);
"+=" 	return(TADDASSIGN);
"-=" 	return(TSUBASSIGN);
"*=" 	return(TMULASSIGN);
"/=" 	return(TDIVASSIGN);
"%=" 	return(TMODASSIGN);
"("	return(TLEFTPARENTHESIS);
")"	return(TRIGHTPARENTHESIS);
"{"	return(TLEFTBRACE);
"}"	return(TRIGHTBRACE);
"["	return(TLEFTBRACKET);
"]"	return(TRIGHTBRACKET);
";"  	return(TSEMICOLON);
","	return(TCOMMA);
"."	return(TDOT);
[A-Za-z_][A-Za-z0-9_]* {
	if(yyleng > 12) {
		error = overlen;
		ReportError(error);
		return(TERROR);
	}
	else {
		SymbolTable(yytext);
		return(TIDENT);	
	}
}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? return(TNUMBER);
[0-9]+[A-Za-z0-9]+ {
	error = illid;
	ReportError(error);
	return(TERROR);
}
"/*"([^*]|\*+[^*/])*\**"*/"	;
"//".*	;
"\n" 	{ lineNum++; }
[ \t]	;
.	{
	error = illic;
	ReportError(error);
	return(TERROR);
}
%%

int yywrap()
{
printf("\n");
printf(" JoongHyun Kim(2076088) SeoJin Kwak(2076016) SeonYeong Kim(2071010) NaHyun Lee(2076292) \n");
return 1;
}