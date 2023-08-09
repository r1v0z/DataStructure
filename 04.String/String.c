#include "./String.h"

// 1. 赋值
Status StrAssign(String* T, char* chars)
{
    int len = strlen(chars);    // 获取要赋值字符串的长度
    if (len > MAXLEN)           // 判断字符串的长度是否超过能存储的字符长度
        return EXIT_FAILURE;

    T->len = len;       // 将串的长度设置为字符串的长度

    // 将字符串的内容赋值给串
    for(int i = 0; i < len - 1; i++)
        T->ch[i] = chars[i];
    
    return EXIT_SUCCESS;
}

// 2. 复制字符串
Status StrCopy(String* S, String* T)
{
    // 复制字符
    for(int i = 0; i < T->len; i++)
        S->ch[i] = T->ch[i];
    
    // 修改串的长度
    S->len = T->len;

    return EXIT_SUCCESS;
}

// 3. 清空串
Status ClearString(String* S)
{
    S->len = 0;     // 串的长度设置为 0，表示串中没有字符
    return EXIT_SUCCESS;
}

// 4. 判断串空
int StrEmpty(String* S)
{
    // 当串为空时，返回 TRUE，否则返回 FALSE
    if(S->len == 0)
        return TRUE;
    else
        return FALSE;
}

// 5. 求串的长度
int StrLength(String* S)
{
    return S->len;      // 结构体 String 中 len 存储串的长度
}

// 6. 字符串比较
int StrCompare(String* S, String* T)
{
    // 比较两串中最小长度的字符串
    for(int i = 0; i < S->len && i < T->len; i++)
    {
        if (S->ch[i] != T->ch[i])
        {
            return (S->ch[i] - T->ch[i]);
        }
    }

    // 两串前面的字符相等，那么哪个串长那就是哪个串大
    return (S->len - T->len);
}

// 7. 拼接字符串
Status ConCat(String* T, String* S1, String* S2)
{
    int i = 0;
    int j = 0;
    for(i = 0, j = 0; j < S1->len - 1; i++, j++)
        T->ch[i] = S1->ch[j];
    
    // 判断两个串的长度是否超过串能够存储的最大长度
    if (S1->len + S2->len > MAXLEN)
    {
        // 如果超过能够存储的长度，则存储到最大长度后返回
        for(j = 0; j < MAXLEN - S1->len; j++, i++)
            T->ch[i] = S2->ch[j];
        
        T->len = MAXLEN;
        return EXIT_FAILURE;
    }
    else
    {
        // 如果没有超过能够存储长度，则将串中全部字符存储
        for(j = 0; j < S2->len; j++, i++)
            T->ch[i] = S2->ch[j];
        
        T->len = i + 1;     // 串的长度等于当前下标 + 1
        return EXIT_SUCCESS;
    }
}

// 8. 从串中截取子串
Status SubString(String* S, String* Sub, int pos, int len)
{
    // 判断输入的位置、长度是否合理
    if(pos < 1 || pos > S->len || len < 1 || pos + len > S->len)
        return EXIT_FAILURE;

    int i;

    // 复制串中的内容到子串中
    for(i = 0; i < len - 1; i++)
        Sub->ch[i] = S->ch[i + pos];
    
    Sub->len = len;     // 设置子串的长度
    return EXIT_SUCCESS;
}