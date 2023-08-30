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
			printf("%d ���ڣ������±�Ϊ %d\n", k, mid);
		else
			printf("%d ������\n", k);
	}
	return 0;
}
/*
*�ܹ���n��Ԫ�أ�ÿ�β��ҵ������С����n��n/2��n/4������n/2^k������������Ԫ�ص�ʣ�������������k����ѭ���Ĵ����� 
*����n/2^kȡ����>=1������n/2^k=1�� 
*�ɵ�k=log2n,������2Ϊ�ף�n�Ķ�����������ʱ�临�Ӷȿ��Ա�ʾO()=O(logn)��
*
*/