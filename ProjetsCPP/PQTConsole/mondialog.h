#ifndef MONDIALOG_H
#define MONDIALOG_H

#include <QDialog>

namespace Ui {
class MonDialog;
}

class MonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MonDialog(QWidget *parent = nullptr);
    ~MonDialog();

private:
    Ui::MonDialog *ui;
};

#endif // MONDIALOG_H
