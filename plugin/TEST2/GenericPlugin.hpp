#ifndef GENERICPLUGIN_HPP
#define GENERICPLUGIN_HPP

#include <QGenericPlugin>

class GenericPlugin : public QGenericPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QGenericPluginFactoryInterface_iid FILE "TEST2.json")

public:
    explicit GenericPlugin(QObject *parent = nullptr);

private:
    QObject *create(const QString &name, const QString &spec) override;
};

#endif // GENERICPLUGIN_HPP
