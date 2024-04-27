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
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// 출력 정렬을 위해 공백 추가
        //// 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //printf("start with digit\n");
        error_message = "Illegal Identifier";
        //nextfree = nextid;  // 다음 identifier의 인덱스를 현재 인덱스로 설정하여 identifier 무시
        break;
    case illic: // 허용되지 않은 문자가 나타난 경우
        //char illic = '\0';  // 허용되지 않은 문자를 저장할 변수
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// 출력 정렬을 위해 공백 추가
        //// 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //for (i = nextid; i < nextfree - 1; i++) {
        //    if (!(isDigit(ST[i]) || isLetter(ST[i])))   // 문자가 숫자나 영문자가 아닐 경우
        //        illic = ST[i];
        //}
        //printf("%c Is not allowed\n", illic);
        error_message = "Illegal Character";
        //nextfree = nextid;
        break;
    case overlen: // identifier가 12자 이내가 아닌 경우
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// 출력 정렬을 위해 공백 추가
        //// 최대 길이를 20글자로 가정하고, (20 - (nextfree - nextid)만큼 공백 추가
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //printf("too long identifier\n");
        error_message = "Too long identifier";
        //nextfree = nextid;
        break;
    }
}