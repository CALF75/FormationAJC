#ifndef MONAPPLICATION_H
#define MONAPPLICATION_H

#include <QMainWindow>
#include <QMap>
#include <QDebug>
namespace Ui {
class MonApplication;
}

class MonApplication : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonApplication(QWidget *parent = nullptr);
    ~MonApplication();

private:
    Ui::MonApplication *ui;
    QMap <QString, int> qhashAge;
//ou QHash
private slots:
    void AffichageAge();
};

#endif // MONAPPLICATION_H
