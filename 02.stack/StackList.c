#include "./head/StackList.h"

// 初始化
StackList Init()
{
    StackList s = NULL;
    return s;
}

// 入栈
status push(StackList* s, int data)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (node == NULL)
        return EXIT_FAILURE;
    
    node->data = data;
    node->next = *s;
    *s = node;

    return EXIT_SUCCESS;
}

// 出栈
status pop(StackList* s, int* e)
{
    if (*s == NULL)
        return EXIT_FAILURE;
    
    *e = (*s)->data;
    StackNode* node = *s;
    *s = (*s)->next;
    free(node);

    return EXIT_SUCCESS;
}

// 判断栈空
int isEmpty(StackList* s)
{
    if(*s == NULL)
        return 1;
    else
        return 0;
}

// 获取栈顶元素
status GetTop(StackList* s, int* e)
{
    if (*s == NULL)
        return EXIT_FAILURE;
    
    *e = (*s)->data;

    return EXIT_SUCCESS;
}