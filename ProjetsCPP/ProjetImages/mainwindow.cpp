#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *Event)
{
    qDebug()<<this->width()<<this->height();
    QPainter painter(this);
    painter.drawLine(0,0,500,500);

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->pos().y()>(this->height()-100))
    {
           qDebug()<<"on est en bas";
       }
    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"un clic droit a été fait.";
    }else{
        qDebug()<<"AUtre qu'un clic droit.";
    }

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    qDebug()<<"Double-clic effectué.";
    if(event->pos().y()<(this->height()-100))
    {
           qDebug()<<"on est en haut";
       }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<event->pos().y()<<"T";
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
if (event->key() == Qt::Key_Escape)
{
this->close();
}
}


