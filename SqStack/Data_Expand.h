/*************************************
**顺序栈的扩展操作
**************************************/
#ifndef DATA_EXPAND_H
#define DATA_EXPAND_H

#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

/*将任意十进制数m转换成n进制数(2<=n<=16)输出.*/
void Conversion_ten_to_n(const unsigned int m, const unsigned int n);

/*将任意二进制数data转换成n进制数(2<=n<=16)输出.m为以NUll结尾的'0'和'1'的字符串*/
void Conversion_two_to_n(const char m[], const unsigned int n);

/*逆波兰计算器*/
void ReversePolishNotation(void);

/*括号匹配*/
void BracketsMatch(void);

#endif