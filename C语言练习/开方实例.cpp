#include<stdio.h>
#include<math.h>
int main()
/*һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�*/
{
    int x = -99;
    float i, j;
    for (x = -99; x < 17956; x++)
    {
        i = sqrt(x + 100), j = sqrt(x + 268);//(int)x��ʾת��Ϊ���ͣ���ȥС����
        if (((int)i == i) && ((int)j == j))
            printf("%d ", x);
    }
    return 0;
}