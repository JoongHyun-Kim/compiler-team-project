/**************************************************************************************
Hashtable Implementation Program

Contributors : 김중현/2076088, 곽서진/2076016, 김선영/2071010, 이나현/2076292
Date: 03/20/2024
Assignment  : Compiler HW1

***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "inputdata1.txt" // 파일명 지정
#define STsize 1000 // 문자열 테이블 크기
#define HTsize 100 // 해시 테이블 크기
#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || (x) == '_') // 문자 여부 확인
#define isDigit(x) ((x) >= '0' && (x) <= '9') // 숫자 여부 확인

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // ST에서 identifier의 인덱스
    HTpointer next; // 다음 identifier를 가리키는 포인터
} HTentry;

enum errorTypes { noerror, illsp, illid, illic, overst, overlen }; // 에러 유형 enum으로 정의
typedef enum errorTypes ERRORtypes;

char separators[] = " .,;:?!\t\n"; // separator 정의

HTpointer HT[HTsize];
char ST[STsize];

ERRORtypes error; // 에러 상태

int nextid = 0; // 현재 identifier 인덱스
int nextfree = 0; // ST에서 다음 available한 인덱스

int hashcode; // identifier의 해시코드
int sameid; // 같은 식별자의 첫 인덱스

bool found; // identifier의 이전 등장 여부

FILE* fp; // 파일을 가리키는 포인터
char input; // 입력 문자

// Input 파일을 여는 함수
void initialize() {
    fp = fopen(FILE_NAME, "r"); // 파일 읽기
    input = fgetc(fp); // 첫 문자 읽기
}

// Separator인지 확인하는 함수
bool isSeparator(char input) {
    int i;
    unsigned long sep_len;

    sep_len = strlen(separators);
    for (i = 0; i < sep_len; i++) {
        if (input == separators[i]) {
            return true; // separator인 경우
        }
    }
    return false; // separator가 아닌 경우
}

// Heading(Index in ST, identifier)을 출력하는 함수
void PrintHeading() {
    printf("--------------      ------------\n");
    printf(" Index in ST         identifier \n");
    printf("--------------      ------------\n");
}

// 해시 테이블을 출력하는 함수
void PrintHStable() {
    int i, j;
    HTpointer here; // 현재 노드를 가리킬 포인터

    printf("\n\n\n\n\n [[ HASH TABLE ]] \n\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) { // 노드가 존재하면
            printf(" Hash Code %3d : ", i); // 현재 해시 코드 출력
            for (here = HT[i]; here != NULL; here = here->next) { // 연결 리스트의 모든 노드 방문
                j = here->index; // 현재 노드의 identifier 시작 인덱스
                while (ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]); // identifier 문자 하나씩 출력
                printf("    ");
            }
            printf("\n");
        }
    }
    printf("\n\n\n < %5d characters are used in the string table > \n", nextfree); // ST에서 사용된 총 문자 수 출력
}

// 발생한 에러에 따라 적절한 에러 메시지를 출력하는 함수
void PrintError(ERRORtypes error) {
    int i;
    switch (error) {
        case noerror: // 에러가 발생하지 않은 경우
            break;
        case overst: // ST 사이즈가 오버플로우인 경우
            printf("...Error...             OVERFLOW ");
            PrintHStable();
            exit(0); // 프로그램 종료
        case illsp: // illegal separator인 경우
            printf("...Error...             %c is illegal separator\n", input);
            break;
        case illid: // input이 숫자로 시작하는 경우
            printf("...Error...             ");
            for(i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
            // 출력 정렬을 위해 공백 추가
            // 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
            for (int j = 0; j < 20-(nextfree-nextid); j++) {
                printf(" ");
            }
            printf("start with digit\n");
            nextfree = nextid;  // 다음 identifier의 인덱스를 현재 인덱스로 설정하여 identifier 무시
            break;
        case illic: // 허용되지 않은 문자가 나타난 경우
            printf("...Error...             ");
            char illic = '\0';  // 허용되지 않은 문자를 저장할 변수
            for(i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
            // 출력 정렬을 위해 공백 추가
            // 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
            for (int j = 0; j < 20-(nextfree-nextid); j++) {
                printf(" ");
            }
            for (i = nextid; i < nextfree - 1; i++) {
                if (!(isDigit(ST[i]) || isLetter(ST[i])))   // 문자가 숫자나 영문자가 아닐 경우
                    illic = ST[i];
            }
            printf("%c Is not allowed\n", illic);
            nextfree = nextid;
            break;
        case overlen: // identifier가 12자 이내가 아닌 경우
            printf("...Error...             ");
            for (i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
            // 출력 정렬을 위해 공백 추가
            // 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
            for (int j = 0; j < 20-(nextfree-nextid); j++) {
                printf(" ");
            }
            printf("too long identifier\n");
            nextfree = nextid;
            break;
    }
}

// Separator를 건너뛰는 함수
void SkipSeparators() {
    while (input != EOF && !(isLetter(input) || isDigit(input))) { // input이 파일의 끝에 도달하지 않았고, 문자나 숫자가 아닐 때
        if (!isSeparator(input)) { // identifier가 아니면
            error = illsp; // illsp(잘못된 공백 문자 에러)로 지정
            PrintError(error);
        }
        input = fgetc(fp); // 다음 문자 읽기
    }
}

// Identifier를 읽는 함수
void ReadID() {
    nextid = nextfree;  // input의 시작 index를 nextid에 저장
    if (isDigit(input)) {   // input이 숫자로 시작할 때
        error = illid; // illid(잘못된 identifier 에러)로 지정
    }
    while (input != EOF && !isSeparator(input)) { // input이 파일의 끝에 도달하지 않았고 identifier가 아닐 때까지
        if (nextfree == STsize) { // ST가 꽉 차면
            error = overst; // overst(오버플로우 에러)로 지정
            PrintError(error);
        }
        if(!(isLetter(input) || isDigit(input))){   // input이 영문자나 숫자가 아닌 허용되지 않은 문자일 경우
            error = illic; // illic(잘못된 문자 에러)로 지정
        }
        ST[nextfree++] = input; // input을 ST에 추가하고 다음 문자로 이동
        input = fgetc(fp); // 다음 문자 읽기
    }
    ST[nextfree++] = '\0';  // 문자열의 끝을 나타내는 null 문자 추가
    PrintError(error);
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
void ADDHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr)); // 새로운 노드 동적 할당
    ptr->index = nextid; // 현재 identifier의 인덱스 설정
    ptr->next = HT[hscode]; // 새 노드의 다음 노드를 현재 해시코드의 첫 번째 노드로 설정
    HT[hscode] = ptr; // 연결 리스트에 identifier 삽입
}

int main() {
    int i;
    PrintHeading(); // 헤더 출력
    initialize(); // 초기화

    while (input != EOF) {  // 파일의 끝에 도달할 때까지
        error = noerror; // 에러 상태 초기화
        SkipSeparators(); // separator 건너뛰기
        ReadID(); // identifier 읽기
        if (error != illid && error != illic) { // 허용되지 않은 문자가 아니며, 숫자로 시작하지 않는 경우
            if (nextfree == STsize) { // ST가 꽉 찬 경우
                error = overst; // overst(오버플로우)로 에러 지정
                PrintError(error);
            }
            ComputeHS(nextid, nextfree); // 해시코드 계산
            LookupHS(nextid, hashcode); // 해시 테이블에서 identifier 조회
            if (nextfree - nextid > 13) { // identifier의 길이가 12자 이하가 아닌 경우
                error = overlen; // overlen(길이 초과)로 에러 지정
                PrintError(overlen);
            }
            else if (!found) { // 해시 테이블에 동일한 identifier가 존재하지 않는 경우
                printf("%6d        ", nextid); // identifier 인덱스 출력
                printf("          "); // 정렬을 위한 공백
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]); // identifier 출력
                }
                // 출력 정렬을 위해 공백 추가
                // 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
                for (int j = 0; j < 20-(nextfree-nextid); j++) {
                    printf(" ");
                }
                printf("(entered)\n");
                ADDHT(hashcode); // 해시 테이블에 추가
            }
            else { // 해시 테이블에 identifier가 이미 존재하는 경우
                printf("%6d        ", sameid); // 동일한 identifier의 인덱스 출력
                printf("          "); // 정렬을 위한 공백
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]); // identifier 출력
                }
                // 출력 정렬을 위해 공백 추가
                // 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
                for (int j = 0; j < 20-(nextfree-nextid); j++) {
                    printf(" ");
                }
                printf("(already existed)\n");
                nextfree = nextid; // 인덱스 초기화
            }
        }
        SkipSeparators(); // separator 건너뛰기
    }
    PrintHStable(); // 해시 테이블 출력
    printf("김중현/2076088, 곽서진/2076016, 김선영/2071010, 이나현/2076292");
}
