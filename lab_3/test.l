%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESSE, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN
, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
%}

%%
"const" return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"==" return(TEQUAL);
"!=" return(TNOTEQU);
"<=" return(TLESSE);
">=" return(TGREATE);
"&&" return(TAND);
"||" return(TOR);
"++" return(TINC);
"--" return(TDEC);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]* return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/" ;
"\\".* ;
[ \t\n] ;
. return(yytext[0]);
%%

void main()
{
enum tnumber tn;
while ((tn = yylex()) != TEOF) {
switch (tn) {
case TCONST : printf("TCONST	const\n"); break;
case TELSE : printf("TELSE	else\n"); break;
case TIF : printf("TIF	if\n"); break;
case TINT : printf("TINT	int\n"); break;
case TRETURN : printf("TRETURN	return\n"); break;
case TVOID : printf("TVOID	void\n"); break;
case TWHILE : printf("TWHILE	while\n"); break;
case TEQUAL : printf("TEQUAL	equal\n"); break;
case TNOTEQU : printf("TNOTEQU	notequal\n"); break;
case TLESSE : printf("TLESSE		less\n"); break;
case TGREATE : printf("TGREATE	greater\n"); break;
case TAND : printf("TAND	and\n"); break;
case TOR : printf("TOR	or\n"); break;
case TINC : printf("TINC	increase\n"); break;
case TDEC : printf("TDEC	decrease\n"); break;
case TADDASSIGN : printf("TADDASSIGN	add_assign\n"); break;
case TMULASSIGN : printf("TMULASSIGN	mul_assign\n"); break;
case TDIVASSIGN : printf("TDIVASSIGN		div_assign\n"); break;
case TMODASSIGN : printf("TMODASSIGN	mod_assign\n"); break;
case TIDENT : printf("TIDENT		%s\n", yytext); break;
case TNUMBER : printf("TNUMBER		%d\n", atoi(yytext)); break;
}
}
}

int yywrap()
{
printf("\n");
printf(" JoongHyun Kim(2076088) SeoJin Kwak(2076016) SeonYeong Kim(2071010) NaHyun Lee(2076292) \n");
return 1;
}
