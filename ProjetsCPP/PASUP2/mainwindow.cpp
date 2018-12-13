#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(Bouton1()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(Bouton2()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Bouton1()
{
    QString str;
    str=QString::number(i);
    qDebug()<<"boutin1 str"<<str;
ui->lineEdit->setText(str);
qDebug()<<"boutin1"<<i;
}
//
void MainWindow::Bouton2()
{
i=ui->spinBox->value();
qDebug()<<"boutin2"<<i;
}
