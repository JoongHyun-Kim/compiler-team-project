#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern char* yytext;

void main()
{
	enum tnumber tn;
	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST: printf("TCONST	const\n"); break;
		case TELSE: printf("TELSE	else\n"); break;
		case TIF: printf("TIF	if\n"); break;
		case TINT: printf("TINT	int\n"); break;
		case TRETURN: printf("TRETURN	return\n"); break;
		case TVOID: printf("TVOID	void\n"); break;
		case TWHILE: printf("TWHILE	while\n"); break;
		case TEQUAL: printf("TEQUAL	equal\n"); break;
		case TNOTEQU: printf("TNOTEQU	notequal\n"); break;
		case TLESSE: printf("TLESSE		less\n"); break;
		case TGREATE: printf("TGREATE	greater\n"); break;
		case TAND: printf("TAND	and\n"); break;
		case TOR: printf("TOR	or\n"); break;
		case TINC: printf("TINC	increase\n"); break;
		case TDEC: printf("TDEC	decrease\n"); break;
		case TADDASSIGN: printf("TADDASSIGN	add_assign\n"); break;
		case TMULASSIGN: printf("TMULASSIGN	mul_assign\n"); break;
		case TDIVASSIGN: printf("TDIVASSIGN		div_assign\n"); break;
		case TMODASSIGN: printf("TMODASSIGN	mod_assign\n"); break;
		case TIDENT: printf("TIDENT		%s\n", yytext); break;
		case TNUMBER: printf("TNUMBER		%d\n", atoi(yytext)); break;
		}
	}
}