#include <stdio.h>
/*ˮ�ɻ���*/
int main()
{
	int n;                              //λ��n
	printf("������n��ֵ:");
	scanf_s("%d", &n);
	int first = 1; int i = 1;           //����firstȷ��i�ķ�Χ
	for (first = 1; first < n; first++)
	{
		i *= 10;
	}
	first = i;
	for (i = first; i < first * 10; i++) //��һ��ѭ��������i-i*10
	{
		int t = i;           //�м����t
		int sum = 0;         //sumΪ��λ���ֵĴη���
		while (t > 0)        //�ڶ���Ѫѭ���Դ�ȡ����λ����
		{
			int d = t % 10; int p = d; int j = 1;    //�����м����p���м���n�η�
			t /= 10;           //Ҳ������<math.h>�е�pow��������   pow��������ָ����
			do {                          //����j�͵�����ѭ������n�η���p��ֵ��
				p *= d;
				j++;
			} while (j < n);
			sum += p;                //���������ڶ���ѭ���У�

		}
		if (i == sum)
		{
			printf("%d\n", i);     //���
		}
	}     //��һ��ѭ������
	return 0;
}
