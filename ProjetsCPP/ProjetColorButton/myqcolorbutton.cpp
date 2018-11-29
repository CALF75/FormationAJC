#include "myqcolorbutton.h"

MyQColorButton::MyQColorButton(QWidget *parent)  : QPushButton(parent)
{

    CouleurButton = new QColor;
    *CouleurButton=Qt::transparent;
    connect(this,SIGNAL(clicked(bool)),this,SLOT(OuvrirFenetre()));

}

MyQColorButton::~MyQColorButton(){
    delete(CouleurButton);
}

void MyQColorButton::OuvrirFenetre()
{
MaFenetreDeCouleurs = new QColorDialog(this);
*CouleurButton=MaFenetreDeCouleurs->getColor();
delete(MaFenetreDeCouleurs);
}

void MyQColorButton::paintEvent(QPaintEvent *event)
{
QPushButton::paintEvent(event);
QPainter painter(this);
QBrush brush(*CouleurButton);
QPen pen(*CouleurButton);
painter.setPen(pen);
painter.setBrush(brush);
painter.drawEllipse(width()/6,height()/6,20,20);

}
