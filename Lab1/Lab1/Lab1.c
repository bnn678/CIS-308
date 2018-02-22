#include <stdio.h>

int Power(int base, int power)
{
	if (power > 0)
	{
		return (base*Power(base, power - 1));
	}
	else
		return 1;
}

int main()
{
	printf("Base: ");
	int base = 0;
	scanf_s("%d", &base);;
	printf("Power: ");
	int power = 0;
	scanf_s("%d", &power);

	if ((base < 0) || (power < 0))
	{
		printf("Input error. Inputs must be non-negative.");
		return 1;
	}
	else if ((base == 0) && (power == 0))
	{
		printf("Input error. At least one input must be non-zero.");
		return 1;
	}
	else
	{
		int result = Power(base, power);
		printf("%d\n", result);
	}

	return 0;
}