#include "LinkedList.h"

Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        return ERROR;
    }
    
    (*L)->next = NULL;
    return OK;
}

Status GetElem(LinkList L, int i, ElemType *e){
    LNode* p = L->next;

    int j = 1;
    while ((p!=NULL) && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

LNode* LocateElem(LinkList L, ElemType e){
    LNode* p = L->next;

    while (p && p->data != e)
    {
        p = p->next;
    }

    return p;
}

Status InsertElem(LinkList *L, int i, ElemType e){
    LNode* p = (*L);
    int j = 0;

    while (p && (j < i-1))
    {
        p = p->next;
        j++;
    }
    
    if (!p || (j > i-1))
    {
        return ERROR;
    }
    
    LNode* s = (LNode*)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status DeleteElem(LinkList *L, int i){
    LNode* p = (*L);
    LNode* q = NULL;
    int j = 0;
    
    while (p->next && (j < i-1))
    {
        p = p->next;
        j++;
    }
    
    if (!p->next || j > i-1)
    {
        return ERROR;
    }
    

    q = p->next;
    p->next = q->next;
    free(q);

    return OK;
}

Status CreateListFromHead(LinkList *L, int n){
    Status status = InitList(L);
    if (status == ERROR)
    {
        return ERROR;
    }
    
    for (int i = 0; i < n; i++)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
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

Status CreateListFromRear(LinkList *L, int n){
    Status status = InitList(L);
    if (status == ERROR)
    {
        return ERROR;
    }
    LNode* r = (*L);

    for (int i = 0; i < n; i++)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        if (!p)
        {
            return ERROR;
        }
        
        InputDataFromKeyboard(p);
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return OK;
}

void InputDataFromKeyboard(LNode* node){
    scanf("%d", &node->data);
}

void DestroyList(LinkList *L){
    LNode* p = (*L);
    while (p)
    {
        LNode* temp = p;
        p = p->next;
        free(temp);
    }
    (*L) = NULL;
}