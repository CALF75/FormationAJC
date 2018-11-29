#ifndef MYQCOLORBUTTON_H
#define MYQCOLORBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QColorDialog>

class MyQColorButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyQColorButton(QWidget *parent = nullptr);

public : QColor* CouleurButton;
         QColorDialog* MaFenetreDeCouleurs;
         ~MyQColorButton();


private slots: void OuvrirFenetre();
protected : void paintEvent(QPaintEvent *event) override;

};

#endif // MYQCOLORBUTTON_H
