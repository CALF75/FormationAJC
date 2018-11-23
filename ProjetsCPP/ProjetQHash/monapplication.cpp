#include "monapplication.h"
#include "ui_monapplication.h"




MonApplication::MonApplication(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonApplication)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));

    qhashAge["Gilles"]=85;
    qhashAge["Tartenpion"]=18;
    qhashAge["Tartenpionne"]=16;
    qhashAge["Zigoto"]=25;

    ui->comboBox->addItems(qhashAge.keys());
    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(AffichageAge()));
    ui->lineEdit->setText(QString::number(qhashAge[ui->comboBox->currentText()]));
}

MonApplication::~MonApplication()
{
    delete ui;
}

void MonApplication::AffichageAge()
{
    qDebug()<<"On a bien déclenché l'action";

    ui->lineEdit->setText(QString::number(qhashAge[ui->comboBox->currentText()]));
}
