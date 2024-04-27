#include "glob.h"

HTpointer HT[HTsize];
char ST[STsize];
int hashcode = 0;
int sameid = 0;
bool found = false;

// �ؽ� ���̺��� ����ϴ� �Լ�
void PrintHStable() {
    int i, j;
    HTpointer here; // ���� ��带 ����ų ������

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) { // ��尡 �����ϸ�
            for (here = HT[i]; here != NULL; here = here->next) { // ���� ����Ʈ�� ��� ��� �湮
                j = here->index; // ���� ����� identifier ���� �ε���
                while (ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]); // identifier ���� �ϳ��� ���
                printf("    ");
            }
            printf("\n");
        }
    }
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

void SymbolTable() {
    
    ERRORtypes error;
    if (nextfree == STsize) { // ST�� �� �� ���
        error = overst; // overst(�����÷ο�)�� ���� ����
        ReportError(error);
    }
    ComputeHS(nextid, nextfree); // �ؽ��ڵ� ���
    LookupHS(nextid, hashcode); // �ؽ� ���̺��� identifier ��ȸ
    if (!found) { // �ؽ� ���̺� ������ identifier�� �������� �ʴ� ���
        printf("%6d        ", nextid); // identifier �ε��� ���
        printf("          "); // ������ ���� ����
        for (int i = nextid; i < nextfree - 1; i++) {
            printf("%c", ST[i]); // identifier ���
        }
        // ��� ������ ���� ���� �߰�
        // �ִ� ���̸� 20���ڷ� �����ϰ�, (20 - (nextfree - nextid)��ŭ ���� �߰�
        for (int j = 0; j < 20 - (nextfree - nextid); j++) {
            printf(" ");
        }
        ADDHT(hashcode); // �ؽ� ���̺� �߰�
    }
    else { // �ؽ� ���̺� identifier�� �̹� �����ϴ� ���
        printf("%6d        ", sameid); // ������ identifier�� �ε��� ���
        printf("          "); // ������ ���� ����
        for (int i = nextid; i < nextfree - 1; i++) {
            printf("%c", ST[i]); // identifier ���
        }
        // ��� ������ ���� ���� �߰�
        // �ִ� ���̸� 20���ڷ� �����ϰ�, (20 - (nextfree - nextid)��ŭ ���� �߰�
        for (int j = 0; j < 20 - (nextfree - nextid); j++) {
            printf(" ");
        }
        nextfree = nextid; // �ε��� �ʱ�ȭ
    }
    PrintHStable();
}