#pragma once

#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 10

#define ERROR 0     //执行遇到错误
#define OK 1    //成功执行

typedef int status;     // 返回的状态，1表示成功，0表示错误

// 0. 定义
typedef struct {
    int *data;
    int len;
    int maxSize;
}SqList;

// 1. 初始化顺序表，构造一个空的线性表list，分配内存空间
status InitList(SqList* list);

// 2. 销毁顺序表，销毁线性表，并释放线性表list所占用的内存空间
status DestroyList(SqList* list);

// 3. 插入元素，在表中的第pos个位置插入指定元素e
status ListInsert(SqList* list, int pos, int e);

// 4. 删除元素，删除表list中第pos个位置的元素，并用e返回删除元素的值
status ListDelete(SqList* list, int pos, int* e);

// 5. 按值查找，在表list中查找指定值e
int locateElem(SqList* const list, int e);

// 6. 按位查找，获取表list中第pos个位置的元素
int GetElem(SqList* const list, int pos);

// 7. 求表长,返回线性表L的长度
int Length(SqList* const list);

// 8. 打印顺序表的内容，按前后顺序输出线性表的所有元素
status PrintList(SqList* const list);

// 9. 判空，判断表是否为空
int Empty(SqList* const list);

// 10. 扩容
status Expansion(SqList* list);