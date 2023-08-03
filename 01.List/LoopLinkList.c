#include "./head/LoopLinkList.h"

// 初始化
LinkList InitList()
{
    LinkList list = NULL;
    return list;
}

// 销毁链表
status DestroyList(LinkList* list)
{
    if((*list) == NULL)
        return EXIT_FAILURE;
    
    LinkNode* curNode = *list;     // curNode指向要释放的节点
    LinkNode* nextNode = curNode->next;     // nextNode 指向要释放节点的下一节点

    while (curNode->next != *list)  // 当 curNode->next 指向头指针，curNode指向的是最后一个节点
    {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    *list = NULL;

    return EXIT_SUCCESS;
}

// 头插法
status HeadInsertList(LinkList* list, int data)
{
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    // 当 node 没有成功分配内存时，直接返回
    if(node == NULL)
        return EXIT_FAILURE;
    

    if((*list) != NULL)
    {
        node->data = (*list)->data;     // 将新节点的数据域，存放第一个节点的数据
        node->next = (*list)->next;     // 当链表中存在节点，则将 node->next 设置为第一个节点
        (*list)->next = node;
        (*list)->data = data;
    }
    else
    {
        node->data = data;
        node->next = node;     // 链表中没有节点，将 node->next 指向自己
        (*list) = node;        // 修改头指针指向 node
    }

    return EXIT_SUCCESS;
}

// 尾插法
status TailInsertList(LinkList* list, int e)
{
    LinkNode* cur = (*list);
    // 判断 cur != NULL,是为了避免链表中没有节点而发生错误，当节点的 next 指向第一个节点，表示该节点为最后一个节点
    while (cur != NULL && cur->next != (*list))       
        cur = cur->next;

    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if (node == NULL)
        return EXIT_FAILURE;

    node->data = e;
    if (cur == NULL)    // 链表中没有节点
    {
        node->next = node;
        (*list) = node;
    }
    else                // 链表中有节点
    {
        node->next = (*list);
        cur->next = node;
    }
    
    return EXIT_SUCCESS;
}

// 头删法
status HeadDeleteList(LinkList* list)
{
    // 判断 next 是否指向本身，如果是表示只有一个节点
    if((*list)->next == *list)
    {
        // 只有一个节点时，释放后需要将指针指向 NULL
        free(*list);
        *list = NULL;
    }
    else
    {
        LinkNode* curNode = (*list)->next;
        (*list)->next = curNode->next;
        (*list)->data = curNode->data;
        free(curNode);
    }

    return EXIT_SUCCESS;
}

// 尾删法
status TailDeleteList(LinkList* list)
{
    LinkNode* cur = *list;
    LinkNode* pre = NULL;

    // 遍历链表，cur 表示当前的节点， pre 表示前一个节点
    while(cur->next != *list)
    {
        pre = cur;
        cur = cur->next;
    }
    free(cur);

    // 当 pre == NULL，则说明链表只有一个节点
    if(pre == NULL)
        *list = NULL;       // 只有一个节点，删除后没有节点，所以 *list 指向 NULL
    else
        pre->next = *list;  // 有多个节点, 将删除后的最后一个节点，指向开头

    return EXIT_SUCCESS;
}

// 打印链表
status PrintList(LinkList  list)
{
    // list == NULL 链表中没有节点；
    LinkNode* cur = list;

    do
    {
        printf("%d -> ", cur->data);    // 打印当前节点的数据
        cur = cur->next;    // cur 指向下一个节点
    }while (cur != list);   // cur == list 时表示已经遍历了整个链表，如果使用 cur->next != list 进行判断最后一个节点会无法打印     

    printf("NULL\n");
    
    return EXIT_SUCCESS;
}

// 按位插入节点
status InsertList(LinkList* list, int pos, int data)
{
    // 判断值是否合法，大于等于 1 不代表pos有效，但小于1一定不能插入
    if(pos < 1)
        return EXIT_FAILURE;

    // 当要在第一位插入时，可以使用头差法插入
    if (pos == 1)
        return HeadInsertList(list, data);

    LinkNode* curNode = *list;
    int count = 1;      // 表示当前的位置

    while (curNode->next != *list && count < pos - 1)
    {
        // 
        curNode = curNode->next;
        count++;
    }

    // 当 count < pos - 1时，代表已经到最后一个节点了，但是还是没有到达pos - 1的位置
    if(count < pos - 1)
        return EXIT_FAILURE;

    
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if(node == NULL)
        return EXIT_FAILURE;
    

    node->data = data;
    node->next = curNode->next;
    curNode->next = node;

    return EXIT_SUCCESS;
}

// 按位删除节点
status DeleteList(LinkList* list, int pos)
{
    // 判断 pos 是否小于1，插入位置不能小于 1
    if (pos < 1)
        return EXIT_FAILURE;
    // 当 pos 等于 1 时，使用头插法
    if (pos == 1)
        return HeadDeleteList(list);
    
    int curPos = 1;                 // 当前节点的位置
    LinkNode* curNode = *list;     // 用于查找要删除的节点
    LinkNode* preNode = NULL;      // 指向 curNode 的前一个节点，一开始没有前一节点，所以初始化为NULL
    while (curNode->next != *list && curPos < pos)
    {
        // 移动 curNode，直到 curNode 指向第 pos 位节点
        preNode = curNode;
        curNode = curNode->next;
        curPos++;
    }

    // 当 curPos 小于 pos-1 时，curNode 已经指向最后一个节点，故要插入的位置超出当前链表长度
    if(curPos < pos - 1)
        return EXIT_FAILURE;

    preNode->next = curNode->next;
    free(curNode);
}

// 求表长
int Length(LinkList list)
{
    int len = 1;
    LinkNode* curNode = list;

    while (curNode->next != list)
    {
        len++;
        curNode = curNode->next;
    }

    return len;
}

// 按位置查找节点
LinkNode* GetElem(LinkList list, int pos)
{
    LinkNode* curNode = list;
    int curPos = 1;
    while (curNode->next == list && curPos < pos)
    {
        curNode = curNode->next;
        curPos++;
    }
    
    if (curPos == pos)
        return curNode;
    else
        return NULL;
}


// 按值查找节点
LinkNode* LocateElem(LinkList list, int data)
{
    LinkNode* curNode = list;

    while (curNode->next == list)
    {
        if(curNode->data == data)
            return curNode;
        curNode = curNode->next;
    }
    
    return NULL;
}