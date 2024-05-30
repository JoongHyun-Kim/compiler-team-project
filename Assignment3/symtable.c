/*
* symtable.c - Identifier를 읽고 HT를 구성
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 31/05/2024
*/

#include "glob.h"

ERRORtypes error;
HTpointer HT[HTsize];
char ST[STsize];
int hashcode = 0;
int sameid = 0;
bool found = false;
int nextid = 0;
int nextfree = 0;


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
                case 3: printf("float scalar variable, line%d)\n", here->line); break;
                case 4: printf("integer array variable, line%d)\n", here->line); break;
                case 5: printf("float array variable, line%d)\n", here->line); break;
                case 6: printf("function, return type=void, line%d)\n", here->line); break;
                case 7: printf("function, return type=int, line%d)\n", here->line); break;
                case 8: printf("function, return type=float, line%d)\n", here->line); break;
                case 10: printf("not defined identifier/function, line%d)\n", here->line); break;
                }
                here = here->next;
            } while (here != NULL);
        }
    }
    printf("===========================================\n");
}

// Identifier를 읽는 함수
void ReadID(char* ident) {
    nextid = nextfree; // ident의 시작 index를 nextid에 저장
    for (int i = 0; i < strlen(ident); i++) {
        ST[nextfree++] = ident[i]; // ident을 ST에 추가하고 다음 문자로 이동
    }
    ST[nextfree++] = '\0'; // 문자열의 끝을 나타내는 null 문자 추가
}

// Hashcode를 계산하는 함수
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0;
    for (i = nid; i < nfree - 1; i++) { // nid부터 nfree-1 까지의 문자에 대해
        code += (int)ST[i]; // 아스키 코드값 합
    }
    hashcode = code % HTsize; // 해시코드값 계산
}

// 해시테이블에서 현재 읽은 identifier가 존재하는지 판단하는 함수
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;

    found = false; // 초기화
    if (HT[hscode] != NULL) { // 해시테이블의 해당 해시코드에 값이 있으면
        here = HT[hscode]; // 해당 해시코드의 첫 번째 노드 가져오기
        while (here != NULL && found == false) { // 문자가 존재하고 identifier가 발견되지 않은 경우
            found = true;
            i = here->index; // 현재 노드의 identifier 인덱스
            j = nid; // 읽고있는 identifier의 시작 인덱스
            sameid = i; // 같은 identifier 인덱스 저장

            while (ST[i] != '\0' && ST[j] != '\0' && found == true) {   // 문자를 비교하며 identifier 일치 여부 판단
                if (ST[i] != ST[j]) // 문자가 다르면
                    found = false;
                else { // 다음 문자로 이동
                    i++;
                    j++;
                }
            }
            here = here->next;  // 연결 리스트의 다음 identifier로 이동
        }
    }
}

// 해시 테이블에 identifier를 추가하는 함수
/*void ADDHT(int hscode) {
    HTpointer ptr;
    ptr = (HTpointer)malloc(sizeof(struct HTentry));
    ptr->type = 0;
    ptr->next = NULL;
    ptr->line = cLine;
    HT[hscode] = ptr;
    ptr->index = nextid;

    look_id = ptr;
}*/

void ADDHT(int hscode)
{
    HTpointer ptr;

    if (HT[hscode] == NULL) {
        ptr = (HTpointer)malloc(sizeof(struct HTentry));
        ptr->type = 0;
        ptr->line = cLine;
        ptr->index = nextid;
        ptr->next = NULL;
        HT[hscode] = ptr;
    }
    else {
        ptr = (HTpointer)malloc(sizeof(struct HTentry));
        ptr->type = 0;
        ptr->line = cLine;
        ptr->index = nextid;
        ptr->next = HT[hscode];
        HT[hscode] = ptr;
    }
    look_id = ptr;
}

// 주어진 identifier를 처리해 심볼 테이블에 추가 또는 이미 존재하는지 확인
void SymbolTable(char* ident) {
    ReadID(ident);
    ComputeHS(nextid, nextfree); // 해시코드 계산
    LookupHS(nextid, hashcode); // 해시 테이블에서 identifier 조회
    if (!found) { // 해시 테이블에 동일한 identifier가 존재하지 않는 경우
        ADDHT(hashcode); // 해시 테이블에 추가
    }
    else { // 해시 테이블에 identifier가 이미 존재하는 경우
        nextfree = nextid; // 인덱스 초기화
    }

    if (nextfree == STsize) {
        error = overflow;
        ReportError(overflow);
        PrintHStable();
        exit(1);
    }
}