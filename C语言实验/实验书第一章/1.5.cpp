#include <stdio.h>
int main()
{
	int count=0,max=0, x, t;
	scanf_s("%d",&x);//��Ҫ©��%�����򱨴�C6271���ݸ�scanf����Ĳ�����C4474��ʽ�ַ������ݵĲ���̫��
	while(x>0)
	{
		t = x % 10;
		if (t == 0)//��Ҫ��ֺţ����򱨴�C4390�ҵ��յ��ܿ�������0�ĸ����������
		{
			count++; 
		}
		if (t > max)
		{
			max = t;
		}
			x /= 10;
	}
	printf("�������%d��0����������%d", count, max);
	return 0;
}