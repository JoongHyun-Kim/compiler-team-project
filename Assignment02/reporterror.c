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
    case noerror: // ������ �߻����� ���� ���
        break;
    case overst: // ST ����� �����÷ο��� ���
        error_message = "Overflow";
        exit(0); // ���α׷� ����
    case illid: // input�� ���ڷ� �����ϴ� ���
        error_message = "Illegal Identifier";
        //nextfree = nextid;  // ���� identifier�� �ε����� ���� �ε����� �����Ͽ� identifier ����
        break;
    case illic: // ������ ���� ���ڰ� ��Ÿ�� ���
        error_message = "Illegal Character";
        break;
    case overlen: // identifier�� 12�� �̳��� �ƴ� ���
        error_message = "Too long identifier";
        break;
    }
}