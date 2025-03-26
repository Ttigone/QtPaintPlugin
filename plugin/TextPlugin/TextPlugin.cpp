#include "TextPlugin.h"

#include <QtWidgets/qinputdialog.h>

// #include <QLabel>
#include <QtWidgets/QLabel>

QString TextPlugin::name()
{
    return QString("Static text");
}

int TextPlugin::getObject(QWidget* parent)
{
    // QPainterPath test;
    // QFont f;
    // QLabel L;
    // QString text = QInputDialog::getText(parent, QString("Insert Text"), QString("Text"));

    // if (!text.isEmpty()) {
    //     ppath.addText(10, 80, QFont("Cambria", 60), text);
    // }

    int ppath = 3;
    return ppath;
}
