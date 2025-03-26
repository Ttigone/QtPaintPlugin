#ifndef TESTPLUGIN_HPP
#define TESTPLUGIN_HPP

#include <QObject>
#include <QtWidgets/QInputDialog>
#include "paintersharedinterface.h"
#include "testPlugin_global.hpp"

class TESTPLUGIN_EXPORT TestPlugin : public QObject, public PainterSharedInterface
{
    Q_OBJECT
    Q_INTERFACES(PainterSharedInterface)
    Q_PLUGIN_METADATA(IID "org.ttigone.plugin" FILE "test.json")
public:
    TestPlugin();
    ~TestPlugin();
    QString name() override { return "TEST2"; }
    QPainterPath getObject(QWidget *parent) override
    {
        QPainterPath ppath;
        QString text = QInputDialog::getText(parent, QString("Insert Text"), QString("Text"));

        if (!text.isEmpty()) {
            ppath.setFillRule(Qt::FillRule::OddEvenFill);
            ppath.addText(10, 80, QFont("Cambria", 60), text);
        }
        return ppath;
    }
};

#endif // TESTPLUGIN_HPP
