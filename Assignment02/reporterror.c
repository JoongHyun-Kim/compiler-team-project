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
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// ��� ������ ���� ���� �߰�
        //// �ִ� ���̸� 20���ڷ� �����ϰ�, (20 - (nextfree - nextid)��ŭ ���� �߰�
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //printf("start with digit\n");
        error_message = "Illegal Identifier";
        //nextfree = nextid;  // ���� identifier�� �ε����� ���� �ε����� �����Ͽ� identifier ����
        break;
    case illic: // ������ ���� ���ڰ� ��Ÿ�� ���
        //char illic = '\0';  // ������ ���� ���ڸ� ������ ����
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// ��� ������ ���� ���� �߰�
        //// �ִ� ���̸� 20���ڷ� �����ϰ�, (20 - (nextfree - nextid)��ŭ ���� �߰�
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //for (i = nextid; i < nextfree - 1; i++) {
        //    if (!(isDigit(ST[i]) || isLetter(ST[i])))   // ���ڰ� ���ڳ� �����ڰ� �ƴ� ���
        //        illic = ST[i];
        //}
        //printf("%c Is not allowed\n", illic);
        error_message = "Illegal Character";
        //nextfree = nextid;
        break;
    case overlen: // identifier�� 12�� �̳��� �ƴ� ���
        //for (i = nextid; i < nextfree - 1; i++) {
        //    printf("%c", ST[i]);
        //}
        //// ��� ������ ���� ���� �߰�
        //// �ִ� ���̸� 20���ڷ� �����ϰ�, (20 - (nextfree - nextid)��ŭ ���� �߰�
        //for (int j = 0; j < 20 - (nextfree - nextid); j++) {
        //    printf(" ");
        //}
        //printf("too long identifier\n");
        error_message = "Too long identifier";
        //nextfree = nextid;
        break;
    }
}