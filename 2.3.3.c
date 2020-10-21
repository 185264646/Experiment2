#include <stdio.h>
int combination(int m ,int n) // Calculate C(m, n)
{
	int numerator = 1, denominator = 1; // 
	if (m == 0 || n == 0)
		return 1;
	if (m < 2 * n)
		n = m - n;
	for (int i = 1; i <= n; i++)
	{
		numerator *= m--;
		denominator *= i;
	}
	return numerator / denominator;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 10 - i; k; k--)
			printf("  ");
		for (int j = 0; j <= i; j++)
			printf("%4d", combination(i, j));
		putchar('\n');
	}
	return 0;
}