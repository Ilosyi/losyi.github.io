#include <stdio.h>
#include <stdlib.h>
void convertAndPrint(char* hexadecimal, int Base) {
    long int d;
    if (sscanf_s(hexadecimal, "%lx", &d) == 1)//转换为10进制数字
    {
        printf("输出(%d进制): ",Base);
        if (Base == 10) {
            printf("%ld\n", d);
        }
        else if (Base >= 2 && Base <= 12) {
            long int quo = d;
            int i = 0;
            char result[100];

            while (quo > 0) 
            {                                      //反复相除
                int r = quo % Base;
                result[i] = (r < 10) ? ('0' + r)
                    : ('A' + r - 10);
                i++;
                quo /= Base;
            }
            for (int j = i - 1; j >= 0; j--) //打印结果
            {
                printf("%c", result[j]);
            }
            printf("\n");
        }
    }
    else {
        printf("输入错误\n");
    }
}

int main() {
    char input[20];
    int Base;

    printf("输入(16进制)：");
    if (scanf_s("%19s", input, sizeof(input)) != 1) {
        printf("输入错误\n");
        return 1;
    }
    char input2[30];//删除空格后的字符串
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ')
        {
            input2[i] = input[i];
        }
        else
        {
            i--;
        }
    }

    printf("输入目标进制（2-12）：");
    if (scanf_s("%d", &Base) != 1 || Base < 2 || Base > 12) {
        printf("目标进制不在范围内\n");
        return 1;
    }

    convertAndPrint(input, Base);

    return 0;
}
