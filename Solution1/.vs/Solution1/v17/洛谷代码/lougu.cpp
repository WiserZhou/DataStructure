#include <cstring> //直接过P3383
#include <cctype>
#include <cstdio>
#include <string>
#define N 10000000
using namespace std;
bool a[N + 5];
int main()
{
	memset(a, true, sizeof(a));
	a[1] = false;
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= N; i++)
	{
		if (a[i])
		{
			for (int j = 2; i * j <= N; j++)
			{
				a[i * j] = false;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		if (a[m])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}