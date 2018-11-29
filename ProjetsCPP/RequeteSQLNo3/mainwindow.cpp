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
      connect(ui->pushButton,SIGNAL(clicked(bool)),this, SLOT(AfficherResultat()));
      ui->pushButton->clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AfficherResultat()
{
    qDebug()<<"On rentre dans la méthode.";
    QString dep;
    dep.clear();

    QString req;
    dep = ui->lineEdit->text();
    if(!dep.isEmpty()){
        req="select *from france2016 where DEP=\""+dep+"\"";
        qDebug()<<"UN";
    }else{
        req="select *from france2016";
        qDebug()<<"DEUX";
    }
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(req);
    ui->tableView->setModel(model);


}


