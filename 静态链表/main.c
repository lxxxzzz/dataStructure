//
//  main.c
//  静态链表
//
//  Created by 小红李 on 2021/11/9.
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

Status list_insert(StaticLinkList space, int i, ElemType e) {
    int j;
    j = list_alloc(space);
    
    if (j) {
        
    }
    
    return ERROR;
}

int main(int argc, const char * argv[]) {

    StaticLinkList space;
    list_init(space);
    
    list_insert(space, 1, 'A');
    
    return 0;
}
