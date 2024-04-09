#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, a, b;
int max(int a,int b)
{
	return a >= b ? a : b;
}
int min(int a, int b)
{
	return a <= b ? a : b;
}
int ans=INT_MAX;
int visit[5005];
void dfs(int x, int step)
{
	if (x == b) {
		ans = min(ans, step);
		return;
	}
	if (visit[x]<step) return;
	visit[x] = step;
	if (x + 1 <= n) dfs(x + 1, step + 1);
	if (x - 1 >=0  ) dfs(x - 1, step + 1);
	if (x * 2 <= n) dfs(x * 2, step + 1);
	return;
}
int main()
{
	memset(visit, 0x3f, sizeof(visit));
	scanf("%d%d%d", &n, &a, &b);
	dfs(a, 0);
	printf("%d", ans);
}
