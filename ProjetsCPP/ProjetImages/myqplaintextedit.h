#ifndef MYQPLAINTEXTEDIT_H
#define MYQPLAINTEXTEDIT_H
#include <QPlainTextEdit>
#include <QWidget>

class MyQPlainTextEdit : public QPlainTextEdit
{

    Q_OBJECT

public:
    explicit MyQPlainTextEdit(QWidget *parent = 0);
};

#endif // MYQPLAINTEXTEDIT_H
