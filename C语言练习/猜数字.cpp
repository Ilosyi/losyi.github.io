#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*猜数字游戏*/
int main()
{
	srand(time(0));
	int a = rand();   a = a % 10000;//生成随机数，并取4位数
	int num = 0; int count = 0;//创建计数变量count
	while(a!=num) //循环开始
	{
		printf("请输入你猜的值：");
		scanf_s("%d", &num);
		if (num > a)
		{
			printf("猜大了\n");
		}
		if (num <a)
		{
			printf("猜小了\n");
		}
		count++;
			
	}
	if (a = num)
	{
		printf("正确答案就是%d\n", a);
		printf("你猜了%d次\n", count);
	}

	return 0;
}