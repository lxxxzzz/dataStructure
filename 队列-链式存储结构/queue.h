//
//  queue.h
//  队列-链式存储结构
//
//  Created by 小红李 on 2021/11/23.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
}Node, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}Queue;

Status queue_init(Queue *Q);
int queue_length(Queue Q);
Status queue_enter(Queue *Q, ElemType e);
Status queue_out(Queue *Q, ElemType *e);
void queue_print(Queue Q);

#endif /* queue_h */
