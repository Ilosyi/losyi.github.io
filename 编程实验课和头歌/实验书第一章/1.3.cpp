/*���������գ��ж���һ������һ��ĵڼ��죬Ϊ�˱����·ݺ������±�һ�£���ǿ�ɶ��ԣ���mdays[0]
����Ϊ0��*/
#include <stdio.h>
int main()
{
	int day, month, year, sum, leap, i;
	leap=28;//leap��ʼ������ʹ�ã����򱨴�C6001:ʹ��δ��ʼ���ڴ�
	int mdays[12] = { 0,31,leap,31,30,31,30,31,31,30,31,30};
	scanf_s("%d%d%d", &year, &month, &day);
	sum = 0;
	if ((year % 4 == 0 && year % 100 != 0 )|| (year % 400 == 0))
	{
		leap = 29;
		mdays[2] = leap;  // �������������,����������ֵû�иı�

	}
	for (i = 1; i < month; i++)
	{
		sum += mdays[i];
	}
	sum += day;
	printf("%d", sum);
}