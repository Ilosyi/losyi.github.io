//下面是使用迭代方式实现斐波那契数列的C语言代码：
#include <stdio.h>

void fibonacci(int num) {
    long long a = 0, b = 1, c, i;

    printf("斐波那契数列：\n%ll %ll ", a, b);

    for (i = 2; i < num; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main() {
    int num;

    printf("请输入要列出的斐波那契数列的项数：");
    scanf_s("%d", &num);

    if (num<= 0) {
        printf("请输入大于0的项数。\n");
        return 0;
    }

    fibonacci(num);

    return 0;
}

/*在上述代码中，我们使用了两个变量 a 和 b 来迭代计算斐波那契数列的下一个数字。使用循环，从第三项开始，通过更新 a 和 b 的值来计算并打印出每个数字。在每次迭代中，我们将 b 的值赋给 a，并将 c 的值赋给 b，其中 c = a + b。循环的次数由用户输入的 num 决定。
这种迭代方法更高效，并且不会有递归调用的开销，当计算较大的斐波那契数列时会更快。*/