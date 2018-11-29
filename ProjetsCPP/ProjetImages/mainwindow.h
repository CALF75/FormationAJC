#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected : void paintEvent(QPaintEvent *event) override;
            void mousePressEvent(QMouseEvent *event) override;
            void mouseDoubleClickEvent(QMouseEvent *event) override;
            void mouseMoveEvent(QMouseEvent *event) override;
            void keyPressEvent(QKeyEvent *event) override;


};

#endif // MAINWINDOW_H
