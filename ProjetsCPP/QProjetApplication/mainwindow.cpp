#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(traitementLineEdit()));




}

void MainWindow::traitementLineEdit()
{
    ui->lineEdit->setDisabled((true));

    QString str;
    str=ui->lineEdit->text();
    str=str.toUpper();
    qDebug()<<"Le texte récupéré est :"<<str;
}




MainWindow::~MainWindow()
{
    delete ui;
}


