#include<stdio.h>
#include<stdlib.h>

typedef int status;
typedef struct Node
{
    int data;
    struct Node* next;
}LinkNode, *LinkList;

// 初始化
LinkList InitList();

// 销毁链表
status DestroyList(LinkList* list);

// 头插法
status HeadInsertList(LinkList* list, int e);

// 尾插法
status TailInsertList(LinkList* list, int e);

// 头删法
status HeadDeleteList(LinkList* list);

// 尾删法
status TailDeleteList(LinkList* list);

// 打印链表
status PrintList(LinkList list);

// 按位插入节点
status InsertList(LinkList* list, int pos, int data);

// 按位删除节点
status DeleteList(LinkList* list, int pos);

// 求表长
int Length(LinkList list);

// 按位置查找节点
LinkNode* GetElem(LinkList list, int pos);

// 按值查找节点
LinkNode* LocateElem(LinkList list, int data);