#include <stdio.h>
int main()
{
	int count=0,max=0, x, t;
	scanf_s("%d",&x);//不要漏掉%，否则报错C6271传递给scanf额外的参数和C4474格式字符串传递的参数太多
	while(x>0)
	{
		t = x % 10;
		if (t == 0)//不要多分号，否则报错C4390找到空的受控语句或者0的个数运算错误
		{
			count++; 
		}
		if (t > max)
		{
			max = t;
		}
			x /= 10;
	}
	printf("这个数有%d个0，最大的数是%d", count, max);
	return 0;
}