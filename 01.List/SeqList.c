#include "./head/SeqList.h"

// 初始化（InitList）
status InitList(SqList* list)
{
    list->data = (int *)malloc(INITSIZE * sizeof(int));

    // 如果没有成功开辟内存，就返回 ERROR
    if(list->data == NULL)  
    {
        return ERROR;
    }

    list->len = 0;
    list->maxSize = INITSIZE;

    return OK;
}

// 销毁（DestroyList）
status DestroyList(SqList* list)
{
    if(list->data == NULL)
    {
        return ERROR;
    }

    free(list->data);
    list->data = NULL;      // 设置为 NULL, 为了防止后续非法访问
    list->len = 0;
    list->maxSize = 0;

    return OK;
}

// 插入（ListInsert）
status ListInsert(SqList* list, int pos, int e)
{
    if(list->data == NULL)
    {
        return ERROR;
    }

    if(list->len == list->maxSize)  // 判断当前的顺序表是否以及满了
    {
        return ERROR;
    }

    if (pos> (list->len + 1) || pos<= 0)  // 判断插入的位置是否有效
    {
        return ERROR;
    }

    list->data[list->len] = e;
    for(int index = list->len; index > pos - 1; index--)
    {
        int temp = list->data[index];
        list->data[index] = list->data[index - 1];
        list->data[index - 1] = temp;
    }
    list->len++;

    return OK;
}

// 删除（ListDelete）
status ListDelete(SqList* list, int pos, int* e)
{
    if(list->data == NULL)
    {
        return ERROR;
    }

    if (pos> list->len || pos<= 0)  // 判断插入的位置是否有效
    {
        return ERROR;
    }

    *e = list->data[pos- 1];
    int index;

    // 指定位置 pos后面的元素前移
    for(index = pos- 1; index < list->len; index++)
        list->data[index] = list->data[index + 1];

    // 长度 -1，让后面的元素无法被正常访问
    list->len--;
    return OK;
}

// 按值查找（LocateElem）
int locateElem(SqList* const list, int e)
{
    if(list->data == NULL)
    {
        return -1;
    }

    int i;
    for(i = 0; i < list->len; i++)
        if(list->data[i] == e)
            return i+1;     // 返回的是位置，不是下标，所以要 加1
    
    return -1;  // 返回 -1 表示没有后找到找到
}

// 按位查找（GetElem）
int GetElem(SqList* const list, int pos)
{
    if(list->data == NULL)
    {
        return 0;
    }

    if (pos > list->len || pos <= 0)
    {
        return 0;
    }
    
    return list->data[pos- 1];   // 返回第 i 位元素的值
}

// 求表长（Length）
int Length(SqList* const list)
{
    if(list->data == NULL)
    {
        return -1;
    }

    return list->len;
}

// 打印顺序表（PrintList）
status PrintList(SqList* const list)
{
    if(list == NULL)
    {
        return ERROR;
    }
    int i;
    for(i = 0; i < list->len; i++)
    {
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

// 判断表是否为空（Empty）
int Empty(SqList* const list)
{
    if(list->data == NULL)
    {
        return -1;
    }

    if(list->len == 0)
        return 1;   // 返回 1，表示顺序表为空
    else
        return 0;   // 返回 0，表示顺序表不为空
}

// 修改容量（ModifyCap）
status ModifyCap(SqList* list)
{
    if(list->data == NULL)
    {
        return 0;
    }

    int* temp = (int *)realloc(list->data, (list->maxSize + 10) * sizeof(int));
    if(temp == NULL)
    {
        return ERROR;
    }
    if(temp != list->data)
    {
        list->data = temp;
    }

    list->maxSize += 10;
}