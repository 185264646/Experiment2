#include <stdio.h>
#include <stdlib.h>
_Bool is_valid(int);

_Bool nums[10];

int main(void)
{
	int x, y, z = 0; // z / y = x
	scanf("%d", &x);
	for (y = 1234; z <= 98765; y++)
	{
		memset(nums, 0, 10 * sizeof(_Bool));
		if (!is_valid(y))
			continue;
		else if (!is_valid(z = y * x))
			continue;
		else
			printf("%05d / %05d = %d\n", z, y, x);
	}
	return 0;
}

_Bool is_valid(int num)
{
	for (int i=0; i < 5; i++)
		if (nums[num % 10])
			return 0;
		else
		{
			nums[num % 10] = 1;
			num /= 10;
		}
	return 1;
}