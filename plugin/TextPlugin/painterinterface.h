#ifndef PAINTERINTERFACE_H
#define PAINTERINTERFACE_H

#include <QtGui/qpainterpath.h>
#include <QtPlugin>

class PainterInterface
{
public:
    virtual ~PainterInterface() {};
    virtual QString name() = 0;
    // virtual QPainterPath getObject(QWidget* parent) = 0;
    virtual int getObject(QWidget* parent) = 0;
};

#define PainterInterface_iid "org.qt-project.Qt.PainterDemo.PainterInterface"

Q_DECLARE_INTERFACE(PainterInterface, PainterInterface_iid)

#endif // PAINTERINTERFACE_H
