#include <stdio.h>

int main()
{
	long int n = 0;
	long double x = 0, max = -2147483646;
	(void)scanf("%li", &n);
	long int i = 0;
	for (i; i<n; i++)
	{
		(void)scanf("%Lf", &x);
		if (max< x)
		{
			max = x;
		}
	}
	(void)printf("%Lf",(long double)max);
	return 0;
}
