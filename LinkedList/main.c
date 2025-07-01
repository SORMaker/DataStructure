#include "LinkedList.h"
#include <assert.h>

void LinkedList_test();

int main(){
    LinkedList_test();
    
    return 0;
}

void LinkedList_test(){
    LinkList L;
    ElemType e;
    Status status;
    LNode* p;

    // 测试初始化
    status = InitList(&L);
    assert(status == OK);
    assert(L != NULL);
    assert(L->next == NULL);
    printf("初始化测试通过\n");

    // 测试插入元素
    status = InsertElem(&L, 1, 100);
    assert(status == OK);
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 100);

    status = InsertElem(&L, 2, 200);
    assert(status == OK);
    status = GetElem(L, 2, &e);
    assert(status == OK && e == 200);

    status = InsertElem(&L, 2, 150);
    assert(status == OK);
    status = GetElem(L, 2, &e);
    assert(status == OK && e == 150);
    printf("插入测试通过\n");

    // 测试插入越界
    status = InsertElem(&L, 0, 50);
    assert(status == ERROR);
    status = InsertElem(&L, 5, 500);
    assert(status == ERROR);
    printf("插入越界测试通过\n");

    // 测试获取元素
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 100);

    status = GetElem(L, 3, &e);
    assert(status == OK && e == 200);
    printf("获取元素测试通过\n");

    // 测试获取越界
    status = GetElem(L, 0, &e);
    assert(status == ERROR);
    status = GetElem(L, 4, &e);
    assert(status == ERROR);
    printf("获取越界测试通过\n");

    // 测试查找元素
    p = LocateElem(L, 100);
    assert(p != NULL && p->data == 100);
    
    p = LocateElem(L, 150);
    assert(p != NULL && p->data == 150);
    
    p = LocateElem(L, 200);
    assert(p != NULL && p->data == 200);
    
    p = LocateElem(L, 300);
    assert(p == NULL);
    printf("查找元素测试通过\n");

    // 测试删除元素
    status = DeleteElem(&L, 2);
    assert(status == OK);
    status = GetElem(L, 2, &e);
    assert(status == OK && e == 200);

    status = DeleteElem(&L, 2);
    assert(status == OK);
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 100);
    status = GetElem(L, 2, &e);
    assert(status == ERROR);
    printf("删除元素测试通过\n");

    // 测试删除越界
    status = DeleteElem(&L, 0);
    assert(status == ERROR);
    status = DeleteElem(&L, 2);
    assert(status == ERROR);
    printf("删除越界测试通过\n");

    // 测试边界条件：空表操作
    status = DeleteElem(&L, 1);
    assert(status == OK);
    assert(L->next == NULL);

    status = GetElem(L, 1, &e);
    assert(status == ERROR);

    p = LocateElem(L, 100);
    assert(p == NULL);
    printf("空表操作测试通过\n");

    // 测试头插法创建链表
    status = CreateListFromHead(&L, 5);
    assert(status == OK);
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 5);  // 头插法逆序
    status = GetElem(L, 5, &e);
    assert(status == OK && e == 1);
    printf("头插法创建链表测试通过\n");

    // 测试尾插法创建链表
    status = CreateListFromRear(&L, 5);
    assert(status == OK);
    status = GetElem(L, 5, &e);
    assert(status == OK && e == 5);  // 尾插法顺序
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 1);
    printf("尾插法创建链表测试通过\n");

    // 测试删除链表
    DestroyList(&L);
    printf("删除链表测试通过！\n");
    printf("所有测试用例通过！\n");
}
