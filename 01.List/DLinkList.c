#include "./head/DLinkList.h"


// 1. 初始化
DList InitList()
{
    DList list = NULL;
    return list;
}

// 2. 销毁链表
status DestroyList(DList* list)
{
    DNode* node = NULL;
    while((*list) != NULL)
    {
        node = (*list)->next;
        free(*list);
        (*list) = node;
    }

    return EXIT_SUCCESS;
}

// 3. 头插法插入
status HeadInsertList(DList* list, int e)
{
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == NULL)
        return EXIT_FAILURE;
    
    if((*list) != NULL)
        (*list)->pre = node;

    node->data = e;
    node->next = (*list);
    node->pre = NULL;
    (*list) = node;

    return EXIT_SUCCESS;
}

// 4. 尾插法插入
status TailInsertList(DList* list, int e)
{
    DNode* cur = (*list);
    while((*list) != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }

    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == NULL)
        return EXIT_FAILURE;

    node->next = NULL;
    node->data = e;
    node->pre = cur;

    if((*list) == NULL)
        (*list) = node;
    else
        cur->next = node;

    return EXIT_SUCCESS;
}

// 5. 按位插入
status InsertList(DList* list, int pos, int e)
{
    if(pos == 1)
        return HeadInsertList(list, e);

    int count = 1;
    DNode* cur = (*list);
    while (cur->next != NULL && count < pos - 1)
    {
        cur = cur->next;
        count++;
    }

    if(count < pos - 1)
        return EXIT_FAILURE;
    
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == NULL)
        return EXIT_FAILURE;

    node->data = e;
    node->pre = cur;
    node->next = cur->next;

    if(cur->next != NULL)       // 当 cur->next 不为NULL时，才需要修改后面节点的 pre 指针
        cur->next->pre = node;
    
    cur->next = node;
    
    return EXIT_SUCCESS;
}

// 6. 头删法删除
status HeadDeleteList(DList* list)
{
    if((*list) == NULL)
        return EXIT_FAILURE;

    (*list) = (*list)->next;
    free((*list)->pre);
    (*list)->pre = NULL;

    return EXIT_SUCCESS;
}

// 7. 尾删法删除
status TailDeleteList(DList* list)
{
    if((*list) == NULL)
        return EXIT_FAILURE;
    DNode* cur = (*list);
    while (cur->next != NULL)
        cur = cur->next;

    if(cur->pre != NULL)
        cur->pre->next = NULL;

    free(cur);
    return EXIT_SUCCESS;
}


// 8. 按位删除
status DeleteList(DList* list, int pos)
{
    if((*list) == NULL)
        return EXIT_FAILURE;

    if(pos == 1)
        return HeadDeleteList(list);

    int count = 1;
    DNode* cur = (*list);
    while (cur != NULL && count < pos)
    {
        cur = cur->next;
        count++;
    }

    
    if(cur == NULL)
        return EXIT_FAILURE;

    cur->pre->next = cur->next;
    if(cur->next != NULL)
        cur->next->pre = cur->pre;
    
    free(cur);
    return EXIT_SUCCESS;
}


// 9. 打印链表
status PrintList(DList list)
{
    while(list != NULL)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// 10. 按位查找
DNode* GetNode(DList list, int pos)
{
    int count = 1;
    DNode* node = list;
    while (node != NULL && count < pos)
    {
        node = node->next;
        count++;
    }
    return node;
}

// 11. 按值查找
DNode* LocateElem(DList list, int e)
{
    DNode* node = list;
    while (node != NULL)
    {
        if(node->data == e)
            return node;
        
        node = node->next;
    }
    
    return node;
}

// 12. 求表长
int Length(DList list)
{
    if(list == NULL)
        return 0;

    int len = 1;
    DNode* node = list;
    while (node->next != NULL)
    {
        node = node->next;
        len++;
    }

    return len;
}