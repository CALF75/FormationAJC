#include "monapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonApplication w;
    w.show();

    return a.exec();
}
