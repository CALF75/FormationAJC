#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QNetworkReply>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

QNetworkAccessManager *manager;
QNetworkReply *reply;
QString contenureponse;
QJsonDocument jsonrep;
QJsonObject jsonobj;
clock_t start, end;
double elapsed;

private:
    Ui::MainWindow *ui;


public slots:
    void replyFinished(QNetworkReply*);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError err);
    void sfinished();
    void slotSslErrors(QList<QSslError>);
    void processOneThing();
};

#endif // MAINWINDOW_H
