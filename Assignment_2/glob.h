/* 
* glob.h - 프로그램에 사용된 global variable 정의
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 04/30/2024
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STsize 1000 // 문자열 테이블 크기
#define HTsize 100 // 해시 테이블 크기

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // ST에서 identifier의 인덱스
    HTpointer next; // 다음 identifier를 가리키는 포인터
} HTentry;

enum errorTypes { noerror, illid, illic, overlen }; // 에러 유형 enum으로 정의
typedef enum errorTypes ERRORtypes;

extern HTpointer HT[HTsize];
extern char ST[STsize];

extern int nextid; // 현재 identifier 인덱스
extern int nextfree; // ST에서 다음 available한 인덱스

extern int hashcode; // identifier의 해시코드
extern int sameid; // 같은 식별자의 첫 인덱스

extern bool found;  // identifier의 이전 등장 여부

extern int lineNum; // 줄 번호
extern int cErrors; // 에러 개수
extern char *error_message; // 에러 메세지
