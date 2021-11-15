//
//  main.c
//  线性表-静态链表
//
//  Created by 小红李 on 2021/11/11.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

Status list_init(StaticLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE-1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE-1].cur = 0;
    return OK;
}

int list_alloc(StaticLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    
    return i;
}

Status list_free(StaticLinkList L, int i) {
    // i = 4
    if (i < 1 || i > MAXSIZE-1) {
        return ERROR;
    }
    L[i].cur = L[0].cur;
    L[0].cur = i;
    return OK;
}

Status list_insert(StaticLinkList L, int i, ElemType e) {
    int j, k, l;
    k = MAXSIZE - 1;
    
    if (i < 1 || i > MAXSIZE) {
        return ERROR;
    }
    
    j = list_alloc(L);
    
    if (j) {
        L[j].data = e;
        for (l = 1; l < i; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    
    return ERROR;
}

Status list_delete(StaticLinkList L, int i) {
    if (i < 1 || i > MAXSIZE) {
        return ERROR;
    }
    int l, k;
    k = MAXSIZE - 1;
    for (l = 1; l < i; l++) {
        k = L[k].cur;
    }
    L[k].cur = L[i].cur;
    list_free(L, i);
    return OK;
}

int list_len(StaticLinkList L) {
    int cur, c;
    cur = L[MAXSIZE-1].cur;
    c = 0;
    while (cur) {
        c++;
        cur = L[cur].cur;
    }
    return c;
}

void list_print(StaticLinkList L) {
    int cur = L[MAXSIZE-1].cur;
    while (cur) {
        printf("%c", L[cur].data);
        cur = L[cur].cur;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    StaticLinkList L;
    list_init(L);
    
    int a[] = {'a', 'b', 'c', 'd', 'e'};
    int len = sizeof(a) / sizeof(int);
    for (int i=0; i<len; i++) {
        list_insert(L, i + 1, a[i]);
    }
    list_print(L);
    
//    list_insert(L, 3, 'z');
//    list_print(L);
    
    list_delete(L, 2);
    list_print(L);
    
    return 0;
}
