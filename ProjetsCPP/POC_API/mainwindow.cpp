#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
start=clock();

    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(close()));
/*
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
    timer->start(1000);
*/
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(replyFinished(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=vigicrues&q=timestamp+%3E%3D+2018-12-13T09%3A00%3A00%2B00%3A00+AND+station_id+%3D+F704000101&facet=station_id&facet=lbstationhydro&facet=cdcommune&facet=timestamp&facet=cdzonehydro&geofilter.distance=48.862725%2C+2.287592%2C+5000"));

    end = clock();
    elapsed= ((double)end - start) / CLOCKS_PER_SEC; /* Conversion en seconde */
    qDebug()<<CLOCKS_PER_SEC;
    qDebug()<<"1 elapsed vaut : "<<elapsed;
    reply = manager->get(request);

    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(reply, SIGNAL(finished()), this, SLOT(sfinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *)
{
qDebug()<<"on est dans replyFinished";

}

void MainWindow::slotReadyRead()
{
qDebug()<<"on est dans slotReadyRead";

}

void MainWindow::slotError(QNetworkReply::NetworkError err)
{
qDebug()<<"on est dans slotError";
qDebug()<<err;
}

void MainWindow::sfinished()
{
  qDebug()<<"on est dans sfinished";
  end = clock();
  elapsed= ((double)end - start) / CLOCKS_PER_SEC; /* Conversion en seconde */
  qDebug()<<CLOCKS_PER_SEC;
  qDebug()<<"2 elapsed vaut : "<<elapsed;
  jsonrep=QJsonDocument::fromJson(reply->readAll());
  qDebug()<<jsonrep;
  qDebug()<<"isNull : "<<jsonrep.isNull();
  qDebug()<<"isArray : "<<jsonrep.isArray();
  qDebug()<<"isEmpty : "<<jsonrep.isEmpty();
  qDebug()<<"isObject : "<<jsonrep.isObject();
  end = clock();
  elapsed= ((double)end - start) / CLOCKS_PER_SEC; /* Conversion en seconde */
  qDebug()<<CLOCKS_PER_SEC;
  qDebug()<<"3 elapsed vaut : "<<elapsed;
  contenureponse = jsonrep.toJson();
  ui->plainTextEdit->setPlainText(contenureponse);
  jsonobj=jsonrep.object();
  qDebug()<<"Le nombre de hits est :"<<jsonobj.value(QString("nhits")).toDouble();
  qDebug()<<"Le records est :"<<jsonobj.value(QString("records"));
  QJsonArray MonJSonArray = jsonobj.value(QString("records")).toArray();
  qDebug()<<"=================";
  qDebug()<<MonJSonArray.size();
  int i;
  for(i=0;i<MonJSonArray.size();i++)
  {
      qDebug()<<"ZZZZZZZZZZZZZZZZZZZZZ";
      qDebug()<<MonJSonArray[i];
      qDebug()<<MonJSonArray[i].isObject();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).isObject();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("dist")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("lbstationhydro")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdcommune")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("timestamp")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("station_id")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("cdzonehydro")).toString();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[0].toDouble();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("coordonneeswgs84")).toArray()[1].toDouble();
      qDebug()<<MonJSonArray[i].toObject().value(QString("fields")).toObject().value(QString("hauteur")).toDouble();
      qDebug()<<MonJSonArray[i].toObject().value(QString("geometry")).toObject().value(QString("type")).toString();

end = clock();
elapsed= ((double)end - start) / CLOCKS_PER_SEC; /* Conversion en seconde */
qDebug()<<CLOCKS_PER_SEC;
qDebug()<<"elapsed vaut : "<<elapsed;
  }
}

void MainWindow::slotSslErrors(QList<QSslError>)
{
qDebug()<<"on est dans slotSslErrors";

}

void MainWindow::processOneThing()
{
    qDebug()<<"on est rentré dans le timer";
}
