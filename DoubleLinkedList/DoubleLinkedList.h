#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode, *DuLinkList;

Status InitList(DuLinkList *L);
Status GetElem(DuLinkList L, int i, ElemType *e);
DuLNode* LocateElem(DuLinkList L, ElemType e);
Status InsertElem(DuLinkList *L, int i, ElemType e);
Status DeleteElem(DuLinkList *L, int i);
void DestroyList(DuLinkList *L);
Status CreateListFromHead(DuLinkList *L, int n);
Status CreateListFromRear(DuLinkList *L, int n);
ElemType InputDataFromKeyboard();
