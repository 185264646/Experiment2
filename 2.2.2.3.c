/* 实验2-1改错题程序：合数判断器 */
#include <stdio.h>

_Bool isprime(int);
int main(void)
{
	for (int i=400; i<1000; i++)
	{
		if (isprime(i) && isprime(i/10) && isprime(i/100))
			printf("%d\n", i);
	}
	return 0;
}

_Bool isprime(int num)
{
	int i, k;
	_Bool flag = 0;
	for (i = 2, k = num >> 1; i <= k; i++)
		if (!(num % i))
		{
			flag = 1;
			break;
		}
	return flag;
}