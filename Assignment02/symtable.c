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

// Hashcode�� ����ϴ� �Լ�
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0;
    for (i = nid; i < nfree - 1; i++) { // nid���� nfree-1 ������ ���ڿ� ����
        code += (int)ST[i]; // �ƽ�Ű �ڵ尪 ��
    }
    hashcode = code % HTsize; // �ؽ��ڵ尪 ���
}

// �ؽ����̺��� ���� ���� identifier�� �����ϴ��� �Ǵ��ϴ� �Լ�
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;

    found = false; // �ʱ�ȭ
    if (HT[hscode] != NULL) { // �ؽ����̺��� �ش� �ؽ��ڵ忡 ���� ������
        here = HT[hscode]; // �ش� �ؽ��ڵ��� ù ��° ��� ��������
        while (here != NULL && found == false) { // ���ڰ� �����ϰ� identifier�� �߰ߵ��� ���� ���
            found = true;
            i = here->index; // ���� ����� identifier �ε���
            j = nid; // �а��ִ� identifier�� ���� �ε���
            sameid = i; // ���� identifier �ε��� ����

            while (ST[i] != '\0' && ST[j] != '\0' && found == true) {   // ���ڸ� ���ϸ� identifier ��ġ ���� �Ǵ�
                if (ST[i] != ST[j]) // ���ڰ� �ٸ���
                    found = false;
                else { // ���� ���ڷ� �̵�
                    i++;
                    j++;
                }
            }
            here = here->next;  // ���� ����Ʈ�� ���� identifier�� �̵�
        }
    }
}

// �ؽ� ���̺� identifier�� �߰��ϴ� �Լ�
void ADDHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr)); // ���ο� ��� ���� �Ҵ�
    ptr->index = nextid; // ���� identifier�� �ε��� ����
    ptr->next = HT[hscode]; // �� ����� ���� ��带 ���� �ؽ��ڵ��� ù ��° ���� ����
    HT[hscode] = ptr; // ���� ����Ʈ�� identifier ����
}

void SymbolTable(char* ident) {   
    ERRORtypes error;
    ReadID(ident);
    if (nextfree == STsize) { // ST�� �� �� ���
        error = overst; // overst(�����÷ο�)�� ���� ����
        ReportError(error);
    }
    ComputeHS(nextid, nextfree); // �ؽ��ڵ� ���
    LookupHS(nextid, hashcode); // �ؽ� ���̺��� identifier ��ȸ
    if (!found) { // �ؽ� ���̺� ������ identifier�� �������� �ʴ� ���
        ADDHT(hashcode); // �ؽ� ���̺� �߰�
    }
    else { // �ؽ� ���̺� identifier�� �̹� �����ϴ� ���
        nextfree = nextid; // �ε��� �ʱ�ȭ
    }
}