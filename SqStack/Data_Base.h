/**********************
**栈的基本操作.
***********************/
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include "Main_First.h"
#include "Data.h"
/*
pS为指向栈的指针,且pS不为NULL.
*/

/*构造一个空的栈.*/
void InitStack(SQSTACK *pS);

/*销毁栈.*/
void DestroyStack(SQSTACK *pS);

/*将栈清空.*/
void ClearStack(SQSTACK *pS);

/*判断栈是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL StackEmpty(const SQSTACK *pS);

/*返回栈中元素个数,即长度.*/
size_t StackLength(const SQSTACK *pS);

/*获取栈顶元素.若操作成功,函数返回OK,*e保存栈顶的值;若操作失败,函数返回FAILE,*e为垃圾值.*/
STATUS GetTop(const SQSTACK *pS, Elem *e);

/*插入新的数据元素v为栈顶元素.*/
void Push(SQSTACK *pS, const Elem v);

/*删除栈顶元素.若成功删除,函数返回OK,*e保存被删除元素的值;否者函数返回FAILE,*e为垃圾值.*/
STATUS Pop(SQSTACK *pS, Elem *e);

/*从栈底到栈顶依次输出栈中元素.*/
void TraveStack(const SQSTACK *pS);

#endif