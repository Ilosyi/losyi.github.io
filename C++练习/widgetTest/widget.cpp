#include "widget.h"
#include "ui_widget.h"
#include<string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接信号与槽   谁发出信号 发出什么信号 谁接受信号 怎么处理
    //设置窗口标题
    this->setWindowTitle("计算器");
    //设置按钮图片
    QIcon con("C:\\Users\\muke\\Pictures\\Screenshots\\back.png");
    ui->delButton->setIcon(con);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_oneButton_clicked()
{
    //字符串
    expression+="1";
    //设置line显示
    ui->mainlineEdit->setText(expression);
}
void Widget::on_twoButton_clicked()
{
    expression+="2";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_threeButton_clicked()
{
    expression+="3";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_fourButton_clicked()
{
    expression+="4";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_fiveButton_clicked()
{
    expression+="5";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_sixButton_clicked()
{
    expression+="6";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_sevenButton_clicked()
{
    expression+="7";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_eightButton_clicked()
{
    expression+="8";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_nineButton_clicked()
{
    expression+="9";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_plusButton_clicked()
{
    expression+="+";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_subButton_clicked()
{
    expression+="-";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_mulButton_clicked()
{
    expression+="*";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_divButton_clicked()
{
    expression+="/";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_leftButton_clicked()
{
    expression+="(";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_rightButton_clicked()
{
    expression+=")";
    ui->mainlineEdit->setText(expression);
}
void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainlineEdit->clear();
}
void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainlineEdit->setText(expression);
}

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

void Widget::on_resultButton_clicked()
{
    QStack<double> values; // 值栈
    QStack<char> ops; // 操作符栈

    std::string exp = expression.toStdString();
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

    QString resultexp;
    resultexp= QString::number(values.top(),10,5);
    ui->mainlineEdit->setText(resultexp);

}


void Widget::on_threeButton_2_clicked()
{
    expression+=".";
    ui->mainlineEdit->setText(expression);
}

