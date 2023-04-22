#include <stdio.h>
#include "malloc.h"

#define OK 1
#define ERROR 0

typedef struct lNode
{
    int data;
    struct lNode  *next;
}LNode, *LinkList;

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

int InitList(LinkList *l)
{
    (*l) = (LinkList)malloc(sizeof(LNode));
    (*l)->data = 0;
    (*l)->next = NULL;
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
    }
    return OK;
    
}

int main() {
    LinkList la;
    LNode *p;
    int temp;
    createLinkList(&la,100);
    linkListInsert(&la,1,4);
    getElement(la,1,&temp);
    p = locateElem(la,1);
    deleteLinkList(&la,1);
    printf("temp:%d\n",temp);
    getchar();
    free(la);
    return 0;
}



