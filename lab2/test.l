%{
    #include <stdio.h>
    #include <stdlib.h>
    enum tnumber { TEOF };
%}

letter [a-zA-Z_];
digit [0-9];

%%

int	printf("integer");
"{"	printf("\nBegin");
"}"	printf("\nEnd");
.	printf("%s", yytext);

%%

void main() {
	enum tnumber tn;
	printf(" Start of Lex\n");
	yylex();
// 	while((tn=yylex()) != TEOF) {
// 	}
}

int yywrap() {
    printf("\nJoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292) \n");
    return 1;
}