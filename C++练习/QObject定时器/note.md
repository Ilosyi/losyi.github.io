1.开始定时器,返回值为定时器编号
`myTimerID=this->startTimer(TIMEOUT);`

2.关闭定时器
`this->killTimer(myTimerID);`

3.在标签上显示图片
 ```c++
  QPixmap pix(QString::fromLocal8Bit("E:\\picture\\1.jpg"));
    ui->label->setPixmap(pix);
```

4.将int转化为QString
`QString::number(picID)`

5.虚函数，定时任务
```c++
void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()!=myTimerID)
        return;
    QString path(QString::fromLocal8Bit("E:\\picture\\"));
    path+=QString::number(picID);
    path+=".jpg";
    QPixmap pix(path);
    ui->label->setPixmap(pix);
    picID++;
    if(picID==7)  picID=1;

}
```
