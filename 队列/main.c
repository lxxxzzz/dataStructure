//
//  main.c
//  队列
//
//  Created by 小红李 on 2021/11/23.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define OK 1
#define ERROR 0

typedef int Status;
typedef int QElemType;


typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status queue_init(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int queue_length(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status queue_enter(SqQueue *Q, QElemType e) {
    if (Q == NULL || ((Q->rear+1) % MAXSIZE) == Q->front) {
        return ERROR;
    }
    
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAXSIZE;
    
    return OK;
}

Status queue_out(SqQueue *Q, QElemType *e) {
    if (Q == NULL) {
        return ERROR;
    }
    
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % MAXSIZE;
    
    return OK;
}

int main(int argc, const char * argv[]) {

    return 0;
}
