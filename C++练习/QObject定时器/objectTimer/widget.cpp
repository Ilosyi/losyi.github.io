#include "widget.h"
#include "ui_widget.h"
#define TIMEOUT 1000

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("自动播放图片");
    picID=2;
    QPixmap pix(QString::fromLocal8Bit(":/picture/1.jpg"));
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    myTimerID=this->startTimer(TIMEOUT);//开始定时器,返回值为定时器编号


}
void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()!=myTimerID)
        return;

    QString path(QString::fromLocal8Bit(":/picture/"));
    path+=QString::number(picID);
    path+=".jpg";
    QPixmap pix(path);
    ui->label->setPixmap(pix);
    picID++;
    if(picID==7)  picID=1;

}


void Widget::on_pushButton_2_clicked()
{
    this->killTimer(myTimerID);
}

