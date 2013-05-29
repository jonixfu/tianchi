// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵�������ݿ������
//     ע�⣺MySQL ��֧�ִ洢���̷������ݼ����Լ���֧�� OUT ���������
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.05.03   ʥ������    ����
//
// ====================================================================================================================
/// @file TcDatabase.h ���ݿ������

#ifndef DATABASE_H
#define DATABASE_H

#include "TcGlobal.h"

#include <QtSql/QSqlDatabase>
#include <QVariant>
#include <QMultiHash>
#include <QStringList>
#include <QList>

typedef QHash<QString, QByteArray>  TcParams;

/// @brief ���ݿ������
/// @note SQLite ��������ʱ�䶼������ String(25) �����ʹ洢
///       ��ʽΪ yyyy-MM-dd HH:mm:ss
/// @author ʥ������ Jonix@qtcn.org
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
        MYSQL      =  2, // ���� MySQL ����ȱ�ݣ���δʵ�ִ˹��ܣ�������ʹ�á�
        POSTGRESQL =  3,
        SQLTIE     = 11
    };

    static  char     typeFrom(QVariant::Type type);

    static  int      dbType(const QString& typeName);
    static  TcParams addParams(const QStringList& keys, const QList<QByteArray>& values);

    /// @brief �����������ݿ�
    void setDatabase(int dbType,
                     const QString& hostName, int hostPort,
                     const QString& dbName, const QString& username, const QString& password);
    /// @brief �����������ݿ�
    bool setDatabase(const QString& typeName,
                     const QString& hostName, int hostPort,
                     const QString& dbName, const QString& username, const QString& password);
    /// @brief ���ñ������ݿ�
    void setDatabase(int dbType,
                     const QString& dbName, const QString& username="", const QString& password="");
    /// @brief ���ñ������ݿ�
    bool setDatabase(const QString& typeName,
                     const QString& dbName, const QString& username="", const QString& password="");

    /// @brief �������ݿⲻ����ʱ��ʹ�ô�DDL�����ؽ�
    QString CreateDDL;

    QString SqlLibrary;

    /// @brief ���ݿ����ʱ�Ĵ�����Ϣ
    QString lastError();


Q_SIGNALS:
    /// @brief ��ȡDBI����ʾ
    /// @note index �� 1 ��ʼ
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

    // ��������
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
    /// �����ݿ�
    /// @return �������
    ///  1   �����ɹ�
    ///  0   ����ʧ��
    /// -1   ���ݿ��޷����������
    /// -2   ���ݿⲻ����
    /// -3   �汾̫�£�����֧��
    /// @see close
    int  open();

    /// @brief �ر����ݿ�
    /// @see open
    void close();

    /// @brief ���ݿ���á�һ���ڹر�ǰ���ã�Ȼ��ȴ������߳��˳���
    bool accepted() const { return m_accepted; }

    /// @brief ���ݿ���á�һ���ڹر�ǰ���ã�Ȼ��ȴ������߳��˳���
    void setAccepted(bool value) { m_accepted = value; }

    /// @brief ���ݿ��Ƿ��Ѵ�
    inline bool isOpened() const { return m_handle.isOpen(); }

    /// @brief �����������ݿ�Ĳ���SQL��
    void loadEngine();
    /// @brief �������ݿ�Ĳ���SQL��
    void loadEngine(const QString& filename);

    /// @brief ���ݿ����׼��, ע�� params �� key ����ȫСд
    QSqlQuery* prepare(const QString& sqlID, TcParams prams,
                       int userNo = 0, const QString& userID = "", const QString& username = "");

    /// @brief ִ�в���SQLID���޷������ݼ�
    bool exec(int& result, const QString& sqlID, const TcParams& prams,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief ִ�в���SQLID���ɷ������ݼ�
    bool exec(QVariantList& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief ִ�в���SQLID���ɷ������ݼ�
    int exec(int& result, QVariantList& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
    /// @brief ִ�в���SQLID���ɷ������ݼ�
    int exec(int& result, QList<QByteArray>& list, const QString& sqlID, const TcParams& params,
              int userNo = 0, const QString& userID = "", const QString& username = "");
};

#endif // DATABASE_H
