//
// Created by sorrymaker on 2023/4/22.
//

#include "stack.h"
#include "malloc.h"

#define OK 1
#define ERROR 0
#define TRUE    1
#define FALSE   0
#define OVERFLOW 0

/*!
 * @brief   initStack
 *
 * @param   initStack        Stack struct
 *
 * @return  OK:1            Init success
 *
 * @note
 */
int initStack(SqStack *S)
{
    (*S).base = (int *)malloc(MAXSIZE * sizeof(int));
    if((*S).base == NULL)
    {
        return ERROR;
    }
    (*S).top = (*S).base;
    (*S).stackSize = MAXSIZE;
    return OK;
}
/*!
 * @brief   push
 *
 * @param   SqStack        Stack struct
 * @param   Elem           push element
 *
 * @return  OK:1           push success
 *
 * @note        if ram not enough , malloc other ram
 */
int push(SqStack *S, int Elem)
{
    if((*S).top - (*S).base == (*S).stackSize)
    {
        (*S).top = (int*)malloc(MAXSIZE * sizeof(int));
        (*S).stackSize += MAXSIZE;
    }
    (*(*S).top) = Elem;
    (*S).top++;
    return OK;
}
/*!
 * @brief   pop
 *
 * @param   SqStack        Stack struct
 * @param   Elem           pop element
 *
 * @return  OK:1           push success
 * @return  ERROR:0        Stack is empty
 * @note
 */
int pop(SqStack *S, int *Elem)
{
    if((*S).base == (*S).top)
    {
        return ERROR;
    }
    (*S).top--;
    *Elem = (*(*S).top);
    return OK;
}
/*!
 * @brief   getElem
 *
 * @param   SqStack        Stack struct
 * @param   Elem           top element
 *
 * @return  OK:1           get top element
 * @return  ERROR:0        Stack is empty
 * @note
 */
int getElem(SqStack S, int *Elem)
{
    if(S.top == S.base)
    {
        return ERROR;
    }
    
    S.top--;
    *Elem = *(S.top);
    return OK;
}
/*!
 * @brief   destroyStack
 *
 * @param   SqStack        Stack struct
 *
 * @return  OK:1           destroy stack
 * @note
 */
int destroyStack(SqStack *S)
{
    free(S->base);
    S->base = S->top = NULL;
    S->stackSize = 0;
    return OK;
}
/*!
 * @brief   clearStack
 *
 * @param   SqStack        Stack struct
 *
 * @return  OK:1           clear stack
 * @note
 */
int clearStack(SqStack *S)
{
    S->top = S->base;
    return OK;
}
/*!
 * @brief   stackIsEmpty
 *
 * @param   SqStack        Stack struct
 *
 * @return  TRUE:1         stack is empty
 * @return  FALSE:1        stack is not empty
 * @note
 */
int  stackIsEmpty(SqStack S)
{
    if(S.top == S.base)
    {
        return TRUE;
    }
    return FALSE;
}
/*!
 * @brief   stackLength
 *
 * @param   SqStack        Stack struct
 *
 * @return  stack's length
 * @note
 */
int stackLength(SqStack S)
{
    return S.top - S.base;
}
