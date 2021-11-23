//
//  stack.h
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/16.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;

Status push(LinkStack *s, ElemType e);
Status pop(LinkStack *s, ElemType *e);
void stack_print(LinkStack s);

#endif /* stack_h */
