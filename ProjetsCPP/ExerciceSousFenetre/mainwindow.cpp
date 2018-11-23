#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->action_propos,SIGNAL(triggered()),this,SLOT(AfficherAPropos()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::setnomprogramme(char * np)
{
    nomprogramme=np;
    return 0;
}

int MainWindow::AfficherAPropos()
{
qDebug()<<"on passe bien ici"<<nomprogramme;
Dialog sousfenetre(this);
sousfenetre.show();
sousfenetre.modifierlabel(nomprogramme);
return sousfenetre.exec();
}
