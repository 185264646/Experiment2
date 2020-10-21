#include <stdio.h>
int main(void)
{
	char a[BUFSIZ], b;
	int num;
	while(gets(a))
		if(sscanf(a, "%i%c", &num, &b) == 1)
			puts("Valid");
		else
			puts("Invalid");
	return 0;
}