#include "SeqList.h"

Status InitList(SqList *L){
    L->elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    if (!L->elem)
    {
        exit(OVERFLOW);
    }
    L->length = 0;
    return OK;
}

Status GetElem(SqList L, int i, ElemType *e){
    if (i < 1 || i > L.length) 
    {
        return ERROR;
    }
    e = L.elem[i-1];
    return OK;
}

int LocateElem(SqList L, ElemType e){
    for(int i = 0;i < L.length;i++){
        if (e == L.elem[i])
        {
            return i + 1;
        }
    }
    return 0;
}

Status InsertElem(SqList *L, int i, ElemType e){
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }

    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    
    for(int j = L->length-1;j>=i-1;j--){
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i-1] = e;
    L->length++;
    return OK;
}

Status DeleteElem(SqList *L, int i){
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    for(int j=i;j<L->length-1;j++){
        L->elem[j-1] = L->elem[j];
    }
    L->length--;
    return OK;
}
