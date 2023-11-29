#include<stdio.h>
#include<string.h>
#define N 505
void jia(int a[],int b[]);
int main()
{
    char str1[N],str2[N];
	int a[N]={0},b[N]={0};
	int i=0;
	scanf("%s%s",str1,str2);
	a[0]=strlen(str1);
	b[0]=strlen(str2);
 
	for(i=1;i<=a[0];i++)    //分别将字符串1，2逆序存储在整型数组中
		a[i]=str1[a[0]-i]-'0';
    for(i=1;i<=b[0];i++)
        b[i]=str2[b[0]-i]-'0';
    jia(a,b);
 
	for(i=a[0];i>=1;i--)    //逆序输出a，其中存储的是两数之和
      printf("%d",a[i]);
	printf("\n");
    return 0;
}
 
void jia(int a[],int b[])    //两数相加，再判断有没有进位（用一个循环）
{
	int i=0;
	if(a[0]<b[0]) a[0]=b[0];
    for(i=1;i<=a[0];i++)    //两数和存储在a中
	{
	   a[i]+=b[i];
	   if(a[i]>=10)    //要有等号
	   {
		 a[i+1]+=a[i]/10;
         a[i]=a[i]%10;
	   }
	}   
	while(a[a[0]+1]) a[0]++;
}
