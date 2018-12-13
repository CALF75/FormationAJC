#include <QCoreApplication>
#include <iostream>
#include <qdebug.h>
#include <QDir>
#include <QString>
#include <QRegExp>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<<"tests\n"<<std::endl;
    qDebug()<<"rep de recherche :"<<QDir::home()<<"\n";
    QDir dir(QDir::home());
    QStringList resultatsR;
    resultatsR = dir.entryList(QDir::Files | QDir::Hidden |QDir::Dirs );
    qDebug()<<"Contenu du répertoire :"<<resultatsR<<"\n";
    qDebug()<<"=======================";
    QRegExp exp1("(\\w*)\\.w{3}");
    QRegExp exp2("([a-z0-9A-Z]*)\\.[a-z0-9A-Z]{3}$");
    qDebug()<<"Contenu du répertoire :"<<resultatsR.indexOf(exp1)<<"\n";
    qDebug()<<"Contenu du répertoire :"<<resultatsR.indexOf(exp2)<<"\n";
QString str;
    foreach (str, resultatsR) {
        if(exp2.indexIn(str)!=-1){
            qDebug()<<"Le nom du fichier est : "<<str;
            qDebug()<<"Le nom du fichier est : "<<exp2.cap(1);
        }
    }


    return a.exec();
}
