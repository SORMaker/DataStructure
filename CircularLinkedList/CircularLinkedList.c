#include "CircularLinkedList.h"

Status InitList(CLinkList *L){
    (*L) = (CLNode*)malloc(sizeof(CLNode));

    if (!L)
    {
        return ERROR;
    }
    

    (*L)->data = 0;
    (*L)->next = (*L);

    return OK;
}

Status GetElem(CLinkList L, int i, ElemType *e){
    CLNode* p = L->next;
    int j = 1;
    while ((p != L) && j < i )
    {
        p = p->next;
        j++;
    }
    if (p == L || j > i)
    {
        return ERROR;
    }
    (*e) = p->data;
    return OK;
}

CLNode* LocateElem(CLinkList L, ElemType e){
    CLNode* p = L->next;
    
    while (p != L && p->data != e)
    {
        p = p->next;
    }
    
    return p;
    
}

Status InsertElem(CLinkList *L, int i, ElemType e){
    CLNode* p = (*L);
    int j = 0;

    while (p->next != (*L) && j < i-1)
    {
        p = p->next;
        j++;
    }
    
    if (j != i-1)
    {
        return ERROR;
    }

    CLNode* s = (CLNode*)malloc(sizeof(CLNode));
    if(!s) return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return OK;
}

Status DeleteElem(CLinkList *L, int i){
    CLNode* p = (*L);
    int j = 0;

    while (j < i-1 && p->next != (*L))
    {
        p = p->next;
        j++;
    }

    if(p->next == *L || j > i-1) return ERROR;

    CLNode* q = p->next;
    p->next = q->next;
    free(q);

    return OK;
}

void DestroyList(CLinkList *L){
    CLNode* p = (*L)->next;
    CLNode* temp = NULL;
    while (p != *L)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(*L);
    *L = NULL;
}

Status CreateListFromHead(CLinkList *L, int n){
    Status status = InitList(L);
    if (status == ERROR)
    {
        return ERROR;
    }
    
    for (int i = 0; i < n; i++)
    {
        CLNode* p = (CLNode*)malloc(sizeof(CLNode));
        if (!p)
        {
            return ERROR;
        }
        
        InputDataFromKeyboard(p);
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return OK;
}

Status CreateListFromRear(CLinkList *L, int n){
    Status status = InitList(L);
    if (status == ERROR)
    {
        return ERROR;
    }
    CLNode* r = (*L);

    for (int i = 0; i < n; i++)
    {
        CLNode* p = (CLNode*)malloc(sizeof(CLNode));
        if (!p)
        {
            return ERROR;
        }
        
        InputDataFromKeyboard(p);
        p->next = (*L);
        r->next = p;
        r = p;
    }
    return OK;
}

void InputDataFromKeyboard(CLNode* node){
    scanf("%d", &node->data);
}