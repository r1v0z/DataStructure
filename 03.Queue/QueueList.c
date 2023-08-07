#include "./QueueList.h"


// 初始化
status InitQueue(LinkQueue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;

    return EXIT_SUCCESS;
}


// 入队（插入数据）
status EnQueue(LinkQueue* queue, int data)
{
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
    if(node == NULL)
        return EXIT_FAILURE;
    node->next = NULL;
    node->data = data;

    if (queue->rear != NULL)
    {
        queue->rear->next = node;
    }
    else
    {
        queue->front = node;
    }
    
    queue->rear = node;
    return EXIT_SUCCESS;
}


// 出队（删除数据）
status DeQueue(LinkQueue* queue, int* e)
{
    if (queue->front == NULL)
    {
        return EXIT_FAILURE;
    }
    
    LinkNode* node = queue->front;
    queue->front = node->next;
    *e = node->data;
    free(node);
    
    return EXIT_SUCCESS;
}

// 判断队空
int QueueEmpty(LinkQueue queue)
{
    if (queue.front == NULL)
    {
        return 1;
    }
    else
        return 0;
    
}

// 读队头元素
status GetHead(LinkQueue queue, int* e)
{
    if (queue.front == NULL)
    {
        return EXIT_FAILURE;
    }
    
    LinkNode* node = queue.front;
    *e = node->data;

    return EXIT_SUCCESS;
}

// 销毁队列
status DestroyQueue(LinkQueue* queue)
{
    while (queue->front != NULL)
    {
        LinkNode* node = queue->front;
        queue->front = node->next;
        free(node);
    }
    queue->rear = NULL;
    
    return EXIT_SUCCESS;
}