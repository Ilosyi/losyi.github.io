/*输入年月日，判断这一天是这一年的第几天，为了保持月份和数组下标一致，增强可读性，讲mdays[0]
设置为0。*/
#include <stdio.h>
int main()
{
	int day, month, year, sum, leap, i;
	leap=28;//leap初始化才能使用，否则报错C6001:使用未初始化内存
	int mdays[12] = { 0,31,leap,31,30,31,30,31,31,30,31,30};
	scanf_s("%d%d%d", &year, &month, &day);
	sum = 0;
	if ((year % 4 == 0 && year % 100 != 0 )|| (year % 400 == 0))
	{
		leap = 29;
		mdays[2] = leap;  // 更新闰年的天数,否则数组中值没有改变

	}
	for (i = 1; i < month; i++)
	{
		sum += mdays[i];
	}
	sum += day;
	printf("%d", sum);
}