//
//  main.c
//  线性表-链式存储结构
//
//  Created by 小红李 on 2021/11/9.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

Status get_elem(LinkList list, int i, ElemType *e) {
    if (list == NULL)
        return ERROR;
    
    int k;
    LinkList p;
    p = list->next;
    k = 1;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if (k < i || p == NULL)
        return ERROR;
    
    *e = p->data;
    
    return OK;
}

Status list_insert(LinkList *list, int i, ElemType e) {
    int k;
    LinkList p, q;
    k = 1;
    p = *list;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    
    if (k > i || p == NULL) {
        return ERROR;
    }
    
    q = malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    
    return OK;
}

Status list_delete(LinkList *list, int i, ElemType *e) {
    int k;
    LinkList p, q;
    k = 1;
    p = *list;
    while (p->next && k < i) {
        p = p->next;
        k++;
    }
    
    if (!(p->next) || k > i) {
        return ERROR;
    }
    
    *e = p->data;
    q = p->next;
    p->next = p->next->next;
    
    free(q);
    
    return OK;
}

Status list_create(LinkList *list, ElemType a[], int len) {
    LinkList p, q;
    *list = (LinkList)malloc(sizeof(Node));
    if (list == NULL) {
        return ERROR;
    }
    q = *list;
    
    for (int i=0; i<len; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = a[i];
        p->next = NULL;
        q->next = p;

        q = p;
    }
    
    return OK;
}

Status list_create2(LinkList *list, ElemType a[], int len) {
    LinkList p, q;
    *list = (LinkList)malloc(sizeof(Node));
    if (list == NULL) {
        return ERROR;
    }
    q = *list;
    
    for (int i=0; i<len; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = a[i];
        q->next = p;

        q = p;
    }
    q->next = NULL;
    
    return OK;
}

Status list_create3(LinkList *list, ElemType a[], int len) {
    LinkList p;
    *list = (LinkList)malloc(sizeof(Node));
    if (list == NULL) {
        return ERROR;
    }
    (*list)->next = NULL;

    for (int i=0; i<len; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = a[i];
        p->next = (*list)->next;

        (*list)->next = p;
    }
    return OK;
}

void list_print(LinkList list) {
    LinkList p;
    p = list->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status list_clear(LinkList *list) {
    if (list == NULL) {
        return ERROR;
    }

    LinkList p, q;
    p = (*list)->next;
    while (p) {
//        q = p;
//        p = p->next;
//        free(q);
        q = p->next;
        free(p);
        p = q;
    }
    (*list)->next = NULL;
    return OK;
}

int main(int argc, const char * argv[]) {
    
    ElemType a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int len = sizeof(a) / sizeof(ElemType);
    
    LinkList list;
    list_create(&list, a, len);
    list_print(list);
    
//    list_insert(&list, 7, 'z');
//    list_print(list);
    
//    ElemType e;
//    list_delete(&list, 10, &e);
//    list_print(list);
    
    list_clear(&list);
    list_print(list);
    return 0;
}
