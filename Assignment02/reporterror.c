#include "glob.h"

char ST[STsize];
int nextid;
int nextfree;
int cErrors = 1;
char *error_message;

void ReportError(ERRORtypes error) {
    cErrors++;
    int i;
    switch (error) {
    case noerror: // 에러가 발생하지 않은 경우
        break;
    case overst: // ST 사이즈가 오버플로우인 경우
        error_message = "Overflow";
        exit(0); // 프로그램 종료
    case illid: // input이 숫자로 시작하는 경우
        error_message = "Illegal Identifier";
        //nextfree = nextid;  // 다음 identifier의 인덱스를 현재 인덱스로 설정하여 identifier 무시
        break;
    case illic: // 허용되지 않은 문자가 나타난 경우
        error_message = "Illegal Character";
        break;
    case overlen: // identifier가 12자 이내가 아닌 경우
        error_message = "Too long identifier";
        break;
    }
}