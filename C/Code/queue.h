//
// Created by sorrymaker on 2023/4/23.
//

#ifndef CODE_QUEUE_H
#define CODE_QUEUE_H

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


int InitQueue(LinkQueue *Q);
int enQueue(LinkQueue *Q, int Elem);
int deQueue(LinkQueue *Q, int *Elem);
int getHead(LinkQueue Q, int *Elem);
int destroyQueue(LinkQueue *Q);
int clearQueue(LinkQueue *Q);
int queueIsEmpty(LinkQueue Q);
int queueLength(LinkQueue Q);

#endif //CODE_QUEUE_H
