%{
/*
* scanner.l - MiniC 구문 분석기
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
%}

%%
"const"	return(TCONST);
"else"	return(TELSE);
"if" 	return(TIF);
"int" 	return(TINT);
"float"	return(TFLOAT);
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
		ReportError(overlen);
		return(TERROR);
	}
	else {
		SymbolTable();
		return(TIDENT);	
	}
}

[0-9]+ return(TNUMBER);
[0-9]+"."[0-9]+	return(TRNUMBER);
[0-9]+[A-Za-z0-9]+ {
	ReportError(illid);
	return(TERROR);
}
"//".*	;
[\n] 	{ cLine++; }
[ \t]	;
.	{
	printf("%s",yytext);
	ReportError(illic);
	return(TERROR);
}
%%

// 스캔이 끝났을 때 호출
int yywrap()
{
	return 1;
}