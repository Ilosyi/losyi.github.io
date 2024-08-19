#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include<QHostAddress>//ip地址
#include<QMessageBox>
#include<chat.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_canceButton_clicked();

    void on_okButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};
#endif // WIDGET_H
