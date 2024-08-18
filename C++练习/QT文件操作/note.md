1.打开或保存文件

`QString filename= QFileDialog::getOpenFileName(this, tr("文件选取"), "C:", tr("文本文件(*txt)"));`
```c++
/*
*第一个参数 this，指代父窗口为当前组件，并在当前父窗口下弹出一个子框口对话框
*第二个参数tr("文件选取")，用于指定弹出的对话框标题为"文件选取"
*第三个参数"C:"，指定对话框显示时默认打开的目录是C盘
*第四个参数tr("文本文件(*txt)")，指文本过滤器
*/
```
`QString filename=QFileDialog::getSaveFileName(this,"选择一个文件","C:");`

2.消息通知(QMessageBox)
示例:
```c++
if(filename.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
```
[Qt QMessageBox用法详解](https://blog.csdn.net/ccc369639963/article/details/122699085)

3.读文件
 ```c++
 qDebug()<<filename;//打印文件路径
        QFile file(filename);//创建时读入文件名
        file.open(QIODevice::ReadOnly);//打开方式
        QByteArray ba=file.readAll();//读取文件内容
        ui->textEdit->setText(QString(ba));//显示文件内容
        file.close();//关闭文件
```
4.写文件
```c++
  QFile file(filename);//创建时读入文件名
    file.open(QIODevice::WriteOnly);
    //ui->textEdit->toPlainText();
    QByteArray ba;//存储内容
    ba.append(ui->textEdit->toPlainText().toUtf8());//格式转换，将文本存入字节数组
    QMessageBox::information(this,"提示","保存成功");
    file.write(ba);//写入文件
    file.close();
```
[Qt深入浅出（九）QString与QByteArray](https://blog.csdn.net/qq769651718/article/details/79357923)

5.事件系统
示例
```c++
void MainWindow::KeyPressEvent(QKeyEvent* k)
{
    if(k->modifiers()==Qt::ControlModifier&&k->key()==Qt::Key_S)
    {
        MainWindow::saveActionSlot();
        qDebug()<<"Ctrl+S";
    }
}
void MainWindow::mousePressEvent(QMouseEvent *m)
{
    QPoint pt=m->pos();
    if(m->button()==Qt::LeftButton)
    {
        qDebug()<<"左键按下";
    }
    else if(m->button()==Qt::RightButton)
    {
        qDebug()<<"右键按下";
    }
}
```
[QT 学习之键盘事件（ keyPressEvent）](https://blog.csdn.net/yexiangcsdn/article/details/80337491) 
