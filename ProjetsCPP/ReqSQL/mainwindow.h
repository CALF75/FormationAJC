#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
QSqlDatabase* db;
QString* Ville;
QString* ChefLieu;
QString* Departement;
QString* CP;

private:
    Ui::MainWindow *ui;

private slots: void ExecuterReq();
};

#endif // MAINWINDOW_H
