/*
* glob.h - 프로그램에 사용된 global variable 정의
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 31/05/2024
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
	int type;	// type
	int line;	// line num
} HTentry;

enum errorTypes { noerror, illid, illic, overlen, overflow, wrong_st, wrong_funcdef, wrong_assign, nosemi, noparen, nobrace, nobracket, nocomma }; // 에러 유형 enum으로 정의
typedef enum errorTypes ERRORtypes;
ERRORtypes error;

HTpointer HT[HTsize];
HTpointer look_id;
HTpointer look_tmp;
char ST[STsize];

int nextid; // 현재 identifier 인덱스
int nextfree; // ST에서 다음 available한 인덱스

int hashcode; // identifier의 해시코드
int sameid; // 같은 식별자의 첫 인덱스

bool found;  // identifier의 이전 등장 여부

int yyleng;  // yytext 길이
char* yytext; // scanner input text

int cLine;	// 줄 번호
int cErrors; // 에러 개수
char* error_message; // 에러 메세지
