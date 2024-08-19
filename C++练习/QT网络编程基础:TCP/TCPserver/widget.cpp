#include "widget.h"
#include "ui_widget.h"
#define PORT 8000
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,PORT);
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);


}

Widget::~Widget()
{
    delete ui;
}
void Widget::newClientHandler()
{
    //建立TCP连接
    QTcpSocket *socket=server->nextPendingConnection();
    //socket->peerAddress();//获取客户端地址
   // socket->peerPort();//获取客户端端口号

    ui->lineEdit->setText(socket->peerAddress().toString());
    ui->lineEdit_2->setText(QString::number(socket->peerPort()));
}
