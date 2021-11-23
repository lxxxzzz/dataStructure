//
//  main.c
//  栈-共享栈空间
//
//  Created by 小红李 on 2021/11/15.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct SharedStack{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}SharedStack;

Status push(SharedStack *s, ElemType e, int n) {
    if (s == NULL) {
        return ERROR;
    }
    if (s->top1 + 1 == s->top2) {
        return ERROR;
    }
    if (n == 1) {
        s->top1++;
        s->data[s->top1] = e;
    } else if (n == 2) {
        s->top2++;
        s->data[s->top2] = e;
    }
    return OK;
}

Status pop(SharedStack *s, ElemType *e, int n) {
    if (s == NULL) {
        return ERROR;
    }
    if (n == 1 ) {
        if (s->top1 == -1) {
            return ERROR;
        }
        *e = s->data[s->top1];
        s->top1--;
    } else if (n == 2) {
        if (s->top2 == MAXSIZE - 1) {
            return ERROR;
        }
        *e = s->data[s->top2];
        s->top2++;
    }

    return OK;
}

int main(int argc, const char * argv[]) {

    return 0;
}
