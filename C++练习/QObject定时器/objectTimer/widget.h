#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimerEvent>
#include <QLabel>

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
    virtual void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    int myTimerID;
    int picID;
};
#endif // WIDGET_H
