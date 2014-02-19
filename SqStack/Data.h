/*****************
**栈的顺序数据结构
*****************/
#ifndef DATA_H
#define DATA_H

#include "Main_First.h"

#define STACK_INIT_SIZE 10		/*栈的初始分配量.*/
#define STACK_INCREMENT 5		/*栈的每次分配增量.*/

typedef int Elem;

typedef struct SqStack
{
	Elem *Bottom;			/*栈底指针.*/
	Elem *Top;			/*栈顶指针,始终指向栈顶元素的下一个位置.*/
	size_t stacksize;	/*当前栈允许的的最大长度(即当前栈空间分配量).*/

}SQSTACK, *PSQSTACK;


#endif