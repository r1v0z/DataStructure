#include<stdio.h>
#include<stdlib.h>

typedef int status;

// 双链表的定义
typedef struct DNode
{
    int data;
    struct DNode *pre, *next;
}DNode, *DList;

// 1. 初始化
DList InitList();

// 2. 销毁链表
status DestroyList(DList* list);

// 3. 头插法插入
status HeadInsertList(DList* list, int e);

// 4. 尾插法插入
status TailInsertList(DList* list, int e);

// 5. 按位插入
status InsertList(DList* list, int pos, int e);

// 6. 头删法删除
status HeadDeleteList(DList* list);

// 7. 尾删法删除
status TailDeleteList(DList* list);

// 8. 按位删除
status DeleteList(DList* list, int pos);

// 9. 打印链表
status PrintList(DList list);

// 10. 按位查找
DNode* GetNode(DList list, int pos);

// 11. 按值查找
DNode* LocateElem(DList list, int e);

// 12. 求表长
int Length(DList list);