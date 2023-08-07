#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef int status;
typedef struct 
{
    int data[MAXSIZE];
    int front, rear;
}SqQueue;

// 初始化
status InitQueue(SqQueue* queue);

// 入队（插入数据）
status EnQueue(SqQueue* queue, int data);


// 出队（删除数据）
status DeQueue(SqQueue* queue, int* e);

// 判断队空
int QueueEmpty(SqQueue queue);

// 读队头元素
status GetHead(SqQueue queue, int* e);