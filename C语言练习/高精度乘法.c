#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 505
char str1[N], str2[N];
int a[N] = { 0 }, b[N] = { 0 }, c[N] = { 0 };
void cheng(int a[], int b[]);
int len_c;
int main()
{
	int i = 0;
	scanf("%s%s", str1, str2);
	a[0] = strlen(str1);
	b[0] = strlen(str2);
	for (i = 1; i <= a[0]; i++)    
		a[i] = str1[a[0] - i] - '0';
	for (i = 1; i <= b[0]; i++)
		b[i] = str2[b[0] - i] - '0';	
	cheng(a, b);
	for (i = len_c; i >= 2; i--)  
		printf("%d", c[i]);
	printf("\n");
	return 0;
}
void cheng(int a[], int b[])  {  
	for (int i = 1; i <= a[0]; i++) {
		for (int j = 1; j <=b[0]; j++) {
			c[i + j] += a[i] * b[j];
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	}	
	len_c = a[0] + b[0]+3;
	while ((!c[len_c])&&len_c>2) len_c--;
}
