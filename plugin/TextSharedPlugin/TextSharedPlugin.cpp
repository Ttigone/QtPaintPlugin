#include "TextSharedPlugin.h"


TextSharedPlugin::TextSharedPlugin()
{
}

TextSharedPlugin::~TextSharedPlugin()
{
}

QString TextSharedPlugin::name()
{
    return "TEST4";
}

QPainterPath TextSharedPlugin::getObject(QWidget* parent)
{
    QPainterPath ppath;
    QString text = QInputDialog::getText(parent, QString("Insert Text"), QString("Text"));

    if (!text.isEmpty()) {
        ppath.addText(10, 80, QFont("Cambria", 60), text);
    }
    return ppath;
}
