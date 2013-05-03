#include <tianchi/Gui/DateEdit.h>
#include <QtPlugin>
#include "DateEditPlugin.h"


DateEditPlugin::DateEditPlugin(QObject *parent)
    : QObject(parent), m_initialized(false)
{
}

QString DateEditPlugin::name() const
{
    return "TcDateEdit";
}

QString DateEditPlugin::includeFile() const
{
    return "tianchi/Gui/DateEdit.h";
}

QString DateEditPlugin::group() const
{
    return tr("Tianchi Widgets");
}

QIcon DateEditPlugin::icon() const
{
    return QIcon();
}

QString DateEditPlugin::toolTip() const
{
    return tr("a date edit widget that can been empty");
}

QString DateEditPlugin::whatsThis() const
{
    return tr("a date edit widget that can been empty");
}

bool DateEditPlugin::isContainer() const
{
    return false;
}

QWidget* DateEditPlugin::createWidget(QWidget *parent)
{
    return new TcDateEdit(parent);
}

bool DateEditPlugin::isInitialized() const
{
    return m_initialized;
}

void DateEditPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (m_initialized)
        return;

    m_initialized = true;
}

QString DateEditPlugin::domXml() const
{
    return QString("\
    <ui language=\"c++\">\
        <widget class=\"TcDateEdit\" name=\"tcDateEdit\">\
        </widget>\
    </ui>");
}

