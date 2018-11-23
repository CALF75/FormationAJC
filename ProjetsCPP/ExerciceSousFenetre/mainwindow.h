#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    char* nomprogramme;
    int setnomprogramme(char* np);
private:
    Ui::MainWindow *ui;

private slots:
    int AfficherAPropos();

};

#endif // MAINWINDOW_H
