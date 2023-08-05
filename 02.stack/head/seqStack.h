#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int status;


// 栈的定义
typedef struct stack
{
    int data[MAXSIZE];
    int top;
}Stack;

// 初始化
status Init(Stack* s);

// 入栈
status push(Stack* s, int data);

// 出栈
status pop(Stack* s, int* e);

// 判断栈空
int isEmpty(Stack* s);

// 获取栈顶元素
status GetTop(Stack* s, int* e);