#include <bits/stdc++.h>
using namespace std;

int num[1000000];
int main()
{
	int n, q, l, r, mid, k;
	while (scanf("%d", &n) != -1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		scanf("%d", &k);
		l = 0;
		r = n - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (num[mid] == k)
				break;
			else if (num[mid] < k)
				l = mid + 1;
			else
				r = mid - 1;
		}
		if (num[mid] == k)
			printf("%d 存在，数组下标为 %d\n", k, mid);
		else
			printf("%d 不存在\n", k);
	}
	return 0;
}
/*
*总共有n个元素，每次查找的区间大小就是n，n/2，n/4，…，n/2^k（接下来操作元素的剩余个数），其中k就是循环的次数。 
*由于n/2^k取整后>=1，即令n/2^k=1， 
*可得k=log2n,（是以2为底，n的对数），所以时间复杂度可以表示O()=O(logn)。
*
*/