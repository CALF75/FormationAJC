#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList namewordList;
    namewordList << "Dupont" << "Dupond" << "Maire" << "Marillier"<<"Tartenpion";
    //QCompleter *namecompleter = new QCompleter(namewordList, this);
    namecompleter = new QCompleter(namewordList, this);
    namecompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(namecompleter);


    QStringList forenamewordList;
    forenamewordList << "Jacques" << "Jean" << "Gilles" << "Charles-Alexandre"<<"Xavier";
    forenamecompleter = new QCompleter(forenamewordList, this);
    forenamecompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_2->setCompleter(forenamecompleter);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete namecompleter;
    delete forenamecompleter;

}
