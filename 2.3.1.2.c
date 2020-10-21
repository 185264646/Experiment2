#include <stdio.h>
float tax_rate[] = { .05, .1, .15, .2, .25 };
int tax_level[] = { 1000, 2000, 3000, 4000, 5000 };
float tax_stable[] = {0, 50, 150, 300, 500};  // 税收分为flexible和stable两部分， 其中某个阶梯以下的部分为stable，两阶梯之间的为flexible

int main(void)
{
	unsigned revenue;
	float tax;
	int taxlevel;
	scanf("%u", &revenue);
	switch(taxlevel = revenue / 1000)
	{
		case 0: tax = 0; break;
		default :
			tax = tax_stable[taxlevel - 1] + (revenue - tax_level[taxlevel - 1]) * tax_rate[taxlevel - 1];
	}
	printf("%.2f", tax);
	return 0;
}
		