#include "./head/LoopDlinkList.h"

// 初始化
DLinkList InitList()
{
    // 一开始并不存在节点，所以执向 NULL
    DLinkList list = NULL;
    return list;
}

// 销毁链表
status DestroyList(DLinkList* list)
{
    // 当链表不存在节点时返回失败
    if (*list == NULL)
        return EXIT_FAILURE;
    

    DNode* curNode = (*list);   // 指向要删除的节点
    DNode* nextNode = NULL;     // 指向要删除节点的下一个节点

    do
    {
        // nextNode 指向下一节点，释放 curNode 指向的节点，最后移动curNode指向下一节点
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    } while (curNode != *list);
    
    *list = NULL;               // 销毁链表后将链表指向 NULL，防止再次使用
    
    return EXIT_SUCCESS;
}

// 头插法
status HeadInsertList(DLinkList* list, int data)
{
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == NULL)   
        return EXIT_FAILURE;
    
    node->data = data;

    if(*list == NULL)
    {
        // 当链表中没有节点时，将 prior 和 next 指向自己
        node->next = node;
        node->prior = node;
    }
    else
    {
        // 当链表中存在节点时
        node->next = (*list);           // 将节点的 next 指向当前链表的第一个节点
        node->prior = (*list)->prior;   // 节点的 prior 执向链表的最后一个节点，也就是 (*list)->prior 指向的位置
        (*list)->prior->next = node;    // 修改最后一个节点的 next 指向新建节点
        (*list)->prior = node;          // 将链表第一个节点的 prior 执向新建节点
    }
    
    *list = node;                   // 链表指向新的头节点

    return EXIT_SUCCESS;
}

// 尾插法
status TailInsertList(DLinkList* list, int data)
{
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == NULL)   
        return EXIT_FAILURE;
    
    node->data = data;
    
    if(*list == NULL)
    {
        // 当链表中没有节点时，将 prior 和 next 指向自己
        node->next = node;
        node->prior = node;
    }
    else
    {
        // 当链表中存在节点时
        node->next = (*list);           // 将节点的 next 指向当前链表的第一个节点
        node->prior = (*list)->prior;   // 节点的 prior 执向链表的最后一个节点，也就是 (*list)->prior 指向的位置
        (*list)->prior->next = node;    // 修改最后一个节点的 next 指向新建节点
        (*list)->prior = node;          // 将链表第一个节点的 prior 执向新建节点
    }
}

// 头删法
status HeadDeleteList(DLinkList* list)
{
    // 判断链表是否只有一个节点
    if ((*list)->next == *list)
    {
        free(*list);
        *list = NULL;
    }
    else
    {
        DLinkList head = *list;         // head 指向链表的第一个节点
        *list = (*list)->next;          // list 指向下一位，也就是删后的第一个节点
        (*list)->prior = head->prior;   // 修改 list 的 prior 执向最后一个节点
        head->prior->next = *list;      // 修改最后一个节点的 next 指向 list
        free(head);
    }

    return EXIT_SUCCESS;
}

// 尾删法
status TailDeleteList(DLinkList* list)
{
    // 判断链表是否只有一个节点
    if ((*list)->next == *list)
    {
        free(*list);
        *list = NULL;
    }
    else
    {
        DLinkList last = (*list)->prior;    // last 指向链表的最后一个节点
        last->prior->next = *list;          // 最后一个节点的前一节点指向第一个节点
        (*list)->prior = last->prior;       // 修改 list 的 prior 执向最后一个节点的前一节点
        free(last);
    }

    return EXIT_SUCCESS;
}


// 打印链表
status PrintList(DLinkList list)
{
    // 判断链表是否存在节点
    if(list != NULL)
    {
        DNode* node = list;
        do
        {
            printf("%d -> ", node->data);
            node = node->next;      // node 指向下一节点
        } while (node != list);
    }

    printf("NULL\n");

    return EXIT_SUCCESS;
}

// 按位插入
status InsertList(DLinkList* list, int pos, int data)
{
    if(pos < 1)
        return EXIT_FAILURE;

    if(pos == 1)
        return HeadInsertList(list, data);

    int curLocation = 1;        // 当前的位置
    DNode* curNode = *list;     // 当前位置的节点


    // 因为要执行循环时不可能在第一位插入，所以可以使用 do ... while
    do
    {
        curNode = curNode->next;    // 移动到下一节点
        curLocation++;              // 位置加 1
    } while (curNode != *list && curLocation < pos);
    
    // 当curLocation 等于 pos 时，表示可以在链表中插入，不相等则表示要插入的位置大于链表的长度 + 1
    if (curLocation != pos)
    {
        return EXIT_FAILURE;
    }
    else
    {
        DNode* node = (DNode*)malloc(sizeof(DNode));
        if(node == NULL)
            return EXIT_FAILURE;

        node->data = data;

        // 修改 node 的前向指针与后向指针
        node->next = curNode;
        node->prior = curNode->prior;

        curNode->prior->next = node;    // 修改 curNode 的前一节点的 next 指向 node
        curNode->prior = node;          // 修改 curNode 指向的节点的 prior 指向 node
    }
    
    return EXIT_SUCCESS;
}

// 按位删除
status DeleteList(DLinkList* list, int pos)
{
    if(pos < 1)
        return EXIT_FAILURE;

    if(pos == 1)
        return HeadDeleteList(list);

    int curLocation = 1;
    DNode* curNode = *list;

    // 移动 curNode 指向要删除的节点
    while (curNode->next != *list && curLocation < pos)
    {
        curLocation++;
        curNode = curNode->next;
    }
    
    if(curLocation != pos)      // 当遍历了整个链表，还是无法到达 pos，则表示无法删除该节点
    {
        return EXIT_FAILURE;
    }
    else
    {
        curNode->next->prior = curNode->prior;  // 修改 curNode 的后一节点的 prior
        curNode->prior->next = curNode->next;   // 修改 curNode 的前一节点的 next
        free(curNode);
    }
    
    return EXIT_SUCCESS;
}

// 按值查找
DNode* GetElem(DLinkList list, int data)
{
    DNode* curNode = list;
    do
    {
        if (curNode->data == data)  // 判断当前节点的数据是否与查找的数据相同
            return curNode;

        curNode = curNode->next;    // 移动到下一节点
    } while (curNode != list);
    

    return NULL;
}