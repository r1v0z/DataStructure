#include "./head/seqStack.h"


status Init(Stack* s)
{
    s->top = -1;
    return EXIT_SUCCESS;
}

// 入栈
status push(Stack* s, int data)
{
    if (s->top >= MAXSIZE - 1)
    {
        return EXIT_FAILURE;
    }

    s->top += 1;
    s->data[s->top] = data;
    
    return EXIT_SUCCESS;
}

// 出栈
status pop(Stack* s, int* e)
{
    if(s->top == -1)
        return EXIT_FAILURE;
    
    *e = s->data[s->top];
    s->top -= 1;

    return EXIT_SUCCESS;
}

// 判断栈空
int isEmpty(Stack* s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

// 获取栈顶元素
status GetTop(Stack* s, int* e)
{
    if(s->top == -1)
        return EXIT_FAILURE;
    else
    {
        *e = s->data[s->top];
        return EXIT_SUCCESS;
    }
}