#include "DoubleLinkedList.h"

Status InitList(DuLinkList *L){
    (*L) = (DuLNode*)malloc(sizeof(DuLNode));

    (*L)->next = NULL;
    (*L)->prior = NULL;

    return OK;
}

Status GetElem(DuLinkList L, int i, ElemType *e){
    if(i <= 0) return ERROR;

    DuLNode* p = L->next;
    int j = 1;

    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    
    if (p == NULL) return ERROR;
    
    (*e) = p->data;

    return OK;
}

DuLNode* LocateElem(DuLinkList L, ElemType e){
    DuLNode* p = L;

    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    
    return p;
}

Status InsertElem(DuLinkList *L, int i, ElemType e){
    if(i < 1) return ERROR;

    DuLNode* p = (*L);
    int j = 0;

    while (p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    
    if(p == NULL) return ERROR;

    DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
    if(!s) return ERROR;

    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL)
    {
        p->next->prior = s;
    }
    p->next = s;

    return OK;
}

Status DeleteElem(DuLinkList *L, int i){
    if(i < 1) return ERROR;

    DuLNode* p = (*L);
    int j = 0;

    while (p->next != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    
    if(p->next == NULL || j != i-1) return ERROR;

    DuLNode* q = p->next;
    p->next = q->next;
    if (q->next != NULL)
    {
        q->next->prior = p;
    }
    
    free(q);
    return OK;
}

void DestroyList(DuLinkList *L){
    DuLNode* p = (*L);
    DuLNode* temp = NULL;

    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

Status CreateListFromHead(DuLinkList *L, int n){
    Status status = InitList(L);
    ElemType e;
    if (status == ERROR)
    {
        return ERROR;
    }
    
    for (int i = 0; i < n; i++)
    {
        DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
        if (!p)
        {
            DestroyList(L);
            return ERROR;
        }
        
        e = InputDataFromKeyboard();
        p->data = e;
        p->next = (*L)->next;
        p->prior = (*L);
        if ((*L)->next != NULL)
        {
            (*L)->next->prior = p;
        }
        (*L)->next = p;
    }
    return OK;
}

Status CreateListFromRear(DuLinkList *L, int n){
    Status status = InitList(L);
    ElemType e;
    if (status == ERROR)
    {
        return ERROR;
    }
    DuLNode* r = (*L);

    for (int i = 0; i < n; i++)
    {
        DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
        if (!p)
        {
            DestroyList(L);
            return ERROR;
        }
        
        e = InputDataFromKeyboard();
        p->data = e;
        p->next = NULL;
        r->next = p;
        p->prior = r;
        r = p;
    }
    return OK;
}

ElemType InputDataFromKeyboard(){
    char line[100];
    ElemType e;
    if(fgets(line, sizeof(line), stdin) == NULL){
        printf("READ INPUT ERROR!");
        return ERROR;
    }
    if(sscanf(line, "%d", &e) != 1)
    {
        printf("INPUT FORMAT ERROR! PLEASE INPUT AGAIN!\n");
        return ERROR;
    }
    return e;
}
