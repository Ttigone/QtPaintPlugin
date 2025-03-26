#ifndef TEXTPLUGIN_H
#define TEXTPLUGIN_H

#include <QFont>
#include <QInputDialog>
#include <QObject>
#include <QPainterPath>

#include "paintersharedinterface.h"


class TextSharedPlugin : public QObject, public PainterSharedInterface
{
    Q_OBJECT
    Q_INTERFACES(PainterSharedInterface)
    Q_PLUGIN_METADATA(IID "org.ttigone.plugin" FILE "info.json")

public:
    TextSharedPlugin();
    ~TextSharedPlugin();
    QString name() override;
    QPainterPath getObject(QWidget* parent) override;
};

#endif // TEXTPLUGIN_H
