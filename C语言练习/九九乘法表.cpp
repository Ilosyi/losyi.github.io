#include<stdio.h>
//�žų˷���
int main() {
    //���ѭ������,������ 
    int i = 0;
    //�ڲ�ѭ������,������  
    int j = 0;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            printf("%dx%d=%d\t", j, i, i * j);
        }
        //ÿ����������  
        printf("\n");
    }
    return 0;
}