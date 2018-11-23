#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <apropos.h>
#include "policedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    APropos* fenetreapropos;
    PoliceDIalog* fenetrepolice;
    QString fileName;
    QFile* fichierouvert;


private:
    Ui::MainWindow *ui;

private slots: void OuvrirFichier();
private slots: void SauvegarderFichier();
private slots: int OuvrirAPropos();
private slots: void OuvrirPoliceDialog();
};

#endif // MAINWINDOW_H
