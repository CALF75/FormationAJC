#ifndef EVENEMENTWIDGET_H
#define EVENEMENTWIDGET_H

#include "awidget.h"
#include "evenementmozaicwidget.h"

class EvenementWidget : public AWidget
{
public:
    explicit EvenementWidget(QWidget *parent = 0);

    ~EvenementWidget();
    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

    EvenementMozaicWidget *evenement_mozaic_widget;

signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};

#endif // EVENEMENTWIDGET_H
