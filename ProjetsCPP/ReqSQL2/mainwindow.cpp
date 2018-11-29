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

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("france2016");
    model->setFilter("NCC like 'VILLARS%'");
    model->select();
    ui->tableView->setModel(model);
    connect(ui->tableView,SIGNAL(clicked(QModelIndex)),this, SLOT(Troulalaitou(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//afficheInfo
void MainWindow::Troulalaitou(QModelIndex ind)
{
    QString val;
    val=ind.data().toString();
    ui->lineEdit->setText(val);
    qDebug()<<val;
    qDebug()<<(ind.sibling(ind.row()+1,ind.column())).data().toString();
    qDebug()<<ind.siblingAtColumn(4);
    qDebug()<<ind.row();
    qDebug()<<ind.column();

}
