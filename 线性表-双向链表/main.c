//
//  main.c
//  线性表-双向链表
//
//  Created by 小红李 on 2021/11/14.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
    struct Node *prior;
}Node;
typedef Node *DoubleLinkList;

Status list_init(DoubleLinkList head, ElemType e[], int len) {
    if (head == NULL) {
        return ERROR;
    }
    DoubleLinkList p, q;
    int i;
    q = head;
    for (i = 0; i < len; i++) {
        p = malloc(sizeof(Node));
        p->data = e[i];
        p->prior = q;
        q->next = p;
        q = p;
    }
    return OK;
}

void list_delete(DoubleLinkList *L, int i, ElemType *e) {
    if (L == NULL) {
        return;
    }
    if (i < 1) {
        return;
    }
    DoubleLinkList p, q;
    int j;
    p = *L;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (j > i || p->next == NULL) {
        return;
    }
    q = p->next;
    *e = q->data;
    q->next->prior = p;
    p->next = q->next;
    free(q);
}

Status list_insert(DoubleLinkList *L, int i, ElemType e) {
    if (L == NULL) {
        return ERROR;
    }
    if (i < 1) {
        return ERROR;
    }
    DoubleLinkList prior, p, next;
    prior = *L;
    int k = 1;
    while (prior && k < i) {
        prior = prior->next;
        k++;
    }
    next = prior->next;
    p = malloc(sizeof(Node));
    p->data = e;
    p->next = next;
    p->prior = prior;
    prior->next = p;
    next->prior = p;

    return OK;
}

void list_print(DoubleLinkList L) {
    if (L == NULL) {
        return;
    }
    DoubleLinkList p;
    p = L->next;
    while (p) {
        printf("[%c]的上一个是[%c]，下一个是[%c]\n", p->data, p->prior ? p->prior->data : '\0', p->next ? p->next->data : '\0');
        
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    char e[] = {'a', 'b', 'c', 'd', 'e'};
    int len = sizeof(e) / sizeof(char);
    DoubleLinkList L = malloc(sizeof(Node));
    L->next = NULL;
    L->prior = NULL;
    list_init(L, e, len);
    list_print(L);
    
//    ElemType a;
//    int i = 3;
//    list_delete(&L, i, &a);
//    printf("删除的第%d个元素是%c\n", i , a);
//    list_print(L);

    list_insert(&L, 2, 'z');
    list_print(L);
    
    return 0;
}
