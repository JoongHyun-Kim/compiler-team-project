/*
* reporterror.c - error에 대한 출력
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
#include "glob.h"

extern char* yytext;
extern yylex();

/*
* yyerror() - 에러 함수
*/
yyerror(s)
char* s;
{
    if (s != "parse error") { //parser_tab.c에서 발생한 parse에러가 아닌경우
        printf("\t%-5d %-10s %-50s\n", cLine, yytext, s);//에러 메세지 출력
        cErrors++;//에러수 1 증가 
    }
}


void ReportError(ERRORtypes error) {
    cErrors++;

    switch (error) {
    case noerror: // 에러가 발생하지 않은 경우
        break;
    case illid: // input이 숫자로 시작하는 경우
        printf("%d	< Error > => Illegal Identifier\n", cLine);
        break;
    case illic: // 허용되지 않은 문자가 나타난 경우
        printf("%d	< Error > => Illegal Character\n", cLine);
        break;
    case overlen: // identifier가 12자 이내가 아닌 경우
        printf("%d	< Error > => Too long identifier\n", cLine);
        break;
    case wrong_st:
        printf("%d	< Error > => Wrong Statement\n", cLine);
        break;
    case wrong_funcdef:
        printf("%d	< Error > => Wrong function definition\n", cLine);
        break;
    case nosemi:
        printf("%d	< Error > => Missing brace\n", cLine);
        break;
    case nobracket:
        printf("%d	< Error > => Missing bracket\n", cLine);
        break;
    case nobrace:
        printf("%d  < Error > => Missing brace\n", cLine);
        break;
    }
}