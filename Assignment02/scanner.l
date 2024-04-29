%{
/*
* scanner.l - MiniC 구문 분석기
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 04/30/2024
*/

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
[A-Za-z_][A-Za-z0-9_]* {
	if(yyleng > 12) {
		error = overlen;
		ReportError(error, yytext);
		return(TERROR);
	}
	else {
		SymbolTable(yytext);
		return(TIDENT);	
	}
}

[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? return(TNUMBER);
[0-9]+"."[0-9]+	return(TRNUMBER);
[0-9]+[A-Za-z0-9]+ {
	error = illid;
	ReportError(error, yytext);
	return(TERROR);
}
"/*"([^*]|\*+[^*/])*\**"*/"	;
"//".*	;
"\n" 	{ lineNum++; }
[ \t]	;
.	{
	error = illic;
	ReportError(error, yytext);
	return(TERROR);
}
%%

int yywrap()
{
printf("\n");
printf("JoongHyun Kim(2076088) SeoJin Kwak(2076016) SeonYeong Kim(2071010) NaHyun Lee(2076292) \n");
return 1;
}
