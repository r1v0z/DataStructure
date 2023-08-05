#include "./head/StackList.h"

// 初始化
status Init(StackList* s)
{
    
}

// 入栈
status push(StackList* s, int data);

// 出栈
status pop(StackList* s, int* e);

// 判断栈空
int isEmpty(StackList* s);

// 获取栈顶元素
status GetTop(StackList* s, int* e);