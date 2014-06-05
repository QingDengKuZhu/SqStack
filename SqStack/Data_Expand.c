#include "Data_Base.h"
#include "ctype.h"
#include <string.h>
#include <math.h>	//pow()

void Conversion_ten_to_n(const unsigned int m_ten, const unsigned int n)
{
	char ch[16] = {'0', '1', '2', '3', 
				   '4', '5', '6', '7', 
				   '8', '9', 'A', 'B', 
				   'C', 'D', 'E', 'F'};
	SQSTACK S;
	unsigned int M_ten = (unsigned int)m_ten;
	InitStack(&S);

	while (M_ten != 0)
	{
		Push(&S, M_ten%n);
		M_ten/=n;
	}

	printf("转换为%d进制数为: ", n);
	
	while (FALSE == StackEmpty(&S))
	{
		Elem temp;
		Pop(&S, &temp);
		printf("%c", ch[temp]);
	}
	
	DestroyStack(&S);
	
	return;
}

void ReversePolishNotation(void)
{
	SQSTACK S;
	char c;	
	int result;		/*结果*/
	char str[10];		/*缓冲区*/
	size_t i = 0;
	int a, b;		/*操作数*/

	InitStack(&S);

	printf("请按照逆波兰表达式输入带计算数据,数据与运算符之间以空格间隔,以#结尾!\n");
	scanf("%c", &c);	

	while (c != '#')
	{
		while (0 != isdigit(c))	/*过滤数字*/
		{
			str[i++] = c;
			str[i] = '\0';
			if (i == 10)
			{
				printf("出错,输入的单个数据过大!\n");
			
				exit(ERROR);
			}

			scanf("%c", &c);
			if (' ' == c)
			{
				Push(&S, atoi(str));	/*将字符转换成数字压入栈中.*/
			}
		}

		i = 0;

		switch (c)
		{
		case '+':
			Pop(&S, &b);
			Pop(&S, &a);
			Push(&S, a+b);
	
			break;	
			
		case '-':
			Pop(&S, &b);
			Pop(&S, &a);
			Push(&S, a-b);	/*注意相减的顺序*/				
	
			break;
		
		case '*':
			Pop(&S, &b);	
			Pop(&S, &a);
			Push(&S, a*b);

			break;

		case '/':	/*注意谁是除数谁是被除数,以及除数不能为0!*/
			Pop(&S, &b);
			Pop(&S, &a);
		
			if (b == 0)
			{
				printf("除数不能为0!\n");
				exit(ERROR);
			}

			Push(&S, a/b);
				
			break;
	
		case ' ':
			
			break;

		default:
			printf("不能用两个空格间隔!\n");
			exit(ERROR);
			break;
		}

		scanf("%c", &c);
	}
	
	Pop(&S, &result);
	/*若输入的是逆波兰表达式,则最后栈一定为空!*/
	if (TRUE != StackEmpty(&S))
	{
		printf("输入的不是逆波兰表达式!!!\n");
		exit(ERROR);
	}
				
	printf("逆波兰表达式的结果是: %d", result);
	
	getchar();

	return;
}

void Conversion_two_to_n(const char  m[], const unsigned int n)
{
	SQSTACK S;
	size_t length = strlen(m);
	size_t i = 0;
	unsigned int ten_sum = 0;	//临时存储字符串代表的二进制数的十进制值
	long  temp = atoi(m);		//二进制的外在表现
	int e;					//临时存储出栈的元素.
	int j;					//二进制数转换成十进制数时使用
	
	InitStack(&S);

	while (temp != 0)
	{
		Push(&S, temp%10);
		temp /= 10;
	}//此时最高位在栈顶,最低位在栈底

	j = StackLength(&S) - 1;
	
	//将二进制数转换成十进制
	while (FALSE == StackEmpty(&S))
	{
		Pop(&S, &e);
		ten_sum += e * (int)pow(2*1.0, j*1.0);
		j--;
	}
	
	//销毁栈,避免内存泄漏
	DestroyStack(&S);
	
	//输出
	Conversion_ten_to_n(ten_sum, n);
	
	return;
}

void BracketsMatch(void)
{
	int inputdata;		//存储输入数据
	int topdata;			//存储当前栈的栈顶元素
	int n;				//存储对应的括号的十进制表达式的差

	SQSTACK S;
	InitStack(&S);
	
	printf("请输待匹配数据('#'表示输结束):");
	scanf("%d", &inputdata);

	while ((int)'#' != inputdata)
	{
		//过滤非括号输入
		if ('('!=inputdata && ')'!=inputdata && '{'!=inputdata && '}'!=inputdata && '['!=inputdata && ']'!=inputdata)
		{
			getchar();
			scanf("%d", &inputdata);

			continue;
		}

		if (StackEmpty(&S) == TRUE)
		{
			Push(&S, inputdata);
			getchar();		
			scanf("%d", &inputdata);
		
			continue;
		}

		GetTop(&S, &topdata);	//因为栈非空,所以一定会取得栈顶元素
		n = abs(topdata-inputdata);
		if (1 == n || 2 == n)
		{
			Pop(&S, &topdata);	//其中topdata的值无用
			getchar();
			scanf("%d", &inputdata);
			
			continue;
		}

		Push(&S, inputdata);
		getchar();
		scanf("%d", &inputdata);
		
	}

	//若所有括号都匹配,则栈一定为空
	if (TRUE == StackEmpty(&S))
	{
		printf("输入的括号匹配!\n");
	}
	else
	{
		printf("输入的括号不匹配!\n");
	}

	DestroyStack(&S);//一定要执行此操作,避免内存泄漏

	getchar();
	return;
}