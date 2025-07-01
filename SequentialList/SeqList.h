#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXSIZE 100

typedef struct 
{
    ElemType* elem;
    int length;
}SqList;

Status InitList(SqList *L);
Status GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e);
Status InsertElem(SqList *L, int i, ElemType e);
Status DeleteElem(SqList *L, int i);