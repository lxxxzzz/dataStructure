//
//  stack.c
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/16.
//

#include "stack.h"

Status push(LinkStack *s, ElemType e) {
    LinkStackPtr p = malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    
    return OK;
}

Status pop(LinkStack *s, ElemType *e) {
    LinkStackPtr p;
    p = s->top;
    *e = p->data;
    s->top = s->top->next;
    s->count--;
    free(p);
    
    return OK;
}

void stack_print(LinkStack s) {
    if (s.top == NULL || s.count == 0) {
        printf("空栈\n");
        return;
    }
    LinkStackPtr p;
    p = s.top;
    while (p) {
        printf("%c \n", p->data);
        p = p->next;
    }
    printf("\n");
}
