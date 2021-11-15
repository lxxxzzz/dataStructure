//
//  main.c
//  线性表-循环链表
//
//  Created by 小红李 on 2021/11/11.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char * ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;
typedef Node *LinkList;

void list_print(LinkList L) {
    if (L == NULL) {
        return;
    }
    if (L->next == L) {
        printf("空链表\n");
        return;
    }
    LinkList p;
    p = L;
    while (p->next != L) {
        p = p->next;
        printf("%s ", p->data);
    }
    printf("\n");
}

int list_cycle(LinkList list) {
    LinkList fast, slow;
    int r;
    fast = slow = list;
    r = 0;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
        if (fast == slow) {
            r = 1;
            break;
        }
    }
    
    return r;
}

void list_last_node(LinkList L, LinkList *node) {
    if (L->next == L) {
        printf("空链表");
        return;
    }
    LinkList p;
    p = L;
    while (p->next != L) {
        p = p->next;
    }
    *node = p;
}

Status list_create(LinkList *list, ElemType a[], int len) {
    LinkList p, q;
    *list = (LinkList)malloc(sizeof(Node));
    if (list == NULL) {
        return ERROR;
    }
    (*list)->next = NULL;
    q = *list;
    
    for (int i=0; i<len; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = a[i];
        p->next = NULL;
        q->next = p;

        q = p;
    }
    q->next = *list;
    return OK;
}

void list_delete(LinkList *list, int i, ElemType *e) {
    if (list == NULL) {
        return;
    }
    if (i < 1) {
        return;
    }
    LinkList p, q;
    int j;
    p = *list;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (j > i || p->next == NULL) {
        // 没有查到
        return;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
}

int main(int argc, const char * argv[]) {
    char *a[] = {"张三", "李四", "王麻子", "王五", "哈哈"};
//    char *a[] = {};
    int len = sizeof(a) / sizeof(char *);
    LinkList list;
    list_create(&list, a, len);
    list_print(list);
    
//    LinkList node;
//    list_last_node(list, &node);
//    printf("最后一个节点是[%s]\n", node->data);
    
    ElemType e;
    int i;
    i = 5;
    list_delete(&list, i, &e);
    printf("删除的第%d个元素是%s\n", i, e);
    list_print(list);
    
    int result = list_cycle(list);
    printf("链表%s\n", result == 1 ? "存在环" : "不存在环");
    
    return 0;
}
