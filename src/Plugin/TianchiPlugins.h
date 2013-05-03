#ifndef TIANCHI_PLUGINS_H
#define TIANCHI_PLUGINS_H

#include <QDesignerCustomWidgetCollectionInterface>


class TianchiPlugins : public QObject,
    public QDesignerCustomWidgetCollectionInterface
{
    Q_OBJECT
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID \
            "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
#endif
    Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)
public:
    TianchiPlugins(QObject *parent = 0);
    virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;
private:
    QList<QDesignerCustomWidgetInterface*> m_plugins;
};


#endif // TIANCHI_PLUGINS_H
