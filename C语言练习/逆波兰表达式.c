#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX_STACK_SIZE 100

// 定义全局变量和函数原型
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    // 将值压入栈
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    }
    else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop() {
    // 从栈中弹出值
    if (top >= 0) {
        return stack[top--];
    }
    else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

int isOperator(char ch) {
    // 检查字符是否是运算符
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluateRPN(char* expression) {
    char* ptr = expression;
    int operand;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            // 如果是数字，将其转换为整数并压入栈
            operand = 0;
            while (isdigit(*ptr)) {
                operand = operand * 10 + (*ptr - '0');
                ptr++;
            }
            push(operand);
        }
        else if (isOperator(*ptr)) {
            // 如果是运算符，弹出栈顶的两个操作数，进行运算，将结果压入栈
            int operand2 = pop();
            int operand1 = pop();

            switch (*ptr) {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            }
            ptr++;
        }
        else {
            // 忽略空格等非数字和运算符的字符
            ptr++;
        }
    }

    // 栈中的最后一个元素即为计算结果
    return pop();
}
int main() {
    char expression[MAX_STACK_SIZE];
    gets_s(expression, MAX_STACK_SIZE);// 逆波兰表达式
    int result = evaluateRPN(expression);

    // 输出计算结果
    printf("Result: %d\n", result);

    return 0;
}
