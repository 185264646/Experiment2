#include <stdio.h>
int main(void)
{
	char in[BUFSIZ];
	int ret;
	while ((ret = scanf("%s", in)) && ret != EOF)
		printf("%s ", in);
	return 0;
}