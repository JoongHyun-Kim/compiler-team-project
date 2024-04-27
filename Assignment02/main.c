#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
#include "tn.h"

extern yylex();
extern char* yytext;

void PrintHeading()
{
	printf("Line Number		Token type		ST-index		Token\n");
}

void PrintToken(enum tnumber tn) {
	switch (tn) {
	case TCONST: printf("%d			const						%s\n", lineNum, yytext); break;
	case TELSE: printf("%d			else						%s\n", lineNum, yytext); break;	
	case TIF: printf("%d			if						%s\n", lineNum, yytext); break;
	case TINT: printf("%d			int						%s\n", lineNum, yytext); break;
	case TRETURN: printf("%d			return						%s\n", lineNum, yytext); break;
	case TVOID: printf("%d			void						%s\n", lineNum, yytext); break;
	case TWHILE: printf("%d			while						%s\n", lineNum, yytext); break;
	case TEQUAL: printf("%d			equal						%s\n", lineNum, yytext); break;
	case TNOTEQU: printf("%d			notequal						%s\n", lineNum, yytext); break;
	case TLESSE: printf("%d			less						%s\n", lineNum, yytext); break;
	case TGREATE: printf("%d			greater						%s\n", lineNum, yytext); break;
	case TAND: printf("%d			and						%s\n", lineNum, yytext); break;
	case TOR: printf("%d			or						%s\n", lineNum, yytext); break;
	case TINC: printf("%d			increase						%s\n", lineNum, yytext); break;
	case TDEC: printf("%d			decrease						%s\n", lineNum, yytext); break;
	case TADDASSIGN: printf("%d			add_assign						%s\n", lineNum, yytext); break;
	case TMULASSIGN: printf("%d			mul_assign						%s\n", lineNum, yytext); break;
	case TDIVASSIGN: printf("%d			div_assign						%s\n", lineNum, yytext); break;
	case TMODASSIGN: printf("%d			mod_assign						%s\n", lineNum, yytext); break;
	case TLEFTPARENTHESIS: printf("%d			left_parenthesis						%s\n", lineNum, yytext); break;
	case TRIGHTPARENTHESIS: printf("%d			right_parenthesis						%s\n", lineNum, yytext); break;
	case TLEFTBRACE: printf("%d			left_brace						%s\n", lineNum, yytext); break;
	case TRIGHTBRACE: printf("%d			right_brace						%s\n", lineNum, yytext); break;
	case TLEFTBRACKET: printf("%d			left_bracket						%s\n", lineNum, yytext); break;
	case TRIGHTBRACKET: printf("%d			right_bracket						%s\n", lineNum, yytext); break;
	case TCOMMA: printf("%d			comma						%s\n", lineNum, yytext); break;
	case TSEMICOLON: printf("%d			semicolon					%s\n", lineNum, yytext); break;
	case TIDENT: printf("%d			ident			%d			%s\n", lineNum, nextid, yytext); break;
	case TNUMBER: printf("%d			number						%d\n", lineNum, atoi(yytext)); break;
	case TERROR: printf("%d			**ERROR**					%s %s\n", lineNum, yytext, error_message); break;
	}
}

void main()
{
	enum tnumber tn;
	PrintHeading();
	while ((tn = yylex()) != TEOF) {
		PrintToken(tn);
	}

	if (cErrors == 0) {
		printf("No errors detected\n");
	}
	else {
		printf("%d erros detected\n", cErrors);
	}

}