//
// Created by sorrymaker on 2023/4/22.
//

#ifndef CODE_LINEARLIST_H
#define CODE_LINEARLIST_H



typedef struct lNode
{
    int data;
    struct lNode  *next;
}LNode, *LinkList;


int InitList(LinkList *L);
int getElement(LinkList L, unsigned int i, int *e);
LNode *locateElem(LinkList L, int e);
int linkListInsert(LinkList *L, int i, int e);
int deleteLinkList(LinkList *L, int i);
int createLinkList(LinkList *L,int n);
int destroyList(LinkList *L);
int clearList(LinkList *L);
int isListEmpty(LinkList L);
int listLength(LinkList L);
LNode *priorElem(LinkList L, int curElem);
LNode *nextElem(LinkList L, int curElem);
int traverseList(LinkList L);

#endif //CODE_LINEARLIST_H
