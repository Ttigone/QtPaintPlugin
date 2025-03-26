#ifndef PAINTERINTERFACE_H
#define PAINTERINTERFACE_H

#include <QtGui/qpainterpath.h>
#include <QtPlugin>

class PainterSharedInterface
{
public:
    virtual ~PainterSharedInterface() {};
    virtual QString name() = 0;
    virtual QPainterPath getObject(QWidget* parent) = 0;
};

#define PainterSharedInterface_iid "org.ttigone.plugin"

Q_DECLARE_INTERFACE(PainterSharedInterface, PainterSharedInterface_iid)

#endif // PAINTERINTERFACE_H
