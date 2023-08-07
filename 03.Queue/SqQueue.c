#include "./SqQueue.h"

// 初始化
status InitQueue(SqQueue* queue)
{
    queue->front = 0;
    queue->rear = 0;
    return EXIT_SUCCESS;
}

// 入队（插入数据）
status EnQueue(SqQueue* queue, int data)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front)
    {
        return EXIT_FAILURE;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    
    return EXIT_SUCCESS;
}


// 出队（删除数据）
status DeQueue(SqQueue* queue, int* e)
{
    if(queue->front == queue->rear)
        return EXIT_FAILURE;
    
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;

    return EXIT_SUCCESS;
}

// 判断队空
int QueueEmpty(SqQueue queue)
{
    if(queue.front == queue.rear)
        return 1;
    else
        return 0;
}

// 读队头元素
status GetHead(SqQueue queue, int* e)
{
    if(queue.front == queue.rear)
        return EXIT_FAILURE;
    
    *e = queue.data[queue.front];
    return EXIT_SUCCESS;
}
