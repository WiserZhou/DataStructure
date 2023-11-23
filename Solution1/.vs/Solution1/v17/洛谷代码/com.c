#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isPrime(int n)
{
	if (n == 0 || n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}
int isRight(int n, int m)
{
	for (int i = n; i < m; i++)
	{
		if (isPrime(n) == 1 && isPrime(m - n) == 1)
			return n;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i += 2)
	{
		for (int j = 2; j < i - 1; j++)
		{
			if (isRight(j, i) != 0)
			{
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
		}
	}
	return 0;
}