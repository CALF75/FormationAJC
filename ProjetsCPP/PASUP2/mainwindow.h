#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public: int i;

private:
    Ui::MainWindow *ui;

private slots: void Bouton1();
private slots: void Bouton2();
};

#endif // MAINWINDOW_H
