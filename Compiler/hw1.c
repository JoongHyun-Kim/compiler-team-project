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

#define FILE_NAME "testdata.txt"
#define STsize 1000        // size of string table
#define HTsize 100        // size of hash table
#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || (x) == '_')
#define isDigit(x) ((x) >= '0' && (x) <= '9')

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;        // index of identifier in ST
    HTpointer next;    // pointer to next identifier
} HTentry;

enum errorTypes { noerror, illsp, illid, illic, overst, overlen };
typedef enum errorTypes ERRORtypes;

char separators[] = " .,;:?!\t\n";

HTpointer HT[HTsize];
char ST[STsize];

ERRORtypes error;

int nextid = 0;     // the current identifier
int nextfree = 0;   // the next available index of ST

int hashcode;       // hashcode of identifier
int sameid;         // first index of identifier

bool found;         // for the previous occurrence of an identifier

FILE* fp;      // to be a pointer to FILE
char input;

// Input 파일을 여는 함수
void initialize() {
    fp = fopen(FILE_NAME, "r");
    input = fgetc(fp);
}

// Separator인지 확인하는 함수
bool isSeparator(char input) {
    int i;
    unsigned long sep_len;

    sep_len = strlen(separators);
    for (i = 0; i < sep_len; i++) {
        if (input == separators[i]) {
            return true;    // separator인 경우
        }
    }
    return false;   // separator가 아닌 경우
}

// Heading(Index in ST, identifier)을 출력하는 함수
void PrintHeading() {
    printf("--------------      ------------\n");
    printf(" Index in ST         identifier \n");
    printf("--------------      ------------\n");
}

// Hashtable 출력 함수
void PrintHStable() {
    int i, j;
    HTpointer here;

    printf("\n\n\n\n\n [[ HASH TABLE ]] \n\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            printf(" Hash Code %3d : ", i);
            for (here = HT[i]; here != NULL; here = here->next) {
                j = here->index;
                while (ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]);
                printf("    ");
            }
            printf("\n");
        }
    }
    printf("\n\n\n < %5d characters are used in the string table > \n", nextfree);
}

// 발생한 에러에 따라 적절한 에러 메시지를 출력하는 함수
void PrintError(ERRORtypes error) {
    int i;
    switch (error) {
        case noerror:   // 에러가 없는 경우
            break;
        case overst:    // ST 사이즈가 오버플로우인 경우
            printf("...Error...             OVERFLOW ");
            PrintHStable();
            exit(0);    // 프로그램 종료
            break;
        case illsp:    // illegal separator인 경우
            printf("...Error...             %c is illegal separator\n", input);
            break;
        case illid:    // input이 숫자로 시작하는 경우
            printf("...Error...             ");
            for(i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
            for (int j = 0; j < 20-(nextfree-nextid); j++) {    // 출력 정렬을 위해 공백 추가
                printf(" ");
            }
            printf("start with digit\n");
            nextfree = nextid;  // 다음 identifier의 인덱스를 현재 인덱스로 설정하여 identifier 무시
            break;
        case illic:     // 허용되지 않은 문자가 나타난 경우
            printf("...Error...             ");
            char illic = '\0';  // 허용되지 않은 문자를 저장할 변수
            for(i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
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
        case overlen:   // identifier가 12자 이내가 아닌 경우
            printf("...Error...             ");
            for (i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
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
    while (input != EOF && !(isLetter(input) || isDigit(input))) {
        if (!isSeparator(input)) {
            error = illsp;
            PrintError(error);
        }
        input = fgetc(fp);
    }
}

// Identifier를 읽는 함수
void ReadID() {
    nextid = nextfree;  // input의 시작 index를 nextid에 저장
    if (isDigit(input)) {   // input이 숫자로 시작할 때
        error = illid;
    }
    while (input != EOF && !isSeparator(input)) {
        if (nextfree == STsize) {
            error = overst;
            PrintError(error);
        }
        if(!(isLetter(input) || isDigit(input))){   // input이 영문자나 숫자가 아닌 허용되지 않은 문자일 경우
            error = illic;
        }
        ST[nextfree++] = input; // input을 ST에 추가하고 다음 문자로 이동
        input = fgetc(fp);
    }
    ST[nextfree++] = '\0';  // 문자열의 끝을 나타내는 null 문자 추가
    PrintError(error);
}

// Hashcode를 계산하는 함수
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0;
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i];
    }
    hashcode = code % HTsize;
}

// Hashtable에서 현재 읽은 identifier가 존재하는지 판단하는 함수
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;

    found = false;
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        while (here != NULL && found == false) {    // 문자가 존재하고 identifier가 발견되지 않은 경우
            found = true;
            i = here->index;
            j = nid;
            sameid = i;

            while (ST[i] != '\0' && ST[j] != '\0' && found == true) {   // 문자를 비교하며 identifier 일치 여부 판단
                if (ST[i] != ST[j])
                    found = false;
                else {
                    i++;
                    j++;
                }
            }
            here = here->next;  // 연결 리스트의 다음 identifier로 이동
        }
    }
}

// Hashtable에 identifier를 추가하는 함수
void ADDHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr));
    ptr->index = nextid;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;   // 연결 리스트에 identifier 삽입
}

int main() {
    int i;
    PrintHeading();
    initialize();

    while (input != EOF) {  // 파일의 끝에 도달할 때까지 반복
        error = noerror;
        SkipSeparators();
        ReadID();
        if (error != illid && error != illic) { // 허용되지 않은 문자가 아니고 숫자로 시작하지 않는 경우
            if (nextfree == STsize) {
                error = overst;
                PrintError(error);
            }
            ComputeHS(nextid, nextfree);
            LookupHS(nextid, hashcode);
            if (nextfree - nextid > 13) {   // identifier의 길이가 12자 이내가 아닌 경우
                error = overlen;
                PrintError(overlen);
            }
            else if (!found) {      // Hashtable에 동일한 identifier가 존재하지 않는 경우
                printf("%6d        ", nextid);
                printf("          ");
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]);
                }
                for (int j = 0; j < 20-(nextfree-nextid); j++) {    // 출력 정렬을 위해 공백 추가
                    printf(" ");
                }
                printf("(entered)\n");
                //printf("         (entered)\n");
                ADDHT(hashcode);
            }
            else {      // Hashtable에 identifier가 이미 존재하는 경우
                printf("%6d        ", sameid);
                printf("          ");
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]);
                }
                for (int j = 0; j < 20-(nextfree-nextid); j++) {
                    printf(" ");
                }
                printf("(already existed)\n");
                nextfree = nextid;
            }
        }
        SkipSeparators();
    }
    PrintHStable();
    printf("김중현/2076088, 곽서진/2076016, 김선영/2071010, 이나현/2076292");
}
