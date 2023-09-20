#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QDataStream>      //二进制文件读写

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}





void Widget::on_generateBt_2_clicked()
{

    QString path = QFileDialog::getSaveFileName(this,tr("Open File"),".", tr("Bin Files(*.bin)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this, tr("Write File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QFile readfile;    //要读取的bin文件
        QFileInfo read_file_info;         //要读取的bin文件的信息
        QByteArray DataAllArray;

        int offsize;    //获取偏移量
        int fillsize;   //填充数据的长度
        bool status;

        offsize = ui->Firstoffsize->text().toInt(&status,16); // 表示以16进制方式读取字符串
        fillsize = offsize;
        qDebug("app offsize = %d", offsize);
        char *pnouseBuff = new char[fillsize];    //和上面一样，直接分配一个大的定长缓存，以便两次填充无用数据时复用。
        memset(pnouseBuff, 0, fillsize);
            //注意此处不能使用sizeof（pnouseBuff）,pnouseBuff是一个指针，sizeof为4
        qDebug() << "the size of iap end to app start is " << fillsize;
        DataAllArray = QByteArray(pnouseBuff, fillsize);
        file.write(DataAllArray);
        delete[] pnouseBuff;

        readfile.setFileName(ui->Firstpath->text());    //要读取的bin文件
        read_file_info.setFile(readfile);         //要读取的bin文件的信息
        if (!readfile.open(QIODevice::ReadOnly)) {  //只读方式打开bin文件
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(ui->Firstpath->text()));
            return;
        }
        QDataStream BinFileData(&readfile);
        char *pBuff = new char[read_file_info.size()];  //要读取bin文件的大小
        BinFileData.readRawData(pBuff,static_cast<int>(read_file_info.size()));
        qDebug("0x%x 0x%x",*pBuff,*(pBuff + 1));
        qDebug() << "First.bin size is " << static_cast<int>(read_file_info.size());    //打印文件长度
        DataAllArray = QByteArray(pBuff,static_cast<int>(read_file_info.size()));
        file.write(DataAllArray);
        readfile.close();
        delete[] pBuff;

        //Secend
        offsize = ui->Secendoffsize->text().toInt(&status,16); // 表示以16进制方式读取字符串
        fillsize = offsize - (read_file_info.size() + ui->Firstoffsize->text().toInt(&status,16));
        qDebug("app offsize = %d", offsize);
        char *pnouseBuff1 = new char[fillsize];    //和上面一样，直接分配一个大的定长缓存，以便两次填充无用数据时复用。
        memset(pnouseBuff1, 0, fillsize);
            //注意此处不能使用sizeof（pnouseBuff）,pnouseBuff是一个指针，sizeof为4
        qDebug() << "the size of iap end to app start is " << fillsize;
        DataAllArray = QByteArray(pnouseBuff1, fillsize);
        file.write(DataAllArray);
        delete[] pnouseBuff1;

        readfile.setFileName(ui->Secendpath->text());    //要读取的bin文件
        read_file_info.setFile(readfile);         //要读取的bin文件的信息
        if (!readfile.open(QIODevice::ReadOnly)) {  //只读方式打开bin文件
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(ui->Secendpath->text()));
            return;
        }
        QDataStream BinFileData1(&readfile);
        char *pBuff1 = new char[read_file_info.size()];  //要读取bin文件的大小
        BinFileData.readRawData(pBuff1,static_cast<int>(read_file_info.size()));
        qDebug("0x%x 0x%x",*pBuff1,*(pBuff1 + 1));
        qDebug() << "Secend.bin size is " << static_cast<int>(read_file_info.size());    //打印文件长度
        DataAllArray = QByteArray(pBuff1,static_cast<int>(read_file_info.size()));
        file.write(DataAllArray);
        readfile.close();
        delete[] pBuff1;

        file.close();
        QMessageBox::information(this,"提示","成功");
    }
    else
    {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }


}


void Widget::on_firstbutton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),//控件的objectName
                                                ".",           //对话框显示时默认打开的目录，"." 代表程序运行目录
                                                tr("Text Files(*.bin)"));   //对话框的后缀名过滤器，将txt文件改为bin文件。
    if(!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QString buf;
        QFileInfo info(file);

        buf = QString(info.absolutePath());
        buf.append("/");
        buf.append(info.baseName());    //直接获得文件名
        buf.append(".bin");
        qDebug("%s",qPrintable(buf));

        ui->Firstpath->setText(buf);
        //ui->appsizeEdit->setText(QString::number(info.size(),16));
        QString appsize = QString("0x%1").arg(info.size(), 8, 16, QLatin1Char('0'));
        appsize = appsize.toUpper();
        ui->Firstsize->setText(appsize);
        ui->Firstoffsize->setText(tr("0x00001080"));  //默认偏移量
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}


void Widget::on_Secendbutton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),//控件的objectName
                                                ".",           //对话框显示时默认打开的目录，"." 代表程序运行目录
                                                tr("Text Files(*.bin)"));   //对话框的后缀名过滤器，将txt文件改为bin文件。
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QString buf;
        QFileInfo info(file);

        buf = QString(info.absolutePath());
        buf.append("/");
        buf.append(info.baseName());    //直接获得文件名
        buf.append(".bin");
        qDebug("%s",qPrintable(buf));

        ui->Secendpath->setText(buf);

        QString appsize = QString("0x%1").arg(info.size(), 8, 16, QLatin1Char('0'));
        appsize = appsize.toUpper();
        ui->Secendsize->setText(appsize);
        ui->Secendoffsize->setText(tr("0x01B685DC"));  //默认偏移量
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}

