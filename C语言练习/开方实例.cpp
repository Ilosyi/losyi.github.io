#include<stdio.h>
#include<math.h>
int main()
/*一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？*/
{
    int x = -99;
    float i, j;
    for (x = -99; x < 17956; x++)
    {
        i = sqrt(x + 100), j = sqrt(x + 268);//(int)x表示转化为整型，舍去小数点
        if (((int)i == i) && ((int)j == j))
            printf("%d ", x);
    }
    return 0;
}