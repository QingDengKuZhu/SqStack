#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

/*
pS为指向栈的指针,且pS不为NULL.
*/

void InitStack(PSQSTACK pS)
{
	pS->Bottom = (Elem *)malloc(sizeof(Elem) * STACK_INIT_SIZE);
	if (!pS->Bottom)
	{
		printf("栈初始化失败!\n");
		exit(ERROR);
	}

	pS->stacksize = STACK_INIT_SIZE;	
	pS->Top = pS->Bottom;		/*刚初始化后,栈为空,此时栈指针与栈底指针相等.*/
	
	return;
}

void DestroyStack(PSQSTACK pS)
{
	free(pS->Bottom);
	pS->Bottom = NULL;
	pS->stacksize = 0;	/*释放内存后,长度为0.*/
	pS->Top = NULL;
	
	return;
}

void ClearStack(PSQSTACK pS)
{
	pS->Top = pS->Bottom;
	
	return;
}

BOOL StackEmpty(PSQSTACK pS)
{
	if (pS->Top == pS->Bottom)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

size_t StackLength(PSQSTACK pS)
{
	
	return (size_t)(pS->Top - pS->Bottom);	/*指针之差的类型为signed int, size_t为unsigned int.*/
}

STATUS GetTop(PSQSTACK pS, Elem *e)
{
	if (TRUE == StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		*e = *(pS->Top-1);	/*栈顶指针Top,始终指向栈顶元素的下一个位置.*/

		return OK;
	}
}

void Push(PSQSTACK pS, const Elem v)
{
	/*
	**当栈已满时.
	*/
	if (pS->stacksize == (size_t)(pS->Top - pS->Bottom))
	{
		 pS->Bottom = realloc(pS->Bottom, (pS->stacksize + STACK_INCREMENT)*sizeof(Elem));
		if (!pS->Bottom)
		{
			printf("扩展栈失败!\n");
			exit(ERROR);
		}

		pS->Top = pS->Bottom + pS->stacksize;	/*与下一步操作顺序不能颠倒!*/
		pS->stacksize += STACK_INCREMENT;
	}
	
	/*
	**插如数据
	*/
	*(pS->Top) = v;
	++pS->Top;	/*移动栈顶指针.*/

	return;
}

STATUS Pop(PSQSTACK pS, Elem *e)
{
	if (TRUE == StackEmpty(pS))	/*若栈为空,则无法弹出栈顶元素.*/
	{
		return FAILE;
	}
	else
	{
		--pS->Top;
		*e = *pS->Top;
		return OK;
	}

}

void TraveStack(PSQSTACK pS)
{
	Elem *p = pS->Bottom;
	while (p != pS->Top)
	{
		printf("%d ", *p);
		++p;
	}

	return;
}
