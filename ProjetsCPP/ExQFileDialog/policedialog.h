#ifndef POLICEDIALOG_H
#define POLICEDIALOG_H
#include <QDebug>
#include <QDialog>
#include <QFont>
#include <QSettings>
namespace Ui {
class PoliceDIalog;
}

class PoliceDIalog : public QDialog
{
    Q_OBJECT

public:
    explicit PoliceDIalog(QWidget *parent = nullptr);
    ~PoliceDIalog();
    void reject();
    void configurationlogiciel2(QSettings &s);


private:
    Ui::PoliceDIalog *ui;
    private slots: void ValiderChangementPolice();
    private slots: void AppliquerChangementPolice();



};

#endif // POLICEDIALOG_H
