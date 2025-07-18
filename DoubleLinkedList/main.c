#include "DoubleLinkedList.h"
#include <assert.h>

void test(){
    DuLinkList L;
    ElemType e;
    Status status;
    DuLNode* p;

    // 测试初始化
    status = InitList(&L);
    assert(status == OK);
    assert(L != NULL);
    assert(L->next == NULL);  // 非循环链表头节点next应为NULL
    assert(L->prior == NULL); // 非循环链表头节点prior应为NULL
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
    assert(p != NULL && p->data == 100);  // 非循环链表返回NULL表示未找到

    p = LocateElem(L, 150);
    assert(p != NULL && p->data == 150);

    p = LocateElem(L, 200);
    assert(p != NULL && p->data == 200);

    p = LocateElem(L, 300);
    assert(p == NULL);  // 未找到时应返回NULL
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
    assert(L->next == NULL);  // 空表时头节点next应为NULL

    status = GetElem(L, 1, &e);
    assert(status == ERROR);

    p = LocateElem(L, 100);
    assert(p == NULL);
    printf("空表操作测试通过\n");

    // 测试头插法创建链表
    status = CreateListFromHead(&L, 5);  // 假设已有此函数
    assert(status == OK);
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 5);  // 头插法逆序
    status = GetElem(L, 5, &e);
    assert(status == OK && e == 1);
    printf("头插法创建链表测试通过\n");

    // 测试尾插法创建链表
    status = CreateListFromRear(&L, 5);  // 假设已有此函数
    assert(status == OK);
    status = GetElem(L, 5, &e);
    assert(status == OK && e == 5);  // 尾插法顺序
    status = GetElem(L, 1, &e);
    assert(status == OK && e == 1);
    printf("尾插法创建链表测试通过\n");

    // 测试销毁链表
    DestroyList(&L);
    printf("销毁链表测试通过！\n");
    printf("所有测试用例通过！\n");
}

int main(){
    test();
    
    return 0;
}

