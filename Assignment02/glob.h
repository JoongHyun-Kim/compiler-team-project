#include <stdlib.h>
#include <stdbool.h>

#define STsize 1000 // ���ڿ� ���̺� ũ��
#define HTsize 100 // �ؽ� ���̺� ũ��
#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || (x) == '_') // ���� ���� Ȯ��
#define isDigit(x) ((x) >= '0' && (x) <= '9') // ���� ���� Ȯ��

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // ST���� identifier�� �ε���
    HTpointer next; // ���� identifier�� ����Ű�� ������
} HTentry;

enum errorTypes { noerror, illid, illic, overst, overlen }; // ���� ���� enum���� ����
typedef enum errorTypes ERRORtypes;

extern HTpointer HT[HTsize];
extern char ST[STsize];

extern int nextid; // ���� identifier �ε���
extern int nextfree; // ST���� ���� available�� �ε���

extern int hashcode; // identifier�� �ؽ��ڵ�
extern int sameid; // ���� �ĺ����� ù �ε���

extern bool found;  // identifier�� ���� ���� ����

extern int lineNum; // �� ��ȣ
extern int cErrors; // ���� ����
extern char *error_message; // ���� �޼���
