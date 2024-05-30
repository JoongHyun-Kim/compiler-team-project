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
yyerror(char* s) {

}

void ReportError(ERRORtypes error) {
    cErrors++;

    switch (error) {
    case noerror: // 에러가 발생하지 않은 경우
        break;
    case overflow:
        printf("%d\tError => Overflow\n", cLine);
        break;
    case illid: // input이 숫자로 시작하는 경우
        printf("%d\tError => Illegal Identifier\n", cLine);
        break;
    case illic: // 허용되지 않은 문자가 나타난 경우
        printf("%d\tError => Illegal Character\n", cLine);
        break;
    case overlen: // identifier가 12자 이내가 아닌 경우
        printf("%d\tError => Too long identifier\n", cLine);
        break;
    case wrong_st:
        printf("%d\tError => Wrong Statement\n", cLine);
        break;
    case wrong_funcdef:
        printf("%d\tError => Wrong function definition\n", cLine);
        break;
    case wrong_assign:
        printf("%d\tError => Wrong assign\n", cLine);
        break;
    case nosemi:
        printf("%d\tError => Missing semicolon\n", cLine);
        break;
    case nocomma:
        printf("%d\tError => Missing comma\n", cLine);
        break;
    case nobracket:
        printf("%d\tError => Missing bracket\n", cLine);
        break;
    case noparen:
        printf("%d\tError => Missing parenthesis\n", cLine);
        break;
    case nobrace:
        printf("%d\tError => Missing brace\n", cLine);
        break;
    }
}