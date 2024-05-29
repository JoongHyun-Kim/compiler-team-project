/*
* main.c - 프로그램 메인 실행
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 05/31/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

int cLine = 1;
extern int yyparse();

void printType(int type) {
    switch (type) {
	case 1:
		printf("type int");
	case 2:
		printf("type void");
    }
}

void PrintHStable() {
	printf("\n\n\n\n\n[[ HASH TABLE ]]\n\n");
    int i, j;
    HTpointer here;

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) { // 노드가 존재하면
            printf(" Hash Code %3d : ", i); // 현재 해시 코드 출력
            for (here = HT[i]; here != NULL; here = here->next) { // 연결 리스트의 모든 노드 방문
                j = here->index; // 현재 노드의 identifier 시작 인덱스
                while (ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]); // identifier 문자 하나씩 출력
                printType(here->type);
                printf("line %d", here->line);
            }
            printf("\n");
        }
    }
}

void main()
{
	printf("\n\t[Error Report : Error Information]");
	printf("\n=================================================\n");

	cLine = 1;
    int result = yyparse();
    printf("result %d", result);
	if (cErrors == 0) printf("\n\t no error detected!\n");
	else printf("\n\t %d error(s) detected!\n", cErrors);
	printf("\n=================================================\n");
	PrintHStable(); // identifier와 그 type을 print하는 함수
	printf("JoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292) \n");
}