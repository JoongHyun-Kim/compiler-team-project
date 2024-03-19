#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS

#define FILE_NAME "testdata6.txt"
#define STsize 1000        // size of string table
#define HTsize 100        // size of hash table
#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || (x) == '_')
#define isDigit(x) ((x) >= '0' && (x) <= '9')

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;        // index of identifier in ST
    HTpointer next;    // pointer to next identifier
} HTentry;

enum errorTypes { noerror, illsp, illid, overst, overlen };
typedef enum errorTypes ERRORtypes;

char separators[] = " .,;:?!\t\n";

HTpointer HT[HTsize];
char ST[STsize];

ERRORtypes error;

int nextid = 0;
int nextfree = 0;

int hashcode;
int sameid;

bool found;

FILE* fp;    // to be a pointer to FILE
char input;

// Init
void initialize() {
    fp = fopen(FILE_NAME, "r");
    input = fgetc(fp);
}

// separator check
bool isSeparator(char input) {
    int i;
    unsigned long sep_len;

    sep_len = strlen(separators);
    for (i = 0; i < sep_len; i++) {
        if (input == separators[i]) {
            return true;
        }
    }
    return false;
}

void PrintHeading() {
    printf("--------------       ------------\n");
    printf(" Index in ST           identifier \n");
    printf("--------------       ------------\n");
}

// Print HStable
void PrintHStable() {
    int i, j;
    HTpointer here;

    printf("\n\n\n\n\n [[ HASH TABLE ]] \n\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            printf(" Hash Code %3d : ", i);
            for (here = HT[i]; here != NULL; here = here->next) {
                j = here->index;
                while (ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]);
                printf("    ");
            }
            printf("\n");
        }

    }

    printf("\n\n\n < %5d characters are used in the string table > \n", nextfree);

}

// PrintError
void PrintError(ERRORtypes error) {
    switch (error) {
        case noerror:
            break;
        case overst:
            printf("...Error...         OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
        case illsp:    // illegal separator
            printf("...Error...         %c is illegal separator \n", input);
            break;
        case illid:    // illegal identifier
            printf("...Error...     ");
            if(isDigit(input)) {
                while (input != EOF && (isLetter(input) || isDigit(input))) {
                    printf("%c", input);
                    input = fgetc(fp);
                }
                printf("        start with digit \n");
            } else {
                char illic = input;
                int i;
                for(i = nextid; i < nextfree; i++) {
                    printf("%c", ST[i]);
                }
                while (input != EOF && (isLetter(input) || isDigit(input))) {
                    printf("%c", input);
                    input = fgetc(fp);
                }
                printf("        %c Is not allowed \n", illic);
            }
            nextfree = nextid;
            break;
        case overlen:
            printf("...Error...     ");
            int j;
            for (j = nextid; j < nextfree; j++) {
                printf("%c", ST[j]);
            }
            printf("        too long identifier \n");
            break;
    }
}

// Skip Separators
void SkipSeparators() {
    while (input != EOF && !(isLetter(input) || isDigit(input))) {
        if (!isSeparator(input)) {
            error = illsp;
            PrintError(error);
        }
        input = fgetc(fp);
    }
}

// ReadID
void ReadID() {
    nextid = nextfree;
    if (isDigit(input)) {
        error = illid;
        PrintError(error);
    }
    else {
        while (input != EOF && !isSeparator(input)) {
            if (nextfree == STsize) {
                error = overst;
                PrintError(error);
            }
            if(!(isLetter(input) || isDigit(input))){
                error = illid;
                PrintError(error);
            }
            if(nextfree - nextid < 12) {
                ST[nextfree++] = input;
            }
            input = fgetc(fp);
        }
        if (nextfree - nextid > 11) {
            error = overlen;
            PrintError(error);
        }
        ST[nextfree++] = '\0';
    }
}

// ComputeHS
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0;
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i];
    }
    hashcode = code % HTsize;
}

// LookupHS
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;

    found = false;
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        while (here != NULL && found == false) {
            found = true;
            i = here->index;
            j = nid;
            sameid = i;

            while (ST[i] != '\0' && ST[j] != '\0' && found == true) {
                if (ST[i] != ST[j])
                    found = false;
                else {
                    i++;
                    j++;
                }
            }
            here = here->next;
        }
    }
}

// ADDHT
void ADDHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr));
    ptr->index = nextid;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
}

int main() {
    int i;
    PrintHeading();
    initialize();

    while (input != EOF) {
        error = noerror;
        SkipSeparators();
        ReadID();
        if (input != EOF && error == noerror) {
            if (nextfree == STsize) {
                error = overst;
                PrintError(error);
            }
            ST[nextfree++] = '\0';
            ComputeHS(nextid, nextfree);
            LookupHS(nextid, hashcode);

            if (!found) {   // add to hashtable
                printf("%6d     ", nextid);
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]);
                }
                printf("    (entered)\n");
                ADDHT(hashcode);
            }
            else {
                printf("%6d     ", sameid);
                for (i = nextid; i < nextfree - 1; i++) {
                    printf("%c", ST[i]);
                }
                printf("    (already existed)\n");
                nextfree = nextid;
            }
            
        }
        SkipSeparators();
    }
    // 마지막 문자 출력용 스파게티코드...
    if (nextid < nextfree) {
        ComputeHS(nextid, nextfree);
        LookupHS(nextid, hashcode);
        if (!found) {
            printf("%6d     ", nextid);
            for (i = nextid; i < nextfree - 1; i++) {
                printf("%c", ST[i]);
            }
            printf("    (entered)\n");
            ADDHT(hashcode);
        }
    }
    PrintHStable();
    printf("김중현/2076088, 곽서진/2076016, 김선영/2071010, 이나현/2076292");
}
