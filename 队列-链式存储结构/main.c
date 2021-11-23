//
//  main.c
//  队列-链式存储结构
//
//  Created by 小红李 on 2021/11/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(int argc, const char * argv[]) {

    Queue *q = (Queue *)malloc(sizeof(Queue));
    queue_init(q);
    queue_print(*q);
    
    queue_enter(q, 'a');
    queue_enter(q, 'b');
    queue_enter(q, 'c');
    queue_enter(q, 'd');
    queue_print(*q);
    
    ElemType e;
    queue_out(q, &e);
    printf("%c出队列了\n", e);
    queue_print(*q);
    
    return 0;
}
