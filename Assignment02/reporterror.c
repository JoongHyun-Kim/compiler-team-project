#include "glob.h"

int cErrors = 0;
char *error_message;

void ReportError(ERRORtypes error) {
    cErrors++;
    switch (error) {
    case noerror: // 에러가 발생하지 않은 경우
        break;
    case illid: // input이 숫자로 시작하는 경우
        error_message = "Illegal Identifier";
        break;
    case illic: // 허용되지 않은 문자가 나타난 경우
        error_message = "Illegal Character";
        break;
    case overlen: // identifier가 12자 이내가 아닌 경우
        error_message = "Too long identifier";
        break;
    }
}