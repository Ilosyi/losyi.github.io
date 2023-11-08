#include <stdio.h>
/*水仙花数*/
int main()
{
	int n;                              //位数n
	printf("请输入n的值:");
	scanf_s("%d", &n);
	int first = 1; int i = 1;           //利用first确认i的范围
	for (first = 1; first < n; first++)
	{
		i *= 10;
	}
	first = i;
	for (i = first; i < first * 10; i++) //第一层循环，遍历i-i*10
	{
		int t = i;           //中间变量t
		int sum = 0;         //sum为各位数字的次方和
		while (t > 0)        //第二层血循环以此取出各位数字
		{
			int d = t % 10; int p = d; int j = 1;    //利用中间变量p进行计算n次方
			t /= 10;           //也可利用<math.h>中的pow函数计算   pow（底数，指数）
			do {                          //利用j和第三层循环计算n次方（p的值）
				p *= d;
				j++;
			} while (j < n);
			sum += p;                //加起来（第二层循环中）

		}
		if (i == sum)
		{
			printf("%d\n", i);     //输出
		}
	}     //第一层循环结束
	return 0;
}
