#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef int status;
typedef struct LinkNode
{
    int data;
    // int front, rear;
    struct LinkNode* next;
}LinkNode;

typedef struct head
{
    LinkNode *front, *rear;
}LinkQueue;

// 初始化
status InitQueue(LinkQueue* queue);

// 入队（插入数据）
status EnQueue(LinkQueue* queue, int data);


// 出队（删除数据）
status DeQueue(LinkQueue* queue, int* e);

// 判断队空
int QueueEmpty(LinkQueue queue);

// 读队头元素
status GetHead(LinkQueue queue, int* e);

// 销毁队列
status DestroyQueue(LinkQueue* queue);
