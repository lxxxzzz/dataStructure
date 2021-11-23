//
//  calculate.c
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/16.
//

#include "calculate.h"
#include <math.h>

int is_symbol(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int char_to_int(char *c) {
    
    LinkStack *stack = malloc(sizeof(LinkStack));
    stack->count = 0;
    stack->top = NULL;
    while (*c) {
        if (*c >= '0' && *c <= '9') {
            push(stack, (*c - '0'));
        } else if (*c == ' ' || *c == '\n') {
            if (stack->count) {
                int a;
                a = stack_to_int(stack);
                printf("%d\n", a);
            }
        }
        c++;
    }
    if (stack->count) {
        int a;
        a = stack_to_int(stack);
        printf("%d\n", a);
    }
    return 0;
}

int stack_to_int(LinkStack *stack) {
    int j, k;
    j = k = 0;
    while (stack->top) {
        char e;
        pop(stack, &e);
        j = j + e * pow(10, k);
        k++;
    }
    return j;
}

void z_2_h(char *c, char *h) {
    LinkStack *num_stack, *exp_stack;
    exp_stack = num_stack = malloc(sizeof(LinkStack));
    num_stack->count = 0;
    num_stack->top = NULL;
    
    exp_stack->count = 0;
    exp_stack->top = NULL;
    
    while (*c) {
        if (*c >= '0' && *c <= '9') {
            printf("%c", *c);
        } else if ('+' == *c || '-' == *c) {

        }
        c++;
    }
    if (num_stack->count) {
        int a;
        a = stack_to_int(num_stack);
        printf("%d\n", a);
    }
}
