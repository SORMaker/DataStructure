#include <stdio.h>
#include "malloc.h"

#define OK 1
#define ERROR 0

typedef struct lNode
{
    int data;
    struct lNode  *next;
}lNode, *linkList;

int InitList(linkList *l)
{
    (*l) = (linkList)malloc(sizeof(lNode));
    (*l)->data = 0;
    (*l)->next = NULL;
    return OK;
}

int main() {
    linkList la;
    InitList(&la);
    printf("la.data:%d\n",la->data);
    getchar();
    free(la);
    return 0;
}



