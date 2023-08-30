#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define LL long long

const int N = ;

struct qwq{
	int nxt,to;
};
qwq edge[N * 2];

int cnt,n,x,y;
int dp[N],head[N];

void addedge(int f,int t)
{
	edge[++ cnt].nxt = head[f];
	edge[cnt].to = t;
	head[f] = cnt;
}

void dfs(int now,int fa)
{
	for(int i = head[now];i;i = edge[i].nxt)
	{
		int to = edge[i].to;
		if(to == fa) continue;
		dfs(to,now);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 1;i < n;i ++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	return (0 ^ 0);
}
