#include "linechartwidget.h"

LineChartWidget::LineChartWidget(QWidget *parent) :
    QWidget(parent)
{



}

LineChartWidget::~LineChartWidget()
{

}

bool LineChartWidget::refresh(QMap<QString, QString> map_formulaire)
{
    formatdatetime = QString("yyyy-MM-ddTHH:mm:ss+00:00");

    if(map_formulaire.keys().size() == 0) return false;
    hauteurMax=0.0;
    nb_row = map_formulaire.keys().size();

    for(int i = 0; i < nb_row; i++){
            if(i==0) datedebut=QDateTime::fromString(map_formulaire.keys()[i], formatdatetime);
            if(i==nb_row-1) datefin=QDateTime::fromString(map_formulaire.keys()[i], formatdatetime);
            if(map_formulaire.value(map_formulaire.keys()[i]).toFloat()>hauteurMax) hauteurMax=map_formulaire.value(map_formulaire.keys()[i]).toFloat();
            listeAbscisses << map_formulaire.keys()[i];
            listeOrdonnees << map_formulaire.value(map_formulaire.keys()[i]);
    }

    Deltatemps = datefin.toSecsSinceEpoch()-datedebut.toSecsSinceEpoch();
    if (Deltatemps>25*3600)
    {typePeriode=QString("semaine");}
    else
    {typePeriode=QString("journée");}
    return true;
}

QPoint LineChartWidget::TransformationCoordonnees(QPoint point)
{
    //Passage des coordonnées dans le graphique à celle dans le widget
    int xr,yr;
    xr = point.x() + largeurwidget/12.0;
    yr = hauteurwidget*5.0/6.0 - point.y();

    QPoint pointRetourne(xr,yr);
    return pointRetourne;
}

void LineChartWidget::paintEvent(QPaintEvent *event)
{


    couleurAxes = Qt::darkGray;
    couleurCourbe = Qt::darkBlue;
    couleurRemplissage = Qt::blue;
    hauteurwidget = this->height();
    largeurwidget = this->width();
    hauteurgraphique = hauteurwidget*5.0/6.0;
    largeurgraphique = largeurwidget*5.0/6.0;
    QPainter painter(this);
    QBrush brush(couleurRemplissage);
    QPen pen(couleurAxes);
    pen.setWidth(3);
    QPen pen2(couleurCourbe);
    QPen pen3(Qt::transparent);
    painter.setBrush(brush);

QPoint polygone[nb_row+2];
QPoint polyline[nb_row];
polygone[0]=this->TransformationCoordonnees(QPoint(0,0));
qDebug()<<"listeAbscisses"<<listeAbscisses;
for(int i=0;i<nb_row;i++)
{
    int xpm,ypm;
    qint64 Deltat = QDateTime::fromString(listeAbscisses[i], formatdatetime).toSecsSinceEpoch()-datedebut.toSecsSinceEpoch();
    xpm=(largeurgraphique*1.0)*(1.0*Deltat)/(Deltatemps*1.0);
    ypm=(hauteurgraphique*1.0)*(listeOrdonnees[i].toFloat())/(hauteurMax*1.0);
    QPoint mesure = TransformationCoordonnees(QPoint(xpm,ypm));
    qDebug()<<mesure;
    polygone[i+1]=mesure;
    polyline[i]=mesure;
}

polygone[nb_row+1]=TransformationCoordonnees(QPoint(largeurgraphique,0));
painter.setPen(pen3);
painter.drawPolygon(polygone,nb_row+2);
painter.setPen(pen2);
painter.drawLine(TransformationCoordonnees(QPoint(0,hauteurgraphique)),TransformationCoordonnees(QPoint(largeurgraphique,hauteurgraphique)));
painter.drawPolyline(polyline,nb_row);
painter.setPen(pen);
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(largeurgraphique,0)));
painter.drawLine(TransformationCoordonnees(QPoint(0,0)),TransformationCoordonnees(QPoint(0,hauteurgraphique)));


}
