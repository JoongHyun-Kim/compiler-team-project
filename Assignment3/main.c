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

void PrintHStable()
{
    HTpointer here;
    int i, j;

    printf("\n\n\n\n\n[[HASH TABLE]]\n\n");
    printf("===========================================\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            here = HT[i];
            do {
                printf("Hash Code%3d : (", i);
                for (j = here->index; ST[j] != '\0'; j++) printf("%c", ST[j]);
                printf(" : ");

                switch (here->type) {
                case 1: printf("integer scalar variable, line%d)\n", here->line); break;
                case 2: printf("void scalar variable, line%d)\n", here->line); break;
                case 3: printf("integer array variable, line%d)\n", here->line); break;
                case 4: printf("function, return type=void, line%d)\n", here->line); break;
                case 5: printf("function, return type=int, line%d)\n", here->line); break;
                case 6: printf("not defined identifier/function, line%d)\n", here->line); break;
                }
                here = here->next;
            } while (here != NULL);
        }
    }
    printf("===========================================\n");
}

void main()
{
    printf("\n\t[Error Report : Error Information]");
    printf("\n=================================================\n");

    cLine = 1;
    yyparse();
    if (cErrors == 0) printf("\n\t no error detected!\n");
    else printf("\n\t %d error(s) detected!\n", cErrors);
    printf("\n=================================================\n");
    printf("Parsing ends.");
    PrintHStable(); // identifier와 그 type을 print하는 함수
    printf("JoongHyun Kim(2076088) Seojin Kwak(2076016) Seonyeong Kim(2071010) NaHyun Lee(2076292) \n");
}