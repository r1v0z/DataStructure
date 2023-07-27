#pragma once

#include<stdio.h>
#include<stdlib.h>


// 定义
typedef struct Node
{
    int data;
    struct Node* next;
} LinkNode, *LinkList;

// 1. 初始化链表
LinkList InitList();


// 2. 销毁链表
void DestroyList(LinkList* list);

// 3. 头插法插入
void HeadInsertList(LinkList list, int e);

// 4. 尾插法插入
void TailInsertList(LinkList list, int e);

// 5. 头删法删除
void HeadDeleteList(LinkList list);

// 6. 尾删法删除
void TailDeleteList(LinkList list);

// 7. 按位插入 
void InsertList(LinkList list, int pos, int e);

// 8. 按位删除
void DeleteList(LinkList list, int pos);

// 9. 打印链表
void PrintList(LinkList list);

// 10. 反转链表
void ReverseList(LinkList list);

// 11. 链表排序
void SortList(LinkList list);

// 12. 删除链表中的所有指定值
void DeleteValue(LinkList list, int e);

// 13. 获取链表节点
LinkNode* GetNode(LinkList list, int pos);

// 按值查找
LinkNode* LocateElem(LinkList L, int e);