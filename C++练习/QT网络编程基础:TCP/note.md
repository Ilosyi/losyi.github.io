1.添加库和头文件
进入xxx.pro文档中，在右侧代码界面中的 QT+= core gui 后加上 network。
接着进入widget.h头文件中，添加头文件：`#include <QTcpServer>,#include <QTcpSocket>`，在这之前一定要先添加network模版
2.声明对象，槽函数
在类中添加成员`QTcpSocket *socket;`并在构造函数中`socket=new QTcpSocket;`
3.客户端连接
···c++
void Widget::on_okButton_clicked()
{
    //获取ip和端口号

    QString ip=ui->lineEdit->text();
    QString port=ui->lineEdit_2->text();
    if(!socket->state()==QAbstractSocket::UnconnectedState)
    {
        socket->close();
    }
    //连接服务器
    socket->connectToHost(QHostAddress(ip),port.toShort());
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
···
[QT之TCP网络通信——保姆级教程](https://blog.csdn.net/weixin_74734834/article/details/139690397#:~:text=%E5%9C%A8widget.h%E5%A4%B4%E6%96%87%E4%BB%B6%E4%B8%AD%E6%B7%BB%E5%8A%A0,%23include%20%3CQTcpSocket%3E%E3%80%82)
[Qt网络编程实现TCP通信](https://blog.csdn.net/qq_43686329/article/details/120358274)
