#include <stdio.h>
int main(void)
{
	for (int i = 100; i < 1000; i++)
		if (i * i % 1000 == i)
			printf("%d ", i);
	return 0;
}