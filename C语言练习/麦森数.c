#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
//计算2^1297-1的最后五百位
long long a[1000];

int main()
{
    int P;
    scanf("%d", &P); 
    printf("%d\n", (int)(P * log10(2)) + 1);
    long long tmp = pow(2,32);      
    a[0] = 1;
    int t = P / 32;                 
    int tm = P %32;              
    for (int j = 1; j <= t; j++)
    {
        long long carry = 0;
        for (int i = 0; i <= 500; i++)
        {
           long long temp = a[i] * tmp + carry;
            a[i] = temp % 10;
            carry = temp / 10;
        }
    }
    for (int j = 1; j <= tm; j++)
    {
        int carry = 0;
        for (int i = 0; i <= 500; i++)
        {
            int temp = a[i] * 2 + carry;
            a[i] = temp % 10;
            carry = temp / 10;
        }
    }
    a[0]--;
    int q = 0;
    for (int i = 499; i>=0; i--)
    {
        printf("%lld",a[i]);
        q++;
        if (q% 50 == 0) printf("\n");
    }
    return 0;
}
