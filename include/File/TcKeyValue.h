// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// ********************************************************************************************************************
// 文档说明：key=value 格式配置文件的读写
// ====================================================================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------------------------------------------------
// 2013.05.15   圣域天子    建立
//
// ====================================================================================================================
/// @file TcKeyValue.h key=value 格式配置文件的读写
// ====================================================================================================================
#ifndef TCKEYVALUE_H
#define TCKEYVALUE_H

#include <QHash>
#include <QObject>

class TcKeyValue : public QHash<QString, QString>
{
public:
    TcKeyValue();

    bool load(const QString& fileName, const char* codec="UTF8");
    bool save(const QString& fileName, const char* codec="UTF8");

    /// @brief 返回文本文件的行结尾符
    inline QString lineBreak() const
    {
        return m_lineBreak;
    }
    /// @brief 设置文本文件的行结尾符
    inline void lineBreak(const QString& value)
    {
        m_lineBreak = value;
    }
private:
    QString m_lineBreak;
};

#endif // TCKEYVALUE_H
