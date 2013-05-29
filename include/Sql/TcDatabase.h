// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// ********************************************************************************************************************
// 文档说明：数据库操作类
//     注意：MySQL 不支持存储过程返回数据集，以及不支持 OUT 输出参数。
// ====================================================================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------------------------------------------------
// 2013.05.03   圣域天子    建立
//
// ====================================================================================================================
/// @file TcDatabase.h 数据库操作类

#ifndef DATABASE_H
#define DATABASE_H

#include "TcGlobal.h"

#include <QtSql/QSqlDatabase>
#include <QVariant>
#include <QMultiHash>
#include <QStringList>
#include <QList>

typedef QHash<QString, QByteArray>  TcParams;

/// @brief 数据库操作类
/// @note SQLite 的日期与时间都采用了 String(25) 的类型存储
///       格式为 yyyy-MM-dd HH:mm:ss
/// @author 圣域天子 Jonix@qtcn.org
/// @date 2013-05-03
class TIANCHI_API TcDatabase : public QObject
{
    Q_OBJECT
public:
    TcDatabase();
    virtual ~TcDatabase(void);

    enum DBType
    {
        SQLSERVER  =  1,
        MYSQL      =  2, // 由于 MySQL 自身缺陷，故未实现此功能，不建议使用。
        POSTGRESQL =  3,
        SQLTIE     = 11
    };

    static  char     typeFrom(QVariant::Type type);

    static  int      dbType(const QString& typeName);
    static  TcParams addParams(const QStringList& keys, const QList<QByteArray>& values);

    /// @brief 设置网络数据库
    void setDatabase(int dbType,
                     const QString& hostName, int hostPort,
                     const QString& dbName, const QString& username, const QString& password);
    /// @brief 设置网络数据库
    bool setDatabase(const QString& typeName,
                     const QString& hostName, int hostPort,
                     const QString& dbName, const QString& username, const QString& password);
    /// @brief 设置本地数据库
    void setDatabase(int dbType,
                     const QString& dbName, const QString& username="", const QString& password="");
    /// @brief 设置本地数据库
    bool setDatabase(const QString& typeName,
                     const QString& dbName, const QString& username="", const QString& password="");

    /// @brief 本地数据库不存在时，使用此DDL进行重建
    QString CreateDDL;

    QString SqlLibrary;

    /// @brief 数据库操作时的错误信息
    QString lastError();


Q_SIGNALS:
    /// @brief 读取DBI的提示
    /// @note index 从 1 开始
    void dbiLoading(int index, const QString& dbiName);

protected:
    int     m_dbType;
    QString m_typeName;
    QString m_hostName;
    int     m_hostPort;
    QString m_dbName;
    QString m_username;
    QString m_password;

    QString m_lastError;

    QSqlDatabase    m_handle;
    bool            m_accepted;

    // 数据引擎
    QString m_engineFile;
    struct SQLContext
    {
        QString                         id;
        QString                         text;
        QMultiHash<QString, QString>    params;
    };
    QHash<QString, SQLContext>  m_sqls;
    void clearComment(QString& s);

    QMultiHash<QString, QString> getParamList(QString& param_line, QString param_list);

public:
    inline int      dbType()   const { return m_dbType;   }
    inline QString  typeName() const { return m_typeName; }
    inline QString  hostName() const { return m_hostName; }
    inline int      hostPort() const { return m_hostPort; }
    inline QString  dbName()   const { return m_dbName;   }

    inline QSqlDatabase handle() const { return m_handle; }
    inline int          sqlCount() const { return m_sqls.count(); }

public:
    /// 打开数据库
    /// @return 操作结果
    ///  1   操作成功
    ///  0   操作失败
    /// -1   数据库无法创建或更新
    /// -2   数据库不兼容
    /// -3   版本太新，程序不支持
    /// @see close
    int  open();

    /// @brief 关闭数据库
    /// @see open
    void close();

    /// @brief 数据库禁用。一般在关闭前设置，然后等待所有线程退出。
    bool accepted() const { return m_accepted; }

    /// @brief 数据库禁用。一般在关闭前设置，然后等待所有线程退出。
    void setAccepted(bool value) { m_accepted = value; }

    /// @brief 数据库是否已打开
    inline bool isOpened() const { return m_handle.isOpen(); }

    /// @brief 重新载入数据库的操作SQL集
    void loadEngine();
    /// @brief 载入数据库的操作SQL集
    void loadEngine(const QString& filename);

    /// @brief 数据库操作准备, 注意 params 的 key 必须全小写
    QSqlQuery* prepare(const QString& sqlID, TcParams prams,
                       int userNo = 0, const QString& userID = "", const QString& username = "");

    /// @brief 执行操作SQLID，无返回数据集
    bool exec(int& result, const QString& sqlID, const TcParams& prams,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief 执行操作SQLID，可返回数据集
    bool exec(QVariantList& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief 执行操作SQLID，可返回数据集
    int exec(int& result, QVariantList& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief 执行操作SQLID，可返回数据集
    int exec(int& result, QList<QByteArray>& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
};

#endif // DATABASE_H
