#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QFont>
#include <qdebug.h>

void configurationlogiciel(QSettings &s){
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


int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationDomain("MASOC");
    QCoreApplication::setApplicationName("EDITEX");
    QApplication a(argc, argv);
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings settings;
    settings.setValue("mon cul","blabla");
    configurationlogiciel(settings);

    MainWindow w;
    w.show();

    return a.exec();
}

