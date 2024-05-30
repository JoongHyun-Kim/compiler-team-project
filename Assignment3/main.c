/*
* main.c - 프로그램 메인 실행
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern int yyparse();
extern void PrintHStable();

void main()
{
    cLine = 1;
    cErrors = 0;
    printf("\n\t[Error Report : Error Information]");
    printf("\n=================================================\n");
    printf("*** MiniC parsing begins\n\n");
    yyparse();
    printf("\nParsing ends. ***\n");
    if (cErrors == 0) printf("\nno error detected!\n");
    else printf("\n%d error(s) detected!\n", cErrors);
    printf("\n=================================================\n");
    PrintHStable(); // identifier와 그 type을 print하는 함수
    printf("JoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292) \n");
}