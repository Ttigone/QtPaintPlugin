#ifdef USE_QT

#include "ui/widgets/mainwindow.hpp"

#include <QApplication>

// 声明静态插件
#ifdef QT_STATICPLUGIN
Q_IMPORT_PLUGIN(TextPlugin)
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
#else
#error Please enable the USE_QT [DUSE_QT] variable to use Qt.
#endif
