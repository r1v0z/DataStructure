#include<stdio.h>
#include<stdlib.h>

typedef int status;

// 定义循环双链表的节点
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化
DLinkList InitList();

// 销毁链表
status DestroyList(DLinkList* list);

// 头插法
status HeadInsertList(DLinkList* list, int data);

// 尾插法
status TailInsertList(DLinkList* list, int data);

// 头删法
status HeadDeleteList(DLinkList* list);

// 尾删法
status TailDeleteList(DLinkList* list);

// 打印链表
status PrintList(DLinkList list);

// 按位插入
status InsertList(DLinkList* list, int pos, int data);

// 按位删除
status DeleteList(DLinkList* list, int pos);

// 按值查找
DNode* GetElem(DLinkList list, int data);