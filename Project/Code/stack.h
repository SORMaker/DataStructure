//
// Created by sorrymaker on 2023/4/22.
//

#ifndef CODE_STACK_H
#define CODE_STACK_H

#define MAXSIZE 3

typedef struct SqStack
{
    int *top;
    int *base;
    int stackSize;
}SqStack;



int initStack(SqStack *S);
int push(SqStack *S, int Elem);
int pop(SqStack *S, int *Elem);
int getElem(SqStack S, int *Elem);
int destroyStack(SqStack *S);
int clearStack(SqStack *S);
int  stackIsEmpty(SqStack S);
int stackLength(SqStack S);

#endif //CODE_STACK_H
