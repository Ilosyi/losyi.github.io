//����һ���ַ���s��ͳ���ַ����ĳ��ȣ������ַ�����ת�����
#include<stdio.h>
int strlength(char s[])
{
	int i = 0;
	while (s[i++]);    //��whileѭ���У�s[i++]��ʾ�����ַ���������Ϊi���ַ�������i��ֵ������
	                      /*whileѭ��������������s[i++]�����ж�����Ϊi���ַ��Ƿ�Ϊ������\0��   
                          ������ǽ������������ִ��ѭ����*/
	return i-1;//ĩβ0��������
}
void strreverse(char s[])
{
	int i, j;
	for (i = 0, j = strlength(s)-1; i < j; i++,j--)//��Ҫ�����ģ����ߴ��.���򱨴�
	{//j=strlen(s)-1������strlen(s),ĩβ0���ؽ���
		
		char t;
		t = s[i];
		s[i] = s[j];
		s[j] = t;

	}
}
int main() 

{   
	char s[1000];
	int strlength(char s[]);
	void strreverse(char s[]);
	printf("������һ���ַ���\n");
	scanf_s("%s", s,1000);//����ϳ��ȣ����򱨴�C4473û��Ϊ�ַ��������㹻�Ĳ���
	printf("�ַ���%s�ĳ���Ϊ��%d\n", s, strlength(s));
	strreverse(s);
	printf("��ת��Ϊ%s",s);
	return 0;
}