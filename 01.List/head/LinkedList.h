#pragma once

#include<stdio.h>
#include<stdlib.h>

#define FAILURE 0
#define SUCCESS 1
typedef int status;

// 定义
typedef struct Node
{
    int data;
    struct Node* next;
} LinkNode, *LinkList;

// 1. 初始化链表
LinkList InitList();

// 2. 销毁链表
status DestroyList(LinkList* list);

// 3. 头插法插入
status HeadInsertList(LinkList* list, int e);

// 4. 尾插法插入
status TailInsertList(LinkList list, int e);

// 5. 头删法删除
status HeadDeleteList(LinkList* list);

// 6. 尾删法删除
status TailDeleteList(LinkList* list);

// 7. 按位插入 
status InsertList(LinkList* list, int pos, int e);

// 8. 按位删除
status DeleteList(LinkList* list, int pos);

// 9. 打印链表
status PrintList(LinkList list);

// 10. 按位查找
LinkNode* GetNode(LinkList list, int pos);

// 11. 按值查找
LinkNode* LocateElem(LinkList list, int e);

// 12. 求表长
int Length(LinkList list);