/**********************
**主函数, 测试
***********************/

#include "Main_First.h"
#include "Data.h"
#include "Data_Base.h"
#include "Test.h"
#include <time.h> /*随机数*/
#include "Data_Expand.h"

int main(void)
{
	int select;		/*保存选择变量*/
	Elem e;			/*保存从函数返回的结点的值*/
	Elem v;			/*保存传递给函数的结点的值*/
	
	size_t i= 0;
	SQSTACK S;
	InitStack(&S);	/*初始化栈*/

	srand((int)time(NULL));

	while (1)	/*while_@1*/
	{
		if (!(S.Bottom))
		{
			printf("栈不存在!\n");
			break;
		}

		system("cls");
		Menu();

		printf("请输入您的选择(1~9):");
		scanf("%d", &select);
		getchar();

		switch (select)	/*switch_@1*/
		{
		case 1:			/*入栈.*/
			v = InputValue("入栈元素为:");
			Push(&S, v);
			printf("入栈操作成功!\n");
			
			getchar();
			break;
		case 2:			/*输出栈中元素.*/
			printf("栈为:");
			TraveStack(&S);
			
			getchar();
			break;
		case 3:			/*出栈.*/
			if (OK == Pop(&S, &e))
			{
				printf("出栈成功,出栈元素是%d!\n", e);
			}
			else
			{
				printf("出栈失败!\n");
			}

			getchar();
			break;

		case 4:			/*输出栈的长度.*/
			printf("栈长为: %d \n", StackLength(&S));
			
			getchar();
			break;

		case 5:			/*清空栈.*/
			ClearStack(&S);
			printf("该栈已经清空!\n");
			
			getchar();
			break;
	
		case 6:			/*销毁栈.*/
			DestroyStack(&S);
			printf("栈已删除!\n");
			
			getchar();	
			break;
			
		case 7:			/*返回栈顶结点元素.*/
			if (OK == GetTop(&S, &e))
			{
				printf("栈顶为:%d\n", e);
			}
			else
			{
				printf("不存在栈顶元素!\n");
			}

			getchar();	
			break;

		case 8:			/*判断栈是否为空.*/
			if (StackEmpty(&S) == TRUE)
			{
				printf("栈为空!\n");
			}
			else
			{
				printf("栈非空!\n");
			}
	
			getchar();	
			break;

		case 9:			/*进制转换*/
		{
			int d;
			unsigned int m, n;
			 v = InputValue("请输入一个非负整数:");
			 d = InputValue("请输入转换进制:");
			 if (v < 0 ||d<2 ||d>16)
			 {
				 printf("输入数据错误!\n");
				 break;
			 }

			 m = (unsigned int)v;
			 n = (unsigned int)d;
			 Conversion_ten_to_n(m, n);
			
			 getchar();
			 break;
		}

		case 10:
			ReversePolishNotation();

			getchar();
			break;
		
		default:
			printf("请重新选择!\n");
			
			getchar();
			break;
		}/*switch_@1*/

	}	/*while_@1*/
	
	return EXIT_SUCCESS;
}