#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuitter,SIGNAL(triggered()), this,SLOT(close()));
    connect(ui->actionOuvrir,SIGNAL(triggered()),this,SLOT(OuvrirFichier()));
    connect(ui->action_propos,SIGNAL(triggered()),this,SLOT(OuvrirAPropos()));
    connect(ui->actionSauvegarder,SIGNAL(triggered()),this,SLOT(SauvegarderFichier()));
    fenetreapropos = new APropos(this);
    connect(ui->actionPolice,SIGNAL(triggered()),this,SLOT(OuvrirPoliceDialog()));
    fenetrepolice = new PoliceDIalog(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::OuvrirAPropos()
{
    fenetreapropos->show();
    fenetreapropos->exec();
    qDebug()<<"test";
    return 0;
}

void MainWindow::OuvrirPoliceDialog()
{
fenetrepolice->show();
fenetrepolice->exec();
    qDebug()<<"test2";
}

void MainWindow::OuvrirFichier()
{
    fileName = QFileDialog::getOpenFileName(this,QString("Ouvrir un fichier"), QDir::homePath(),"Image Files (*.*)");
    fichierouvert = new QFile(fileName);
    qDebug()<<"filename = "<<fileName;

    fichierouvert->open(QIODevice::ReadWrite);
    QString textfichier;
    textfichier=(QString) fichierouvert->readAll();
    ui->textEdit->setPlainText(textfichier);
    fichierouvert->close();
}

void MainWindow::SauvegarderFichier()
{
    if (!fileName.isEmpty()){
        QString textfichier ;
        textfichier= ui->textEdit->toPlainText();
        fichierouvert->open(QIODevice::WriteOnly);

        QTextStream out(fichierouvert);
        out << textfichier;

        fichierouvert->close();}
    else{
           qDebug()<<"Il n'y a pas de fichier chargé";

          fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::homePath(),tr("Images (*.*)"));
          if (!fileName.isEmpty()){
            qDebug()<<"fileName : "<<fileName;
             fichierouvert = new QFile(fileName);
             QString textfichier ;
             textfichier= ui->textEdit->toPlainText();
             fichierouvert->open(QIODevice::WriteOnly);

             QTextStream out(fichierouvert);
             out << textfichier;

             fichierouvert->close();
              ;}

    }
}
