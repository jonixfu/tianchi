#include <QtPlugin>

#include "TianchiPlugins.h"
#include "TcDateEditPlugin.h"
#include "TcLineEditPlugin.h"
#include "TcClickLabelPlugin.h"
#include "TcMarqueeLabelPlugin.h"


TianchiPlugins::TianchiPlugins(QObject *parent)
    : QObject(parent)
{
    m_plugins.append(new TcDateEditPlugin(this));
    m_plugins.append(new TcLineEditPlugin(this));
    m_plugins.append(new TcClickLabelPlugin(this));
    m_plugins.append(new TcMarqueeLabelPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> TianchiPlugins::customWidgets()
    const
{
    return m_plugins;
}


#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
Q_EXPORT_PLUGIN(TianchiPlugins)
#endif
