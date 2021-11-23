//
//  queue.c
//  队列-链式存储结构
//
//  Created by 小红李 on 2021/11/23.
//

#include "queue.h"

Status queue_init(Queue *Q) {
    if (Q == NULL) {
        return ERROR;
    }
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(Node));
    return OK;
}

int queue_length(Queue Q) {
    if (Q.rear == Q.front) {
        return 0;
    }
    
    int k;
    QueuePtr p;
    k = 0;
    p = Q.front;
    while (p != Q.rear) {
        p = p->next;
        k++;
    }
    return k;
}

Status queue_enter(Queue *Q, ElemType e) {
    if (Q == NULL) {
        return ERROR;
    }
    QueuePtr p = (QueuePtr)malloc(sizeof(Node));
    if (p == NULL) {
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status queue_out(Queue *Q, ElemType *e) {
    if (Q == NULL) {
        return ERROR;
    }
    if (Q->rear == Q->front) {
        return ERROR;
    }
    
    QueuePtr p;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    free(p);
    
    return OK;
}

void queue_print(Queue Q) {
    if (Q.front == Q.rear) {
        printf("空队列\n");
        return;
    }
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
