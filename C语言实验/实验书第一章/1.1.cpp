//若一个数加上100或者268都是一个完全平方数，这个是多少？
#include <stdio.h>
#include<math.h>
int main()
{
	long x, y;
	for (int i = 1; i <= 10000; i++)
	{
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if ((x * x == i+100) && (y * y == i+268))
			printf("%d\n", i);
	}
	return 0;
}