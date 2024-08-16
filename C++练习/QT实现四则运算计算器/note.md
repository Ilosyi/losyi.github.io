1.显示QString
`ui->mainlineEdit->setText(expression)`

2.用于设置窗口标题
`this->setWindowTitle("计算器")`

 3.用于在控件上显示图片
```c++
    QIcon con("C:\\Users\\muke\\Pictures\\Screenshots\\back.png");
    ui->delButton->setIcon(con);
 ```

4.删除结尾x个字符
`expression.chop(x);(expression为QString类型)`

5.计算器逻辑部分（栈）
```c++
#include<iostream>
#include<algorithm>
#include<stack>
#include <sstream>
#include <cctype>
using namespace std;

int precedence(char op);
double applyOperation(double a, double b, char op);
double evaluateExpression(const string& expression);

// 主函数
int main() {
    string expression;
    cout << "请输入一个数学表达式（如3 + 5 * (2 - 4) / 2）：";
    getline(cin, expression);

    try {
        double result = evaluateExpression(expression);
        cout << "结果: " << result << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}

// 返回操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 应用操作符到两个操作数上
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b != 0) return a / b;
        else throw "错误: 除零异常";
    }
    return 0;
}

// 计算表达式的值
double evaluateExpression(const string& exp) {
    stack<double> values; // 值栈
    stack<char> ops; // 操作符栈

    int i = 0;
    while (i < exp.length()) {
        // 跳过空格
        if (isspace(exp[i])) {
            i++;
            continue;
        }

        // 处理数字
        if (isdigit(exp[i])) {
            double value = 0;
            while (i < exp.length() && (isdigit(exp[i]) || exp[i] == '.')) {
                if (exp[i] == '.') {
                    double frac = 1.0;
                    i++;
                    while (i < exp.length() && isdigit(exp[i])) {
                        frac /= 10.0;
                        value += (exp[i] - '0') * frac;
                        i++;
                    }
                }
                else {
                    value = (value * 10) + (exp[i] - '0');
                    i++;
                }
            }
            values.push(value);
        }
        // 处理左括号
        else if (exp[i] == '(') {
            ops.push(exp[i]);
            i++;
        }
        // 处理右括号
        else if (exp[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double value2 = values.top();
                values.pop();

                double value1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(value1, value2, op));
            }
            ops.pop(); // 弹出左括号
            i++;
        }
        // 处理操作符
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(exp[i])) {
                double value2 = values.top();
                values.pop();

                double value1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(value1, value2, op));
            }
            ops.push(exp[i]);
            i++;
        }
    }
    // 完成剩余的操作
    while (!ops.empty()) {
        double value2 = values.top();
        values.pop();

        double value1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOperation(value1, value2, op));
    }
    // 返回结果
    return values.top();
}
 ```
