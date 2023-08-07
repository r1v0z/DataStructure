#include "./QueueList.h"

int main(void)
{
    LinkQueue queue;
    LinkQueue* Pqueue = & queue;
    int e = 0;
    InitQueue(Pqueue);
    if(QueueEmpty(queue))
        printf("queue is Empty!\n");
    else
        printf("queue is not Empty!\n");

    EnQueue(Pqueue, 1);
    GetHead(queue, &e);
    printf("e: %d\n", e);
    EnQueue(Pqueue, 2);
    EnQueue(Pqueue, 3);
    EnQueue(Pqueue, 4);
    EnQueue(Pqueue, 5);

    DeQueue(Pqueue, &e);
    printf("e: %d\n", e);
    GetHead(queue, &e);
    printf("e: %d\n", e);
    if(QueueEmpty(queue))
        printf("queue is Empty!\n");
    else
        printf("queue is not Empty!\n");

    DestroyQueue(Pqueue);
    if(QueueEmpty(queue))
        printf("queue is Empty!\n");
    else
        printf("queue is not Empty!\n");
    
    


    return EXIT_SUCCESS;
}