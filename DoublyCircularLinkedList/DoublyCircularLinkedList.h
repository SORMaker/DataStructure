#include "stdio.h"
#include "stdlib.h"
#include "common.h"

typedef struct DCLNode
{
    ElemType data;
    struct DCLNode* prior;
    struct DCLNode* next;
}DCLNode,*DCLinkList;


Status InitList(DCLinkList *L);
Status GetElem(DCLinkList L, int i, ElemType *e);
DCLNode* LocateElem(DCLinkList L, ElemType e);
Status InsertElem(DCLinkList *L, int i, ElemType e);
Status DeleteElem(DCLinkList *L, int i);
void DestroyList(DCLinkList *L);