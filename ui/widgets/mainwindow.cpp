#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include "pluginapi/painterinterface.h"

#include <QDir>

#include "pluginapi/paintersharedinterface.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas_ = new Canvas;
    setCentralWidget(canvas_);
    loadPlugins();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onInsertInterface()
{
    // QAction* action = qobject_cast<QAction*>(sender());
    QAction* action = qobject_cast<QAction*>(sender());
    PainterSharedInterface* insertInterfacePlugin = qobject_cast<PainterSharedInterface*>(action->parent());
    const QPainterPath ppath = insertInterfacePlugin->getObject(this);
    if (!ppath.isEmpty()) {
        canvas_->insertPainterPath(ppath);
    }
    // PainterInterface* insertInterfacePlugin = qobject_cast<PainterInterface*>(action->parent());

    // qDebug() << insertInterfacePlugin->getObject(this);
}

void MainWindow::loadPlugins()
{
#ifdef QT_STATICPLUGIN
    qDebug() << "static: " << QPluginLoader::staticInstances();
    foreach (auto& plugin, QPluginLoader::staticInstances()) {
        generatePluginMenu(plugin);
    }
#endif

    QDir pluginDir = QDir(qApp->applicationDirPath());
    QStringList filters;
#ifdef Q_OS_WIN
    filters << "*.dll";
#elif defined(Q_OS_MAC)
    filters << "*.dylib";
#else
    filters << "*.so";
#endif

    // 扫描目录中的所有可能的插件文件
    foreach (QString fileName, pluginDir.entryList(filters, QDir::Files)) {
        QString filePath = pluginDir.absoluteFilePath(fileName);
        if (QLibrary::isLibrary(filePath)) {
            qDebug() << "Attempting to load:" << filePath;

            QPluginLoader loader(filePath);
            // 获取元数据 - 无需加载插件
            QJsonObject metadata = loader.metaData();

            if (metadata.isEmpty()) {
                qDebug() << fileName << "不是有效的Qt插件";
                continue;
            }
            qDebug() << "插件:" << fileName;
            qDebug() << "get Data: " << metadata;

            // 访问元数据字段
            QString iid = metadata["IID"].toString();
            qDebug() << "  接口ID:" << iid;

            // 访问元数据字段
            QString className = metadata["className"].toString();
            qDebug() << "className" << className;

            // "MetaData 是固定的键" ?
            QJsonObject metaDataObj = metadata["MetaData"].toObject();
            qDebug() << "MetaData:" << metaDataObj;


            QObject* plugin = loader.instance();
            qDebug() << "plugin: " << plugin;
            if (plugin) {
                PainterSharedInterface* insertInterfacePlugin = qobject_cast<PainterSharedInterface*>(plugin);
                if (insertInterfacePlugin) {
                    QAction* action = new QAction(insertInterfacePlugin->name(), plugin);
                    connect(action, &QAction::triggered, this, &MainWindow::onInsertInterface);
                    ui->menuPlugins->addAction(action);
                }
            } else {
                qDebug() << "Failed to load plugin:" << fileName;
                qDebug() << "Error:" << loader.errorString();
            }
        }
    }
}

void MainWindow::generatePluginMenu(QObject* plugin)
{
    PainterInterface* insertInterfacePlugin = qobject_cast<PainterInterface*>(plugin);
    if (insertInterfacePlugin) {
        QAction* action = new QAction(insertInterfacePlugin->name(), plugin);
        connect(action, &QAction::triggered, this, &MainWindow::onInsertInterface);
        ui->menuPlugins->addAction(action);
    }
}
