#include "tianchi/Sql/MSSQL.h"

#include <QSettings>
#include <QStringListIterator>
#include <QtAlgorithms>

QStringList TcMSSQL::availableODBCDrivers()
{
    QStringList slDrivers;
#ifdef Q_OS_WIN
    QSettings  sts("HKEY_LOCAL_MACHINE\\SOFTWARE\\ODBC\\ODBCINST.INI\\ODBC Drivers", QSettings::NativeFormat);
    QStringList slKeys = sts.allKeys();

    QStringList slKeys2;
    slKeys2 << slKeys.filter("SQL Server") << slKeys.filter("Native Client");
    slKeys2.removeDuplicates();
    QStringListIterator it(slKeys2);

    while (it.hasNext())
    {
        QString strV = it.next();
        if (sts.value(strV).toString() == "Installed")
        {
            QSettings sts2("HKEY_LOCAL_MACHINE\\SOFTWARE\\ODBC\\ODBCINST.INI\\" + strV, QSettings::NativeFormat);
            strV.prepend(sts2.value("DriverODBCVer").toString() + "/");
            slDrivers << strV;
        }
    }
    qSort(slDrivers.begin(), slDrivers.end(), qGreater<QString>());
#endif
    return slDrivers;
}

