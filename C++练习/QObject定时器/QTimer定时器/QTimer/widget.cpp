#include "widget.h"
#include "ui_widget.h"
#define TIMEOUT 1000
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer;
    picID=2;

    QImage img;//创建加载img对象
    img.load("E:\\picture\\1.jpg");
    ui->label->setPixmap(QPixmap::fromImage(img));//从img获取资源来显示

    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    timer->start(TIMEOUT);
}
void Widget::timeoutSlot()
{
    QString path(QString::fromLocal8Bit("E:\\picture\\"));
    path+=QString::number(picID);
    path+=".jpg";
    QImage img;//创建加载img对象
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
    picID++;
    if(picID==7)
    {
        picID=1;
    }
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
}


void Widget::on_pushButton_3_clicked()
{
    QTimer::singleShot(1000,this,SLOT(timeoutSlot()));
}

