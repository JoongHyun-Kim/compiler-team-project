#include "glob.h"

int cErrors = 0;
char *error_message;

void ReportError(ERRORtypes error) {
    cErrors++;
    switch (error) {
    case noerror: // ������ �߻����� ���� ���
        break;
    case illid: // input�� ���ڷ� �����ϴ� ���
        error_message = "Illegal Identifier";
        break;
    case illic: // ������ ���� ���ڰ� ��Ÿ�� ���
        error_message = "Illegal Character";
        break;
    case overlen: // identifier�� 12�� �̳��� �ƴ� ���
        error_message = "Too long identifier";
        break;
    }
}