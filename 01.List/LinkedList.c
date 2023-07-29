#include "./head/LinkedList.h"

// 1. 初始化链表
LinkList InitList()
{
    LinkList list = NULL;
    return list;
}

// 2. 销毁链表
status DestroyList(LinkList* list)
{
    while((*list) != NULL)
    {
        LinkNode* next = (*list)->next;
        free(*list);
        (*list) = next;
    }

    (*list) = NULL;
    return SUCCESS;
}

// 3. 头插法插入
status HeadInsertList(LinkList* list, int e)
{
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if(node == NULL)
    {
        return FAILURE;
    }
    node->next = (*list);
    node->data = e;
    (*list) = node;
    return SUCCESS;
}

// 4. 尾插法插入
status TailInsertList(LinkList list, int e)
{
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if(node == NULL)
        return FAILURE;

    while(list->next != NULL)
        list = list->next;

    node->data = e;
    node->next = NULL;
    list->next = node;
    
    return SUCCESS;
}


// 5. 头删法删除
status HeadDeleteList(LinkList* list)
{
    LinkNode* node = (*list);
    (*list) = (*list)->next;
    free(node);

    return SUCCESS;
}

// 6. 尾删法删除
status TailDeleteList(LinkList* list)
{
    LinkNode* cur = (*list);
    LinkNode* pre = NULL;
    while(cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }

    if((*list) == cur)
        (*list) = NULL;
    else
        pre->next = NULL;

    free(cur);

    return SUCCESS;
}

// 7. 按位插入 
status InsertList(LinkList* list, int pos, int e)
{
    if(pos == 1)
    {
        return HeadInsertList(list, e);
    }
    
    int count = 1;
    LinkNode* cur = (*list);
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if(node == NULL)
        return FAILURE;
    while(count < pos - 1 && cur != NULL)
    {
        cur = cur->next;
        count++;
    }

    if(cur == NULL)
    {
        return FAILURE;
    }

    node->data = e;
    node->next = cur->next;
    cur->next = node;
    return SUCCESS;
}

// 8. 按位删除
status DeleteList(LinkList* list, int pos)
{
    if(pos == 1)
        return HeadDeleteList(list);
    
    int count = 1;
    LinkNode* cur = (*list);
    LinkNode* pre = NULL;
    while(count < pos && cur != NULL)
    {
        pre = cur;
        cur = cur->next;
        count++;
    }

    if(cur == NULL)
        return FAILURE;
    
    pre->next = cur->next;
    free(cur);

    return SUCCESS;
}

// 9. 打印链表
status PrintList(LinkList list)
{
    while(list != NULL)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
    return SUCCESS;
}

// 10. 按位查找
LinkNode* GetNode(LinkList list, int pos)
{
    int count = 1;
    while(count < pos && list != NULL)
    {
        list = list->next;
        count++;
    }

    return list;
}


// 11. 按值查找
LinkNode* LocateElem(LinkList list, int e)
{
    while (list != NULL)
    {
        if(list->data == e)
            return list;
        list = list->next;
    }

    return list;
}
