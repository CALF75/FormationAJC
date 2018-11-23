#include "policedialog.h"
#include "ui_policedialog.h"



void PoliceDIalog::configurationlogiciel2(QSettings &s){
    //copie du main
    QFont fontinit;
    qDebug()<<"fonctionconfiguration"<<s.value("Style/Police").toString();
    qDebug()<<"fonctionconfiguration"<<s.value("Style/TaillePolice").toString();
if(!s.value("Style/Police").isNull()){
fontinit.setFamily(s.value("Style/Police").toString());
}else{
fontinit.setFamily("Ubuntu");
}
if(!s.value("Style/TaillePolice").isNull()){
fontinit.setPointSize(s.value("Style/TaillePolice").toInt());
}else{
    fontinit.setPointSize(11);
}
QGuiApplication::setFont(fontinit);
qDebug()<<"fonctionconfiguration"<<QGuiApplication::font();
QApplication::setFont(fontinit);
}

PoliceDIalog::PoliceDIalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PoliceDIalog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ValiderChangementPolice()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(AppliquerChangementPolice()));
    ui->spinBox->setValue(QGuiApplication::font().pointSize());
    ui->fontComboBox->setCurrentFont(QGuiApplication::font());
}

PoliceDIalog::~PoliceDIalog()
{

    delete ui;
}


void PoliceDIalog::reject(){

    QSettings srej;
    PoliceDIalog::configurationlogiciel2(srej);
    QDialog::reject();
        qDebug()<<"La fonction reject est appelée.";
        ui->spinBox->setValue(QGuiApplication::font().pointSize());
        ui->fontComboBox->setCurrentFont(QGuiApplication::font());
}


void PoliceDIalog::ValiderChangementPolice()
{
    this->AppliquerChangementPolice();
    QSettings sval;
    sval.beginGroup("Style");
    sval.setValue("Police", (ui->fontComboBox->currentFont()).family());
    sval.setValue("TaillePolice", ui->spinBox->value());
    sval.endGroup();
    this->close();

}

void PoliceDIalog::AppliquerChangementPolice()
{
    qDebug()<<"Entrée dans méthode ValiderChangementPolice"<<QGuiApplication::font();
    QFont nouvellepolice;
    nouvellepolice = ui->fontComboBox->currentFont();
    nouvellepolice.setPointSize(ui->spinBox->value());
    qDebug()<<"Entrée dans méthode ValiderChangementPolice"<<nouvellepolice;
    QGuiApplication::setFont(nouvellepolice);
    qDebug()<<"Entrée dans méthode ValiderChangementPolice"<<QGuiApplication::font();
    QApplication::setFont(nouvellepolice);
    //pour modifier la fonte QGuiApplication::setFont(const QFont &font)
    //pour metttre la taille à une qfonte QFont::setPointSize(int pointSize)
    //QFont::pointSize()

}
