#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct CLNode   
{
    ElemType data;

    struct CLNode* next;
}CLNode, *CLinkList;

Status InitList(CLinkList *L);
Status GetElem(CLinkList L, int i, ElemType *e);
CLNode* LocateElem(CLinkList L, ElemType e);
Status InsertElem(CLinkList *L, int i, ElemType e);
Status DeleteElem(CLinkList *L, int i);
void DestroyList(CLinkList *L);
Status CreateListFromHead(CLinkList *L, int n);
Status CreateListFromRear(CLinkList *L, int n);
ElemType InputDataFromKeyboard();