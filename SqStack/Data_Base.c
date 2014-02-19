#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

/*
pS为指向栈的指针,且pS不为NULL.
*/

void InitStack(PSQSTACK pS)
{
	pS->Base = (Elem *)malloc(sizeof(Elem) * STACK_INIT_SIZE);
	if (!pS->Base)
	{
		printf("栈初始化失败!\n");
		exit(ERROR);
	}

	pS->stacksize = STACK_INIT_SIZE;	
	pS->Top = pS->Base;		/*刚初始化后,栈为空,此时栈指针与栈底指针相等.*/
	
	return;
}

void DestroyStack(PSQSTACK pS)
{
	free(pS->Base);
	pS->Base = NULL;
	pS->stacksize = 0;	/*释放内存后,长度为0.*/
	pS->Top = NULL;
	
	return;
}

void ClearStack(PSQSTACK pS)
{
	pS->Top = pS->Base;
	
	return;
}

BOOL StackEmpty(PSQSTACK pS)
{
	if (pS->Top == pS->Base)
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
	
	return (pS->Top - pS->Base);
}

STATUS GetTop(PSQSTACK pS, Elem *e)
{
	Elem *p = pS->Top;
	if (TRUE == StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		--p;/*未进行自减操作前,指向栈顶元素的下一个位置.*/
		*e = *p;

		return OK;
	}
}

STATUS Push(PSQSTACK pS, const Elem v)
{
	/*
	**当栈已满时.
	*/
	if (pS->stacksize == pS->Top - pS->Base)
	{
		Elem *pNewBase = realloc(pS->Base, (pS->stacksize + STACK_INCREMENT)*sizeof(Elem));
		if (!pNewBase)
		{
			printf("扩展栈失败!\n");
			exit(ERROR);
		}

		pS->Base = pNewBase;
		pS->Top = pS->Base + pS->stacksize;	/*与下一步操作顺序不能颠倒!*/
		pS->stacksize += STACK_INCREMENT;
	}
	
	/*
	**插如数据
	*/
	*(pS->Top) = v;
	++pS->Top;	/*移动栈顶指针.*/

	return OK;
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
		*e = pS->Top;
		return OK;
	}

}

void TraveStack(PSQSTACK pS)
{
	Elem *p = pS->Base;
	while (p != pS->Top)
	{
		printf("%d ", *p);
		++p;
	}
}

#endif
