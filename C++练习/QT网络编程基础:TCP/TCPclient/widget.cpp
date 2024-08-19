#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket=new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_canceButton_clicked()
{
    this->close();
}


void Widget::on_okButton_clicked()
{
    //获取ip和端口号

    QString ip=ui->lineEdit->text();
    QString port=ui->lineEdit_2->text();
   if(socket->state()==QAbstractSocket::UnconnectedState)
    {
        socket->connectToHost(QHostAddress(ip),port.toShort());
    }
    //连接服务器

    //连接成功，socket对象会发出信号
    connect(socket, &QTcpSocket::connected, this, [this]() // 使用新语法连接信号和槽
            {
                QMessageBox::information(this, "Tip", "Connection is OK");
            });
    //连接异常，也发出信号
    connect(socket,&QTcpSocket::disconnected,this,[this]()
            {
         QMessageBox::warning(this, "Tip", "Connection exception ");
        qDebug()<<"连接异常";
    });

}

