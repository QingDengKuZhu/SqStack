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
void InitStack(PSQSTACK pS);

/*销毁栈.*/
void DestroyStack(PSQSTACK pS);

/*将栈清空.*/
void ClearStack(PSQSTACK pS);

/*判断栈是否为空.若为空,函数返回TRUE;否者函数返回FALSE.*/
BOOL StackEmpty(PSQSTACK pS);

/*返回栈中元素个数,即长度.*/
size_t StackLength(PSQSTACK pS);

/*获取栈顶元素.若操作成功,函数返回OK,*e保存栈顶的值;若操作失败,函数返回FAILE,*e为垃圾值.*/
STATUS GetTop(PSQSTACK pS, Elem *e);

/*插入新的数据元素v为栈顶元素.若成功,函数返回OK;否者返回FAILE.*/
STATUS Push(PSQSTACK pS, const Elem v);

/*删除栈顶元素.若成功删除,函数返回OK,*e保存被删除元素的值;否者函数返回FAILE,*e为垃圾值.*/
STATUS DeleteStack(PSQSTACK pS, const size_t pos, Elem *e);

/*从栈底到栈顶依次输出栈中元素.*/
void TraveStack(PSQSTACK pS);

#endif