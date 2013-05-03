#include <tianchi/Gui/ClickLabel.h>
#include <QtPlugin>
#include "ClickLabelPlugin.h"


ClickLabelPlugin::ClickLabelPlugin(QObject *parent)
    : QObject(parent), m_initialized(false)
{
}

QString ClickLabelPlugin::name() const
{
    return "TcClickLabel";
}

QString ClickLabelPlugin::includeFile() const
{
    return "tianchi/Gui/ClickLabel.h";
}

QString ClickLabelPlugin::group() const
{
    return tr("Tianchi Widgets");
}

QIcon ClickLabelPlugin::icon() const
{
    return QIcon();
}

QString ClickLabelPlugin::toolTip() const
{
    return tr("a clickable label widget");
}

QString ClickLabelPlugin::whatsThis() const
{
    return tr("emit clicked() label widget when mouse clicked");
}

bool ClickLabelPlugin::isContainer() const
{
    return false;
}

QWidget* ClickLabelPlugin::createWidget(QWidget *parent)
{
    return new TcClickLabel(parent);
}

bool ClickLabelPlugin::isInitialized() const
{
    return m_initialized;
}

void ClickLabelPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (m_initialized)
        return;

    m_initialized = true;
}

QString ClickLabelPlugin::domXml() const
{
    return QString("\
    <ui language=\"c++\">\
        <widget class=\"TcClickLabel\" name=\"tcClickLabel\">\
            <property name=\"text\">\
                <string>clickText</string>\
            </property>\
        </widget>\
    </ui>");
}

