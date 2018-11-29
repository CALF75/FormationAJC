#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlTableModel>
#include <QSqlQueryModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public: QSqlDatabase* db;

private:
    Ui::MainWindow *ui;

private slots: void AfficherResultat();
};

#endif // MAINWINDOW_H
