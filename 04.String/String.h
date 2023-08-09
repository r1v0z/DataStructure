#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 255      // 串的最大长度
#define TRUE 1          // 表示真值
#define FALSE 0         // 表示假值


typedef int Status;

// 字符串的定义
typedef struct String
{
    char ch[MAXLEN];
    int len;
}String;

// 1. 将字符串赋值给串
Status StrAssign(String* T, char* chars);

// 2. 复制字符串
Status StrCopy(String* S, String* T);

// 3. 清空串
Status ClearString(String* S);

// 4. 判断串空
int StrEmpty(String* S);

// 5. 求串的长度
int StrLength(String* S);

// 6. 字符串比较
int StrCompare(String* S, String* T);

// 7. 拼接字符串
Status ConCat(String* T, String* S1, String* S2);

// 8. 从串中截取子串
Status SubString(String* S, String* Sub, int pos, int len);