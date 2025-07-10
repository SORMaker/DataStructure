#include "DoublyCircularLinkedList.h"

Status InitList(DCLinkList *L){
    *L = (DCLNode*)malloc(sizeof(DCLNode));
    if(!(*L)) return ERROR;
    (*L)->next = (*L);
    (*L)->prior = (*L);
    return OK;
}

Status GetElem(DCLinkList L, int i, ElemType *e){
    if(!L || L->next == L || i < 1) return ERROR;

    DCLNode* p = L->next;
    int j = 1;

    while (p != L && j < i)
    {
        p = p->next;
        j++;
    }

    if(p == L || j != i) return ERROR;

    (*e) = p->data;
    return OK;
}

DCLNode* LocateElem(DCLinkList L, ElemType e){
    if(!L || L->next == L) return NULL;

    DCLNode* p = L->next;
    while (p != L && p->data != e)
    {
        p = p->next;
    }
    return (p == L) ? NULL : p;
}

Status InsertElem(DCLinkList *L, int i, ElemType e){
    if(!L || i < 1) return ERROR;

    DCLNode* p = (*L);
    int j = 0;

    while (p->next != (*L) && j < i-1)
    {
        p = p->next;
        j++;
    }
    
    if(j != i-1) return ERROR;
    DCLNode* s = (DCLNode*)malloc(sizeof(DCLNode));
    if(!s) return OVERFLOW;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return OK;
}

Status DeleteElem(DCLinkList *L, int i){
    if(!L || (*L)->next == (*L) || i < 1) return ERROR;

    DCLNode* p = (*L);
    int j = 0;
    while (p->next != (*L) && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p->next == (*L) || j != i-1) return ERROR;
    DCLNode* q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return OK;
}

void DestroyList(DCLinkList *L){
    DCLNode* p = (*L)->next;
    DCLNode* temp = NULL;
    while (p != *L)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(*L);
    (*L) = NULL;
}