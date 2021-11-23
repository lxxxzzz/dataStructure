//
//  main.c
//  栈-顺序存储结构
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
typedef struct Stack{
    ElemType data[MAXSIZE];
    int top;
}Stack;

Status push(Stack *s, ElemType e) {
    if (s == NULL) {
        return ERROR;
    }
    if (s->top > MAXSIZE - 1) {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    
    return OK;
}

Status pop(Stack *s, ElemType *e) {
    if (s == NULL) {
        return ERROR;
    }
    if (s->top == -1) {
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}

void stack_print(Stack s) {
    if (s.top == -1) {
        printf("空栈\n");
        return;
    }
    int k = 0;
    while (k <= s.top) {
        printf("%c \n", s.data[k]);
        k++;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    
    for (int i = 'a'; i <= 'g'; i++) {
        push(s, i);
    }
    
    stack_print(*s);
    
    ElemType e;
    pop(s, &e);
    
    stack_print(*s);
    
    return 0;
}
