#include "File/TcKeyValue.h"
#include "Core/TcCommon.h"
#include "Core/TcString.h"

#include <QFile>
#include <QTextCodec>
#include <QTextStream>

TcKeyValue::TcKeyValue()
{
#if defined(Q_OS_WIN)
    m_lineBreak = "\r\n";
#elif defined(Q_OS_LINUX)
    m_lineBreak = "\n";
#elif defined(Q_OS_MAC)
    m_lineBreak = "\r";
#else
    m_lineBreak = "\n";
#endif
}

bool TcKeyValue::load(const QString& fileName, const char* codec)
{
    bool ret = false;
    QStringList lines;
    if ( TcStringList::load(lines, fileName, codec) )
    {
        foreach(QString s, lines)
        {
            int index = s.indexOf("=");
            if ( index >0 )
            {
                QString key   = s.left(index);
                QString value = s.mid(index+1);
                QHash::operator [](key) = QS(value.toLocal8Bit().data());
            }
        }
        ret = true;
    }
//    bool ret = false;
//    QFile f(fileName);
//    if ( f.open(QFile::Text | QFile::ReadOnly) )
//    {
//        clear();
//        QTextStream in(&f);
//        in.setCodec(QTextCodec::codecForName(codec));
//        while(!in.atEnd())
//        {
//            QString s = in.readLine();
//            int index = s.indexOf("=");
//            if ( index >0 )
//            {
//                QString key   = s.left(index);
//                QString value = s.mid(index+1);
//                QHash::operator [](key) = QS(value.toLocal8Bit().data());
//            }
//        }
//        f.close();
//        ret = true;
//    }
    return ret;
}

bool TcKeyValue::save(const QString& fileName, const char* codec)
{
    QStringList lines;
    for( QHash<QString, QString>::const_iterator it=constBegin(); it!=constEnd(); it++ )
    {
        lines.append(it.key() + "=" + it.value());
    }
    return TcStringList::save(lines, fileName);

//    bool ret = false;
//    QFile f(fileName);
//    if ( f.open(QFile::Text | QFile::WriteOnly) )
//    {
//        QTextStream out(&f);
//        for( QHash<QString, QString>::const_iterator it=constBegin(); it!=constEnd(); it++ )
//        {
//            out<<it.key()<<"="<<it.value()<<lineBreak();
//        }
//        f.close();
//        ret = true;
//    }
//    return ret;
}
