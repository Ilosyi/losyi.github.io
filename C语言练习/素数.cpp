#include <stdio.h>
#include<math.h>
int sushu(int x)
{
	int ret = 1;
	int i;
	if (x == 1 || (x % 2 == 0 && x != 2))
		ret = 0;
	for (i = 3; i < sqrt(x); i += 2)
	{
		if (x % i == 0)
			ret = 0;
		break;
	}
	if (ret == 1)
	{
		printf("%5d", x);
	}
	return ret;
}
int main()
{
	int x;
	for (x = 1; x < 10000; x++)
	{
		sushu(x);
	}
	return 0;
}
