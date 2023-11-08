#include <stdio.h>

int main() {
    int rows, coef = 1, space, i, j;

    printf("请输入杨辉三角的行数：");
    scanf_s("%d", &rows);

    for (i = 0; i < rows; i++) {
        for (space = 1; space <= rows - i; space++) {
            printf("  "); // 打印空格，用于对齐数字
        }

        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1; // 边界数字为1
            }
            else {
                coef = coef * (i - j + 1) / j; // 计算当前位置的数字
            }

            printf("%4d", coef); // 打印数字
        }

        printf("\n");
    }

    return 0;
}
