/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *Firstsize;
    QLabel *label_4;
    QLineEdit *Firstoffsize;
    QLabel *label_10;
    QLineEdit *Firstpath;
    QLabel *label_7;
    QLabel *label_11;
    QLineEdit *Secendpath;
    QLineEdit *Secendsize;
    QLineEdit *Secendoffsize;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *firstbutton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Secendbutton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *generateBt_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Firstsize = new QLineEdit(Widget);
        Firstsize->setObjectName("Firstsize");
        Firstsize->setGeometry(QRect(210, 180, 150, 33));
        Firstsize->setMinimumSize(QSize(150, 0));
        Firstsize->setMaximumSize(QSize(120, 16777215));
        QFont font;
        font.setPointSize(15);
        Firstsize->setFont(font);
        Firstsize->setReadOnly(true);
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(64, 129, 39, 33));
        label_4->setFont(font);
        Firstoffsize = new QLineEdit(Widget);
        Firstoffsize->setObjectName("Firstoffsize");
        Firstoffsize->setGeometry(QRect(510, 180, 150, 33));
        Firstoffsize->setMinimumSize(QSize(150, 0));
        Firstoffsize->setMaximumSize(QSize(120, 16777215));
        Firstoffsize->setFont(font);
        label_10 = new QLabel(Widget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(130, 180, 75, 33));
        label_10->setFont(font);
        Firstpath = new QLineEdit(Widget);
        Firstpath->setObjectName("Firstpath");
        Firstpath->setGeometry(QRect(109, 129, 612, 33));
        Firstpath->setMinimumSize(QSize(400, 0));
        Firstpath->setFont(font);
        Firstpath->setFrame(true);
        Firstpath->setReadOnly(true);
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(430, 180, 62, 33));
        label_7->setFont(font);
        label_11 = new QLabel(Widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(70, 230, 81, 33));
        label_11->setFont(font);
        Secendpath = new QLineEdit(Widget);
        Secendpath->setObjectName("Secendpath");
        Secendpath->setGeometry(QRect(140, 230, 609, 33));
        Secendpath->setMinimumSize(QSize(400, 0));
        Secendpath->setFont(font);
        Secendpath->setFrame(true);
        Secendpath->setReadOnly(true);
        Secendsize = new QLineEdit(Widget);
        Secendsize->setObjectName("Secendsize");
        Secendsize->setGeometry(QRect(210, 270, 150, 33));
        Secendsize->setMinimumSize(QSize(150, 0));
        Secendsize->setMaximumSize(QSize(120, 16777215));
        Secendsize->setFont(font);
        Secendsize->setReadOnly(true);
        Secendoffsize = new QLineEdit(Widget);
        Secendoffsize->setObjectName("Secendoffsize");
        Secendoffsize->setGeometry(QRect(510, 270, 150, 33));
        Secendoffsize->setMinimumSize(QSize(150, 0));
        Secendoffsize->setMaximumSize(QSize(120, 16777215));
        Secendoffsize->setFont(font);
        label_12 = new QLabel(Widget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(130, 270, 75, 33));
        label_12->setFont(font);
        label_13 = new QLabel(Widget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(430, 270, 62, 33));
        label_13->setFont(font);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 370, 671, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        firstbutton = new QPushButton(widget);
        firstbutton->setObjectName("firstbutton");
        firstbutton->setMinimumSize(QSize(100, 0));
        firstbutton->setFont(font);

        horizontalLayout->addWidget(firstbutton);

        horizontalSpacer_8 = new QSpacerItem(58, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        Secendbutton = new QPushButton(widget);
        Secendbutton->setObjectName("Secendbutton");
        Secendbutton->setMinimumSize(QSize(100, 0));
        Secendbutton->setFont(font);

        horizontalLayout->addWidget(Secendbutton);

        horizontalSpacer_7 = new QSpacerItem(58, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        generateBt_2 = new QPushButton(widget);
        generateBt_2->setObjectName("generateBt_2");
        generateBt_2->setMinimumSize(QSize(100, 0));
        generateBt_2->setFont(font);

        horizontalLayout->addWidget(generateBt_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Firstsize->setText(QString());
        label_4->setText(QCoreApplication::translate("Widget", "First", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "size", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "offsize", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "Secend", nullptr));
        Secendsize->setText(QString());
        label_12->setText(QCoreApplication::translate("Widget", "size", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "offsize", nullptr));
        firstbutton->setText(QCoreApplication::translate("Widget", "First", nullptr));
        Secendbutton->setText(QCoreApplication::translate("Widget", "Secend", nullptr));
        generateBt_2->setText(QCoreApplication::translate("Widget", "generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
