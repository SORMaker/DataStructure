#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct LNode
{
    ElemType data;

    struct LNode* next;
}LNode, *LinkList;

Status InitList(LinkList *L);
Status GetElem(LinkList L, int i, ElemType *e);
LNode* LocateElem(LinkList L, ElemType e);
Status InsertElem(LinkList *L, int i, ElemType e);
Status DeleteElem(LinkList *L, int i);
Status CreateListFromHead(LinkList *L, int n);
Status CreateListFromRear(LinkList *L, int n);
ElemType InputDataFromKeyboard();
void DestroyList(LinkList *L);
