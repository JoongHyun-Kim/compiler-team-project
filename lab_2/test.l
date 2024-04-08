%{
#include <stdio.h>
#include <stdlib.h>
%}
letter [a-zA-Z_]
digit [0-9]
%%
int			printf("integer");
"{"			printf("Begin");
"}"			printf("End");
%%
void main() {
	printf(" Start of Lex\n");
	yylex();
}
int yywrap() {
	printf("\n End of Lex\n");
	printf(" JoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292) \n");
	return 1;
}
