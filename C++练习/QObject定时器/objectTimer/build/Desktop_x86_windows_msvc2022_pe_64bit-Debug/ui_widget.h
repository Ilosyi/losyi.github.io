/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(615, 319);
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(700, 600));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(150, 270, 71, 21));
        pushButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pushButton->setCheckable(false);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 270, 71, 21));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 20, 394, 216));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(394, 216));
        label->setScaledContents(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("Widget", "label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
