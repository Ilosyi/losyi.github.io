//����һ�����ģ�ͳ���ַ���������
#include <stdio.h>
int main()
{
	char c = 0;
	int numchar = 0, numline = 0;
	printf("�����������ı�����������Ctrl+z������\n");
	while ((c = getchar()) != EOF)//ע������
	{
		numchar++;
		if (c == '\n')
			numline++;
	}
	printf("�ַ�����%d\n", numchar);
	printf("������%d\n", numline);

	return 0;
}
