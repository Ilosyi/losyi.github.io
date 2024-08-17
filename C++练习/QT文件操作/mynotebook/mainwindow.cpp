#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("myNoteBook");
    connect(ui->action_N,SIGNAL(triggered(bool)),this,SLOT(newActionSlot()));
    connect(ui->action_O,SIGNAL(triggered(bool)),this,SLOT(openActionSlot()));
    connect(ui->action_S,SIGNAL(triggered(bool)),this,SLOT(saveActionSlot()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档");
}
void MainWindow:: openActionSlot()
{
   QString filename= QFileDialog::getOpenFileName(this, tr("文件选取"), "C:", tr("文本文件(*txt)"));
    if(filename.isEmpty())
   {
       QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        qDebug()<<filename;//打印文件路径
        QFile file(filename);//创建时读入文件名
        file.open(QIODevice::ReadOnly);//打开方式
        QByteArray ba=file.readAll();//读取文件内容
        ui->textEdit->setText(QString(ba));//显示文件内容
        file.close();//关闭文件
    }
}
void MainWindow:: saveActionSlot()
{
    QString filename=QFileDialog::getSaveFileName(this,"选择一个文件","C:");
    if(filename.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    QFile file(filename);//创建时读入文件名
    file.open(QIODevice::WriteOnly);
    //ui->textEdit->toPlainText();
    QByteArray ba;//存储内容
    ba.append(ui->textEdit->toPlainText().toUtf8());//格式转换，将文本存入字节数组
    QMessageBox::information(this,"提示","保存成功");
    file.write(ba);//写入文件
    file.close();

}
