#include <stdio.h>
#include "malloc.h"


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
    return 1;
}

linkList la;


int main() {
    InitList(&la);
    printf("la.data:%d\n",la->data);
    getchar();
    free(la);
    return 0;
}



