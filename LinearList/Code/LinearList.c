//
// Created by sorrymaker on 2023/4/22.
//

#include "LinearList.h"
#include "malloc.h"
#include "stdio.h"

#define OK 1
#define ERROR 0
#define TRUE    1
#define FALSE   0


/*!
 * @brief   Create List
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  OK:1            Create LinkList successfully
 *
 * @note    Create LinkList head node
 *          headnode->data = 0
 *          headnode->next = NULL
 */

int InitList(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}

/*!
 * @brief   GetElement
 *
 * @param   Linklist        LinkList head pointer
 * @param   i               element position
 * @param   e               element value
 *
 * @return  OK:1            get element value
 *          ERROR:0         no matching value
 *
 * @note    Get element value
 */
int getElement(LinkList L, unsigned int i, int *e)
{
    LinkList p = L->next;
    int j = 1;
    while (j < i && p != NULL)
    {
        p = p->next;
        j++;
    }
    if(j>i || p == NULL)
    {
        return ERROR;
    }
    else
    {
        *e = p->data;
    }
    return OK;
}
/*!
 * @brief   locateElem
 *
 * @param   Linklist        LinkList head pointer
 * @param   e               element value
 *
 * @return  p               element address
 *
 * @note    locate element
 *          return element address
 *          if no matching values return NULL
 */
LNode *locateElem(LinkList L, int e)
{
    LinkList p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
/*!
 * @brief   linkListInsert
 *
 * @param   Linklist        LinkList head pointer
 * @param   i               element position
 * @param   e               element value
 *
 * @return  OK:1            Insert element
 *          ERROR:0         Insert failed
 *
 * @note    Insert element
 */
int linkListInsert(LinkList *L, int i, int e)
{
    LinkList p = (*L);
    int j = 0;
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if(p == NULL || j > i-1)
    {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
/*!
 * @brief   deleteLinkList
 *
 * @param   Linklist        LinkList head pointer
 * @param   i               element position
 *
 * @return  OK:1            Delete success
 *          ERROR:0         Delete fail
 *
 * @note    Delete element
 */
int deleteLinkList(LinkList *L, int i)
{
    LinkList p = (*L);
    int j = 0;
    while (j < i-1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j > i-1 || p->next == NULL)
    {
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    q->next = NULL;
    free(q);
    return OK;
}
/*!
 * @brief   createLinkList
 *
 * @param   Linklist        LinkList head pointer
 * @param   n               element num
 *
 * @return  OK:1            Create success
 *
 * @note    Create LinkList
 *          forward interpolation to create LinkList
 */
int createLinkList(LinkList *L,int n)
{
    InitList(L);
    LinkList p = *L;
    for (int i = 0; i < n; ++i)
    {
        LinkList q = (LinkList)malloc(sizeof(LNode));
        q->data = i;
        q->next = p->next;
        p->next = q;
        (*L)->data++;
    }
    return OK;
}

/*!
 * @brief   destoryList
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  OK:1            Destory success
 *
 * @note    Destory LinkList
 *          free ram
 */
int destroyList(LinkList *L)
{
    LinkList p = (*L);
    LinkList q = NULL;
    while (p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(p);
    return OK;
}
/*!
 * @brief   clearList
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  OK:1            Clear success
 *
 * @note    Clear LinkList
 */
int clearList(LinkList *L)
{
    LinkList p = (*L);
    LinkList q = NULL;
    while (p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    return OK;
}
/*!
 * @brief   isListEmpty
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  TRUE:1            List is Empty
 *
 * @note    Determine whether LinkList is empty
 */
int isListEmpty(LinkList L)
{
    LinkList p = L;
    if(p->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*!
 * @brief   listLength
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  num             LinkList's length
 *
 * @note
 */
int listLength(LinkList L)
{
    LinkList p = L;
    int num = 0;
    while (p->next != NULL)
    {
        p = p->next;
        num++;
    }
    return num;
}
/*!
 * @brief   priorElem
 *
 * @param   Linklist        LinkList head pointer
 * @param   curElem         LinkList's data
 *
 * @return  LNode*           LNode address
 *
 * @note    return curElem's pre-Node
 */
LNode *priorElem(LinkList L, int curElem)
{
    LinkList p = L->next;
    LNode *preElem = L;
    if(p->data == curElem)
    {
        printf("is first Element\n");
        return NULL;
    }
    while (p->data != curElem && p->next != NULL)
    {
        preElem = p;
        p = p->next;
    }
    if(p->next == NULL || p->data != curElem)
    {
        return NULL;
    }
    return preElem;
}
/*!
 * @brief   nextElem
 *
 * @param   Linklist        LinkList head pointer
 * @param   curElem         LinkList's data
 *
 * @return  LNode*           LNode address
 *
 * @note    return curElem's next-Node
 */
LNode *nextElem(LinkList L, int curElem)
{
    LinkList p = L;
    LNode *nextElem = L->next;
    
    while (p->data != curElem && nextElem->next != NULL)
    {
        p = nextElem;
        nextElem = nextElem->next;
    }
    
    if(nextElem->next == NULL || p->data != curElem)
    {
        return NULL;
    }
    return nextElem;
}
/*!
 * @brief   traverseList
 *
 * @param   Linklist        LinkList head pointer
 *
 * @return  OK:1            Traverse success
 *
 * @note    Traverse the whole List
 */
int traverseList(LinkList L)
{
    LinkList p = L;
    int num = 0;
    while (p->next != NULL)
    {
        p = p->next;
        num++;
    }
    
    if(L->data == num)
    {
        return OK;
    }
    return ERROR;
}
