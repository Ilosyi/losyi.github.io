#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>
#include<QTcpServer>
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
    void newClientHandler();
    void onReadMessage();
private:
    Ui::Widget *ui;
    QTcpServer *server;
};
#endif // WIDGET_H
