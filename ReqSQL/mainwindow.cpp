#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase mabase =QSqlDatabase::addDatabase("QSQLITE");
    db =&mabase;
    db->setDatabaseName("/home/ajc184/Projets/BDD/BDDCommunes.db");
    bool ok = db->open();

    if(ok){
        qDebug()<<"ok est vrai";
    }else {
        qDebug()<<"ok est faux";
    }
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ExecuterReq()));
    Ville = new QString();
    Departement = new QString();
    ChefLieu = new QString();
    CP = new QString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ExecuterReq()
{
    *Ville = "";
    *Departement = "";
    *ChefLieu = "";
    *CP = "N/A";

        qDebug()<<"Ok";
                qDebug()<<"Ville vaut :"<<*Ville;
                        qDebug()<<"O2";
    QSqlQuery query("SELECT NCCENR, DEP, CHEFLIEU, NCCCT FROM france2016 where NCCENR like \""+ui->lineEdit_10->text()+"\"");

while (query.next()) {

        qDebug()<<"O3";
    *Ville = query.value(0).toString();
    *Departement = query.value(1).toString();
    *ChefLieu = query.value(3).toString();
    *CP = "N/A";
}
    qDebug()<<"O4";
    qDebug()<<"Ville vaut :"<<*CP;
    ui->lineEdit_2->setText(*Ville);
    ui->lineEdit_4->setText(*CP);
    ui->lineEdit_6->setText(*ChefLieu);
    ui->lineEdit_8->setText(*Departement);

}
