//输入一个字符串s，统计字符串的长度，并将字符串反转后输出
#include<stdio.h>
int strlength(char s[])
{
	int i = 0;
	while (s[i++]);    //在while循环中，s[i++]表示访问字符串中索引为i的字符，并将i的值递增。
	                      /*while循环的条件部分是s[i++]，即判断索引为i的字符是否为结束符\0。   
                          如果不是结束符，则继续执行循环。*/
	return i-1;//末尾0不必算入
}
void strreverse(char s[])
{
	int i, j;
	for (i = 0, j = strlength(s)-1; i < j; i++,j--)//不要用中文，或者打成.否则报错
	{//j=strlen(s)-1而不是strlen(s),末尾0不必交换
		
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
	printf("请输入一个字符串\n");
	scanf_s("%s", s,1000);//需加上长度，否则报错C4473没有为字符串传递足够的参数
	printf("字符串%s的长度为：%d\n", s, strlength(s));
	strreverse(s);
	printf("反转后为%s",s);
	return 0;
}