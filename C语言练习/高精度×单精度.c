#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define PI 3.1415
//从大数开始向前，依次分配1,
int a[100];
int b[1000];
void cheng(int x)
{
	int carry = 0;
	for (int i = 0; i < log10(sqrt(2 * PI * x)) + x * log10(x / 2.71828) + 10; i++)
	{
		int temp = b[i] * x + carry;
		b[i] = temp % 10;
		carry = temp / 10;
	}
}
void print(int x)
{
	int leng = log10(sqrt(2 * PI * x)) + x * log10(x / 2.71828) + 10;
	while (!b[leng]) leng--;
	printf("\n");
	for (int i = leng; i >= 0; i--)
	{
		printf("%d", b[i]);
	}
}
int main()
{
	b[0] = 1;
	int n;
	scanf("%d", &n);
	int sum = 0;
	int j = 0;
	int yu=0;
	int last;
	for (int i = 2; i < n; i++)
	{
		a[j] = i;
		sum += i;
		last = i;
		if (sum > n) {
			 yu = sum - n;
			 if (yu == 1) { a[j]++; }
			break;
		}
		j++;
	}

	if (yu == 1) {
		for (int i = 1; a[i] != 0; i++)
		{
			printf("%d ", a[i]);
			cheng(a[i]);
		}
	}
	else {
		for (int i = 0; a[i] != 0; i++)
		{
			if (i != yu - 2)
			{
				printf("%d ", a[i]);
				cheng(a[i]);
			}
		}
	}
	print(last);
	return 0;
}
