#include "./head/LinkedList.h"


// 初始化链表
LinkList InitList()
{
    LinkList list = (LinkList)malloc(sizeof(LinkNode));
    if(list == NULL)
        return NULL;
    list->data = 0;         // 头节点的data用于存放该链表的长度
    list->next = NULL;
    return list;
} 

// 销毁链表
void DestroyList(LinkList* list)
{
    LinkList cur = (*list)->next;
    LinkList next = NULL;
    while(cur != NULL)     // 当list 为 NUL 时表示全部节点已经释放
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *list = NULL;
}

// 头插法插入   
void HeadInsertList(LinkList list, int e)
{
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));

    node->data = e;
    node->next = list->next;
    list->next = node;
    list->data++;
}

// 尾插法插入
void TailInsertList(LinkList list, int e)
{
    LinkList head = list;
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = e;
    node->next = NULL;

    while (list->next != NULL)
    {
        list = list->next;
    }

    list->next = node;
    head->data++;
}


// 头删法
void HeadDeleteList(LinkList list)
{
    LinkNode* node = list->next;
    list->next = node->next;
    free(node);
    list->data--;
}

// 尾删法
void TailDeleteList(LinkList list)
{
    LinkNode* cur = list->next;
    LinkNode* pre = list;
    while (cur->next)
    {
        pre = cur;
        cur = cur->next;
    }
    free(cur);
    pre->next = NULL;
    list->data --;
}

// 按位插入
void InsertList(LinkList list, int pos, int e)
{
    int curpos = 0;
    LinkNode* cur = list;
    while (curpos < pos - 1)
    {
        curpos++;
        cur = cur->next;
    }
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = e;
    node->next = cur->next;
    cur->next = node;
    list->data++;
}

// 按位删除
void DeleteList(LinkList list, int pos)
{
    LinkNode* cur = list;
    LinkNode* pre = NULL;
    int count = 0;
    while(count < pos)
    {
        count++;
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    free(cur);
    list->data--;
}

// 打印链表
void PrintList(LinkList list)
{
    list = list->next;
    while (list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// 反转链表
void ReverseList(LinkList list)
{
    LinkNode* last = list->next;
    LinkNode* first = NULL;

    while (last->next != NULL)
    {
        first = last->next;
        last->next = first->next;
        first->next = list->next;
        list->next = first;
    }
}

// 链表排序(升序，从小到大)
void SortList(LinkList list)
{
    LinkNode* cur = list->next;     // 当前要确定的位置
    LinkNode* node = NULL;

    while(cur->next != NULL)
    {
        node = cur->next;
        while (node != NULL)
        {
            if(node->data < cur->data)
            {
                int temp = node->data;
                node->data = cur->data;
                cur->data = temp;
            }

            node = node->next;
        }
        cur = cur->next;
    }
}

// 删除链表中的所有指定值
void DeleteValue(LinkList list, int e)
{
    LinkNode* cur = list->next;
    LinkNode* pre = NULL;

    while(cur != NULL)
    {
        if(cur->data == e)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
            list->data--;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

// 获取链表节点
LinkNode* GetNode(LinkList list, int pos)
{
    int count = 1;
    LinkNode* node = list->next;
    while(count < pos && node != NULL)
    {
        node = node->next;
        count++;
    }

    if(count == pos)
        return node;
    else
        return NULL;
}

// 按值查找
LinkNode* LocateElem(LinkList list, int e)
{
    LinkNode* node = list->next;

    while(node != NULL)
    {
        if(node->data == e)
            return node;
        else
            node = node->next;
    }

    return NULL;
}