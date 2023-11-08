/*求1000以内的完数，如果一个数等于它的因子之和，那么这个数为完数*/
#include <stdio.h>
int isPerfect(int x)
{
	int s, y;
	s = 0;
	for (y = 1; y <=x/2;y++)
	{
		if (x % y == 0)
			s += y;
	}
	if (s == x)
	{
		printf("%5d", x);
	}
	return 0;
}
int main()
{
	printf("1000以内的完数有：");
	for (int i = 1; i <= 1000; i++)
	{
		isPerfect(i);
	}
	return 0;
}


