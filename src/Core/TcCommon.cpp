#include "Core/TcCommon.h"

QTextCodec* Tianchi_gbkTextCodec = QTextCodec::codecForName("GBK");
QTextCodec* Tianchi_utf8TextCodec = QTextCodec::codecForName("UTF8");
QString GBK(const char* s)
{
    return Tianchi_gbkTextCodec->toUnicode(s);
}
QString UTF8(const char* s)
{
    return Tianchi_utf8TextCodec->toUnicode(s);
}


QTextCodec* initQS(const QByteArray& name)
{
    QTextCodec* textCodec=QTextCodec::codecForName(name);
    QTextCodec::setCodecForLocale(textCodec);
    return textCodec;
}

QString YYYY_MM_DD(QDate date)
{
    return date.dayOfYear() >1900 ? date.toString("yyyy-MM-dd") : "";
}

QString YYYY_MM_DD(QDateTime datetime)
{
    return datetime.date().dayOfYear() >1900 ? datetime.toString("yyyy-MM-dd") : "";
}

QString YYYY_MM_DD_HH_MM_SS(QDateTime datetime)
{
    return datetime.date().dayOfYear() >1900 ? datetime.toString("yyyy-MM-dd HH:mm:ss") : "";
}

QString YYYY_MM_DD_HH_MM_SS_ZZZ(QDateTime datetime)
{
    return datetime.date().dayOfYear() >1900 ? datetime.toString("yyyy-MM-dd HH:mm:ss.zzz") : "";
}

