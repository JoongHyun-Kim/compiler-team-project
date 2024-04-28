#include "glob.h"

HTpointer HT[HTsize];
char ST[STsize];
hashcode = 0;
sameid = 0;
bool found = false;
nextid = 0;
nextfree = 0;

void ReadID(char *ident) {
    nextid = nextfree;
    for (int i = 0; i < strlen(ident); i++) {
        ST[nextfree++] = ident[i];
    }
    ST[nextfree++] = '\0';
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

void SymbolTable(char* ident) {   
    ERRORtypes error;
    ReadID(ident);
    if (nextfree == STsize) { // ST가 꽉 찬 경우
        error = overst; // overst(오버플로우)로 에러 지정
        ReportError(error);
    }
    ComputeHS(nextid, nextfree); // 해시코드 계산
    LookupHS(nextid, hashcode); // 해시 테이블에서 identifier 조회
    if (!found) { // 해시 테이블에 동일한 identifier가 존재하지 않는 경우
        ADDHT(hashcode); // 해시 테이블에 추가
    }
    else { // 해시 테이블에 identifier가 이미 존재하는 경우
        nextfree = nextid; // 인덱스 초기화
    }
}