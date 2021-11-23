//
//  main.c
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "fbi.h"
#include "calculate.h"
#include "stack.h"
#include "match.h"

int main(int argc, const char * argv[]) {
//    printf("%d\n", f(15));
//    printf("%d\n", f2(15));
//    printf("%d\n", f3(15));

//    LinkStack *stack = malloc(sizeof(LinkStack));
//    stack->count = 0;
//    stack->top = NULL;
//    for (int i = 'a'; i <= 'g'; i++) {
//        push(stack, i);
//    }
//    stack_print(*stack);
//
//    ElemType e;
//    pop(stack, &e);
//    printf("pop的元素是%c\n", e);
//    stack_print(*stack);

    bool r = match("{({()})}");
    if (r) {
        printf("匹配\n");
    } else {
        printf("不匹配\n");
    }
    
    return 0;
}
