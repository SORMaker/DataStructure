#include <stdio.h>
#include <stdlib.h>
#include "DoublyCircularLinkedList.h"

// 辅助函数：打印链表内容，方便调试和验证
void print_list(const char* message, DCLinkList L) {
    printf("%s", message);
    if (!L || L->next == L) {
        printf("[ ] (Empty)\n");
        return;
    }
    printf("[ H <-> ");
    DCLNode* p = L->next;
    while (p != L) {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("H ]\n");
}

int main() {
    DCLinkList list = NULL;
    ElemType e;
    Status s;

    printf("========= 自动化鲁棒性测试开始 =========\n\n");

    // === 1. 测试 InitList 和在空表上的操作 ===
    printf("--- 测试 1: 初始化和空表操作 ---\n");
    s = InitList(&list);
    printf("InitList: %s\n", s == OK ? "PASS" : "FAIL");
    print_list("当前链表: ", list);

    s = GetElem(list, 1, &e);
    printf("GetElem from empty list (i=1): %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");

    s = DeleteElem(&list, 1);
    printf("DeleteElem from empty list (i=1): %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");
    
    DCLNode* node = LocateElem(list, 100);
    printf("LocateElem in empty list: %s (Expected NULL)\n", node == NULL ? "PASS" : "FAIL");
    printf("\n");


    // === 2. 测试 InsertElem ===
    printf("--- 测试 2: 插入操作 ---\n");
    // a. 在空表表头插入 (i=1)
    s = InsertElem(&list, 1, 10);
    printf("InsertElem at i=1 in empty list: %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list);

    // b. 在非空表表头插入 (i=1)
    s = InsertElem(&list, 1, 20);
    printf("InsertElem at i=1 in non-empty list: %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list);

    // c. 在表尾插入 (i=length+1)
    s = InsertElem(&list, 3, 30);
    printf("InsertElem at tail (i=3): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list);

    // d. 在表中间插入 (i=2)
    s = InsertElem(&list, 2, 40);
    printf("InsertElem at middle (i=2): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list); // 预期: 20 <-> 40 <-> 10 <-> 30

    // e. 测试无效位置
    s = InsertElem(&list, 0, 99);
    printf("InsertElem at invalid position (i=0): %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");
    s = InsertElem(&list, 6, 99); // 当前长度为4，i=6 是无效位置
    printf("InsertElem at invalid position (i=6): %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");
    print_list("  -> ", list);
    printf("\n");


    // === 3. 测试 GetElem 和 LocateElem ===
    printf("--- 测试 3: 查找和定位操作 ---\n");
    s = GetElem(list, 3, &e);
    printf("GetElem at i=3: %s, Value: %d (Expected 10)\n", s == OK && e == 10 ? "PASS" : "FAIL", e);
    
    s = GetElem(list, 1, &e);
    printf("GetElem at i=1: %s, Value: %d (Expected 20)\n", s == OK && e == 20 ? "PASS" : "FAIL", e);

    s = GetElem(list, 4, &e);
    printf("GetElem at i=4: %s, Value: %d (Expected 30)\n", s == OK && e == 30 ? "PASS" : "FAIL", e);

    s = GetElem(list, 5, &e);
    printf("GetElem at out-of-bounds position (i=5): %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");

    node = LocateElem(list, 40);
    printf("LocateElem for value 40: %s\n", node != NULL && node->data == 40 ? "PASS" : "FAIL");

    node = LocateElem(list, 999);
    printf("LocateElem for non-existent value 999: %s (Expected NULL)\n", node == NULL ? "PASS" : "FAIL");
    printf("\n");

    
    // === 4. 测试 DeleteElem ===
    printf("--- 测试 4: 删除操作 ---\n");
    // a. 删除中间元素 (i=2, value=40)
    s = DeleteElem(&list, 2);
    printf("DeleteElem at middle (i=2): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list); // 预期: 20 <-> 10 <-> 30

    // b. 删除表头元素 (i=1, value=20)
    s = DeleteElem(&list, 1);
    printf("DeleteElem at head (i=1): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list); // 预期: 10 <-> 30

    // c. 删除表尾元素 (i=2, value=30)
    s = DeleteElem(&list, 2);
    printf("DeleteElem at tail (i=2): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list); // 预期: 10

    // d. 删除最后一个元素
    s = DeleteElem(&list, 1);
    printf("DeleteElem the only element (i=1): %s\n", s == OK ? "PASS" : "FAIL");
    print_list("  -> ", list); // 预期: Empty

    // e. 测试无效位置删除
    s = DeleteElem(&list, 1);
    printf("DeleteElem from empty list again: %s (Expected ERROR)\n", s == ERROR ? "PASS" : "FAIL");
    printf("\n");


    // === 5. 测试 DestroyList ===
    printf("--- 测试 5: 销毁操作 ---\n");
    // 重新填充链表
    InsertElem(&list, 1, 100);
    InsertElem(&list, 2, 200);
    InsertElem(&list, 3, 300);
    print_list("List before destruction: ", list);
    DestroyList(&list);
    printf("DestroyList called.\n");
    printf("List pointer after destruction is NULL: %s\n", list == NULL ? "PASS" : "FAIL");
    print_list("List after destruction: ", list);


    printf("\n========= 自动化鲁棒性测试结束 =========\n");
    return 0;
}