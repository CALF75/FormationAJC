#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QDateEdit>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(traitementDate()));
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(traitementDate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::traitementDate()
{




    DateASaisir=ui->dateEdit->date();
    DateASaisir=DateASaisir.addDays(ui->spinBox->value());
    ui->label_3->setText(DateASaisir.toString("Le d MMMM yyyy"));
    qDebug()<<"La date est :"<<DateASaisir;


}
