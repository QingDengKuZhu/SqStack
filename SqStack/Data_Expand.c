#include "Data_Base.h"
#include "ctype.h"

void Conversion_ten_to_n(const unsigned int m, const unsigned int n)
{
	char ch[16] = {'0', '1', '2', '3', 
				   '4', '5', '6', '7', 
				   '8', '9', 'A', 'B', 
				   'C', 'D', 'E', 'F'};
	SQSTACK S;
	unsigned int M = (unsigned int)m;
	InitStack(&S);

	while (M != 0)
	{
		Push(&S, M%n);
		M/=n;
	}

	printf("十进制数%d转换为%d进制数为: ", m, n);
	
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
	char str[10];	/*缓冲区*/
	size_t i = 0;
	int a, b;	/*操作数*/

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