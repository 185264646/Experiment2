/* 实验2-1改错题程序：合数判断器 */
#include <stdio.h>
int main()
{
	int i, x, k, flag = 0;
	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	while (scanf("%d", &x) != EOF)
	{
		i = 2;
		k = x >> 1;
		do
		{
			if (!(x % i))
			{
				flag = 1;
				break;
			}
			i++;
		}
		while (i <= k);
		if (flag == 1)
			printf("%d是合数", x);
		else
			printf("%d不是合数", x);
	}
	return 0;
}

