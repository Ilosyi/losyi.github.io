#include<stdio.h>
//九九乘法表
int main() {
    //外层循环变量,控制行 
    int i = 0;
    //内层循环变量,控制列  
    int j = 0;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            printf("%dx%d=%d\t", j, i, i * j);
        }
        //每行输出完后换行  
        printf("\n");
    }
    return 0;
}