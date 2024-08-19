#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *Socket,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chat)
{
    ui->setupUi(this);
    socket=Socket;
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
}


void chat::on_pushButton_clicked()
{
    QByteArray ba;
    ba=ui->lineEdit->text().toUtf8();
    socket->write(ba);
}

