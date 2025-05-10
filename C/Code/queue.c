//
// Created by sorrymaker on 2023/4/23.
//
#include "queue.h"
#include "common.h"
#include "malloc.h"

/*!
 * @brief   InitQueue
 *
 * @param   LinkQueue        Queue head pointer
 *
 * @return  OK:1            Init success
 *
 * @note
 */
int InitQueue(LinkQueue *Q)
{
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    (*Q).front->next = NULL;
    return OK;
}
/*!
 * @brief   enQueue
 *
 * @param   LinkQueue        Queue head pointer
 * @param   Elem             Enter Queue Element
 *
 * @return  OK:1             Enter success
 *
 * @note
 */
int enQueue(LinkQueue *Q, int Elem)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->data = Elem;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
    (*Q).rear->next = NULL;
    return OK;
}
/*!
 * @brief   deQueue
 *
 * @param   LinkQueue        Queue head pointer
 * @param   Elem             Delete Queue Element
 *
 * @return  OK:1             Delete success
 *
 * @note
 */
int deQueue(LinkQueue *Q, int *Elem)
{
    if((*Q).front == (*Q).rear)
    {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *Elem = p->data;
    (*Q).front->next = p->next;
    if((*Q).rear == p)
    {
        (*Q).rear = (*Q).front;
        (*Q).rear->next = NULL;
    }
    free(p);
}
/*!
 * @brief   getHead
 *
 * @param   LinkQueue        Queue head pointer
 * @param   Elem             Queue head Element
 *
 * @return  OK:1             get success
 *
 * @note
 */
int getHead(LinkQueue Q, int *Elem)
{
    if(Q.front != Q.rear)
    {
        *Elem =  Q.front->next->data;
        return OK;
    }
    return ERROR;
}
/*!
 * @brief   destroyQueue
 *
 * @param   LinkQueue        Queue head pointer
 *
 * @return  OK:1             destroy success
 *
 * @note
 */
int destroyQueue(LinkQueue *Q)
{
    if((*Q).front == (*Q).rear)
    {
        free(Q->front);
        return OK;
    }
    QueuePtr p = NULL;
    while ((*Q).front->next != (*Q).rear)
    {
        p = (*Q).front->next;
        (*Q).front->next = p->next;
        free(p);
    }
    p = (*Q).rear;
    free(p);
    (*Q).rear->next = NULL;
    free(Q->front);
    return OK;
}
/*!
 * @brief   clearQueue
 *
 * @param   LinkQueue        Queue head pointer
 *
 * @return  OK:1             clear success
 *
 * @note
 */
int clearQueue(LinkQueue *Q)
{
    if((*Q).front == (*Q).rear)
    {
        return ERROR;
    }
    QueuePtr p = NULL;
    while ((*Q).front->next != (*Q).rear)
    {
        p = (*Q).front->next;
        (*Q).front->next = p->next;
        free(p);
    }
    p = (*Q).rear;
    free(p);
    (*Q).rear = (*Q).front;
    (*Q).rear->next = NULL;
}
/*!
 * @brief   queueIsEmpty
 *
 * @param   LinkQueue        Queue head pointer
 *
 * @return  TRUE:1           Queue is empty
 *
 * @note
 */
int queueIsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
    {
        return TRUE;
    }
    return FALSE;
}
/*!
 * @brief   queueLength
 *
 * @param   LinkQueue        Queue head pointer
 *
 * @return  length           Queue's length
 *
 * @note
 */
int queueLength(LinkQueue Q)
{
    int length = 0;
    if(Q.front == Q.rear)
    {
        return 0;
    }
    while (Q.front->next != Q.rear)
    {
        Q.front->next = Q.front->next->next;
        length++;
    }
    return length+1;
}


