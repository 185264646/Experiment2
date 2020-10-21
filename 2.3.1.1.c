#include <stdio.h>
float tax_rate[] = { .05, .1, .15, .2, .25 };
int tax_level[] = { 1000, 2000, 3000, 4000, 5000 };

int main(void)
{
	float tax, revenue;
	scanf("%f", &revenue);
	if (revenue < 1000)
		tax = 0;
	else if (revenue < 2000)
		tax = (revenue - tax_level[0]) * tax_rate[0];
	else if (revenue < 3000)
		tax = (tax_level[1] - tax_level[0]) * tax_rate[0] + (revenue - tax_level[1]) * tax_rate[1];
	else if (revenue < 4000)
		tax = (tax_level[2] - tax_level[1]) * tax_rate[1] +
			(tax_level[1] - tax_level[0]) * tax_rate[0] + (revenue - tax_level[2]) * tax_rate[2];
	else if (revenue < 5000)
		tax = (tax_level[3] - tax_level[2]) * tax_rate[2] +
			(tax_level[2] - tax_level[1]) * tax_rate[1] +
			(tax_level[1] - tax_level[0]) * tax_rate[0] + (revenue - tax_level[3]) * tax_rate[3];
	else
		tax = (tax_level[4] - tax_level[3]) * tax_rate[3] +
			(tax_level[3] - tax_level[2]) * tax_rate[2] +
			(tax_level[2] - tax_level[1]) * tax_rate[1] +
			(tax_level[1] - tax_level[0]) * tax_rate[0] + (revenue - tax_level[4]) * tax_rate[4];
	printf("%.2f", tax);
	return 0;
}