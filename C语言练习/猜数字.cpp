#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*��������Ϸ*/
int main()
{
	srand(time(0));
	int a = rand();   a = a % 10000;//�������������ȡ4λ��
	int num = 0; int count = 0;//������������count
	while(a!=num) //ѭ����ʼ
	{
		printf("��������µ�ֵ��");
		scanf_s("%d", &num);
		if (num > a)
		{
			printf("�´���\n");
		}
		if (num <a)
		{
			printf("��С��\n");
		}
		count++;
			
	}
	if (a = num)
	{
		printf("��ȷ�𰸾���%d\n", a);
		printf("�����%d��\n", count);
	}

	return 0;
}