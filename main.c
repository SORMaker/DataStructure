#include "SequentialList/SeqList.h"
#include <assert.h>

void SeqList_test();

int main(){
    SeqList_test();

    return 0;
}

void SeqList_test(){

    SqList L;
    ElemType e;
    Status status;

    // 测试初始化
    status = InitList(&L);
    assert(status == OK);
    assert(L.length == 0);
    printf("初始化测试通过\n");

    // 测试插入元素
    status = InsertElem(&L, 1, 100);
    assert(status == OK);
    assert(L.length == 1);
    assert(L.elem[0] == 100);

    status = InsertElem(&L, 2, 200);
    assert(status == OK);
    assert(L.length == 2);
    assert(L.elem[1] == 200);

    status = InsertElem(&L, 2, 150);
    assert(status == OK);
    assert(L.length == 3);
    assert(L.elem[1] == 150);
    printf("插入测试通过\n");

    // 测试插入越界
    status = InsertElem(&L, 0, 50);
    assert(status == ERROR);
    status = InsertElem(&L, 5, 500);
    assert(status == ERROR);
    printf("插入越界测试通过\n");

    // 测试获取元素
    status = GetElem(L, 1, &e);
    assert(status == OK);
    assert(e == 100);

    status = GetElem(L, 3, &e);
    assert(status == OK);
    assert(e == 200);
    printf("获取元素测试通过\n");

    // 测试获取越界
    status = GetElem(L, 0, &e);
    assert(status == ERROR);
    status = GetElem(L, 4, &e);
    assert(status == ERROR);
    printf("获取越界测试通过\n");

    // 测试查找元素
    assert(LocateElem(L, 100) == 1);
    assert(LocateElem(L, 150) == 2);
    assert(LocateElem(L, 200) == 3);
    assert(LocateElem(L, 300) == 0);
    printf("查找元素测试通过\n");

    // 测试删除元素
    status = DeleteElem(&L, 2);
    assert(status == OK);
    assert(L.length == 2);
    assert(L.elem[1] == 200);

    status = DeleteElem(&L, 2);
    assert(status == OK);
    assert(L.length == 1);
    assert(L.elem[0] == 100);
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
    assert(L.length == 0);

    status = GetElem(L, 1, &e);
    assert(status == ERROR);

    assert(LocateElem(L, 100) == 0);
    printf("空表操作测试通过\n");

    // 测试边界条件：满表插入
    for (int i = 1; i <= MAXSIZE; i++) {
        status = InsertElem(&L, i, i);
        assert(status == OK);
    }
    assert(L.length == MAXSIZE);
    status = InsertElem(&L, MAXSIZE+1, MAXSIZE+1);
    assert(status == ERROR);
    printf("满表插入测试通过\n");

    // 释放内存
    free(L.elem);
    printf("所有测试用例通过！\n");
}