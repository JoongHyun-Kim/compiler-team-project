/*
* reporterror.c - error에 대한 출력
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

int cErrors = 0;
extern line(int);
extern yylex();

/*
* yyerror() - error 함수
*/

yyerror(s)
char *s;
{

}

void printError(ERRORtypes err)
{
	switch(err) {
	    case 0: //wrong_st
	        line(cLine);
		    printf("< Error > => Wrong Statement!\n");
		    cErrors++;
		    break;
		case 1: //wrong_funcdef
		    line(cLine);
		    printf("< Error > => Wrong function definition\n");
		    cErrors++;
		    break;
	    case 2: //nosemi
	        line(cLine);
	        printf("< Error > => Missing brace\n");
	        cErrors++;
	        break;
	   case 4: //nobracket
	        line(cLine);
	        printf("< Error > => Missing bracket\n");
	        cErrors++;
	        break;
	}
}
