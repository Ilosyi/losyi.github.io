#include <stdio.h>
int main() {
    int num, mask, i;
    printf("请输入整数：");
    scanf_s("%d", &num);
    mask = 1 << 15;
    printf("%d=", num);
    for (i = 1; i < 17; i++)
    {
        putchar(num & mask ? '1' : '0');
        num =num<< 1;
        if (i % 4 == 0)
            putchar(',');
    }
    printf("\bB\n");
    return 0;
}
