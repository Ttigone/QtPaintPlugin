#ifndef TEXTPLUGIN_H
#define TEXTPLUGIN_H

#include <QObject>
#include <QPainterPath>

#include "painterinterface.h"

class TextPlugin : public QObject, public PainterInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.PainterDemo.PainterInterface" FILE "info.json")
    Q_INTERFACES(PainterInterface)

public:
    TextPlugin() = default;
    QString name() override;
    int getObject(QWidget* parent) override;
};

#endif // TEXTPLUGIN_H
