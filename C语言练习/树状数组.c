#include<stdio.h>
#define N 8

int a[N] = {1,2,3,4,5,6,7,8};
int b[N + 1] = { 0 };
int lowbit(int x)
{
	return x & (-x);
}
void add(int p, int x)
{
	while (p < N) {
	b[p] += x;
	p += lowbit(p);
}
}
int count(int p)
{
	int result = 0;
	while (p)
	{
		result += b[p];
		p -= lowbit(p);
	}
	return result;
}
void build(int arr[], int n)
{
	for (int i = 1; i <=n; i++)
	{
		add(i, arr[i - 1]);
	}
}
int main()
{
	build(a, N);
	add(3, 3);
	int cnt = count(3);
	printf("%d", cnt);
	return 0;
}
