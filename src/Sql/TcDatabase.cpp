#include "Sql/TcDatabase.h"
#include "Core/TcUtils.h"

#include <QtSql/QtSql>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDesktopServices>

#include "Core/TcCommon.h"

//static QList<QSqlQuery*> TcDatabase::Queries;
TcDatabase::TcDatabase()
{
    m_accepted = true;
}

TcDatabase::~TcDatabase(void)
{
    close();
}

char TcDatabase::typeFrom(QVariant::Type type)
{
    char c = '\0';
    if ( type == QVariant::Int
      || type == QVariant::UInt
      || type == QVariant::LongLong
      || type == QVariant::ULongLong )
    {
        c = 'i';
    }else
    if ( type == QVariant::Double )
    {
        c = 'n';
    }else
    if ( type == QVariant::String )
    {
        c = 's';
    }else
    if ( type == QVariant::Date
      || type == QVariant::Time
      || type == QVariant::DateTime )
    {
        c = 't';
    }else
    if ( type == QVariant::Date
      || type == QVariant::Time
      || type == QVariant::DateTime )
    {
        c = 't';
    }else
    if ( type == QVariant::ByteArray )
    {
         c = 'm';
    }else
    {

    }
    return c;
}

int TcDatabase::dbType(const QString& typeName)
{
    int ret = 0;
    if ( typeName.compare("MSSQL", Qt::CaseInsensitive) == 0
      || typeName.compare("SQLServer", Qt::CaseInsensitive) == 0
      || typeName.compare("SQL Server", Qt::CaseInsensitive) == 0 )
    {
        ret = SQLSERVER;
    }else
    if ( typeName.compare("MySQL", Qt::CaseInsensitive) == 0 )
    {
        ret = MYSQL;
    }else
    if ( typeName.compare("PostgreSQL", Qt::CaseInsensitive) == 0 )
    {
        ret = POSTGRESQL;
    }else
    if ( typeName.compare("SQLite", Qt::CaseInsensitive) == 0 )
    {
        ret = SQLTIE;
    }
    return ret;
}

TcParams TcDatabase::addParams(const QStringList& keys, const QList<QByteArray>& values)
{
    TcParams ret;
    if ( keys.count() == values.count() )
    {
        for( int i=0; i<keys.count(); i++ )
        {
            ret[keys.at(i).toLower()] = values.at(i);
        }
    }
    return ret;
}

QString TcDatabase::lastError()
{
    return m_lastError;
    //return errors.count() >0 ? errors.takeLast() : "";
}

void TcDatabase::setDatabase(int dbType,
                                      const QString& hostName, int hostPort,
                                      const QString& dbName, const QString& username, const QString& password)
{
    switch(dbType)
    {
    case SQLSERVER:
        m_dbType   = dbType;
        m_typeName = "SQL Server";
        m_hostName = hostName;
        m_hostPort = hostPort;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case MYSQL:
        m_dbType   = dbType;
        m_typeName = "MySQL";
        m_hostName = hostName;
        m_hostPort = hostPort;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case POSTGRESQL:
        m_dbType   = dbType;
        m_typeName = "PostgreSQL";
        m_hostName = hostName;
        m_hostPort = hostPort;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case SQLTIE:
        m_dbType   = dbType;
        m_typeName = "SQLite";
        m_hostName = hostName;
        m_hostPort = hostPort;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    default:
        m_dbType   =  0;
        m_typeName = "";
        m_hostName = "";
        m_hostPort =  0;
        m_dbName   = "";
        m_username = "";
        m_password = "";
        break;
    }
}

bool TcDatabase::setDatabase(const QString& typeName,
                                      const QString& hostName, int hostPort,
                                      const QString& dbName, const QString& username, const QString& password)
{
    bool ret = false;
    if ( typeName.compare("MSSQL", Qt::CaseInsensitive) == 0
      || typeName.compare("SQLServer", Qt::CaseInsensitive) == 0
      || typeName.compare("SQL Server", Qt::CaseInsensitive) == 0 )
    {
        m_dbType = SQLSERVER;
        m_typeName = "SQL Server";
    }else
    if ( typeName.compare("MySQL", Qt::CaseInsensitive) == 0 )
    {
        m_dbType = MYSQL;
        m_typeName = "MySQL";
    }else
    if ( typeName.compare("PostgreSQL", Qt::CaseInsensitive) == 0 )
    {
        m_dbType = POSTGRESQL;
        m_typeName = "PostgreSQL";
    }else
    if ( typeName.compare("SQLite", Qt::CaseInsensitive) == 0 )
    {
        m_dbType = SQLTIE;
        m_typeName = "SQLite";
    }else
    {
        m_dbType = 0;
    }
    if ( m_dbType >0 )
    {
        m_hostName = hostName;
        m_hostPort = hostPort;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;

        ret = true;
    }else
    {
        m_typeName = "";
        m_hostName = "";
        m_hostPort =  0;
        m_dbName   = "";
        m_username = "";
        m_password = "";
    }
    return ret;
}

void TcDatabase::setDatabase(int dbType,
                                      const QString& dbName, const QString& username, const QString& password)
{
    switch(dbType)
    {
    case SQLSERVER:
        m_dbType   = dbType;
        m_typeName = "SQL Server";
        m_hostName = "localhost";
        m_hostPort = 0;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case MYSQL:
        m_dbType   = dbType;
        m_typeName = "MySQL";
        m_hostName = "localhost";
        m_hostPort = 0;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case POSTGRESQL:
        m_dbType   = dbType;
        m_typeName = "PostgreSQL";
        m_hostName = "localhost";
        m_hostPort = 0;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    case SQLTIE:
        m_dbType   = dbType;
        m_typeName = "SQLite";
        m_hostName = "localhost";
        m_hostPort = 0;
        m_dbName   = dbName  ;
        m_username = username;
        m_password = password;
        break;
    default:
        m_dbType   =  0;
        m_typeName = "";
        m_hostName = "";
        m_hostPort =  0;
        m_dbName   = "";
        m_username = "";
        m_password = "";
        break;
    }
}

bool TcDatabase::setDatabase(const QString& typeName,
                                      const QString& dbName, const QString& username, const QString& password)
{
    return setDatabase(typeName, "", 0, dbName, username, password);
}

int TcDatabase::open()
{
    int ret = 0;
    close();
    switch(dbType())
    {
    case SQLSERVER:
        //QSqlDatabase::removeDatabase("FriendSafe");
        m_handle = QSqlDatabase::addDatabase("QODBC");
        {
            QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;").arg(hostName()).arg(dbName());
            m_handle.setDatabaseName(dsn);
            m_handle.setUserName(m_username);
            m_handle.setPassword(m_password);
        }
        ret = m_handle.open() ? 1 : 0;
        break;

    case MYSQL:
        //QSqlDatabase::removeDatabase("qt_sql_default_connection");
        m_handle = QSqlDatabase::addDatabase("QMYSQL");//, "qt_sql_default_connection");//, "allowMultiQueries=true");
        m_handle.setHostName(hostName());
        m_handle.setDatabaseName(dbName());
        m_handle.setUserName(m_username);
        m_handle.setPassword(m_password);
        //m_handle.setConnectOptions("allowMultiQueries=true");
        //m_handle.cloneDatabase()
        ret = m_handle.open() ? 1 : 0;
//DEBUG_OUT(m_handle.connectionName())
//DEBUG_OUT(m_handle.connectionNames().join("\n"))
        break;

    case POSTGRESQL:
        //QSqlDatabase::removeDatabase("");
        m_handle = QSqlDatabase::addDatabase("QPSQL");
        m_handle.setHostName(hostName());
        m_handle.setDatabaseName(dbName());
        m_handle.setUserName(m_username);
        m_handle.setPassword(m_password);
        //m_handle.setConnectOptions("allowMultiQueries=true");
        //m_handle.cloneDatabase()
        ret = m_handle.open() ? 1 : 0;
//DEBUG_OUT(m_handle.connectionName())
//DEBUG_OUT(m_handle.connectionNames().join("\n"))
        break;

    case SQLTIE:
        //QSqlDatabase::removeDatabase("FriendSafe");
        m_handle = QSqlDatabase::addDatabase("QSQLITE");

        QFileInfo dbFile(m_dbName);
        QDir dir(dbFile.absoluteDir());
        dir.mkpath(dbFile.absolutePath());
        m_handle.setDatabaseName(m_dbName);
        m_handle.setUserName(m_username);
        m_handle.setPassword(m_password);

        if ( m_handle.open() )
        {
            m_hostName = "localhost";
            m_hostPort = 0;
            QStringList tables = m_handle.tables();
            if ( tables.count() <= 0 )
            {
                // 没有任何表，这个库是新建的。
                QFile f(CreateDDL);
                if ( f.open(QFile::Text | QFile::ReadOnly) )
                {
                    QTextStream in(&f);
                    QString fileText = in.readAll();
                    f.close();

                    ret = 1;
                    QSqlQuery query = QSqlQuery(m_handle);
                    int pos;
                    while((pos=fileText.indexOf(";")) >-1)
                    {
                        QString sqlText = fileText.mid(0, pos).trimmed();
                        fileText.remove(0, pos+1);
                        fileText = fileText.trimmed();

                        QStringList sqlLines = sqlText.split("\n", QString::SkipEmptyParts);
                        QString sql;
                        for( int i=0;i<sqlLines.count();i++ )
                        {
                            QString s = sqlLines.at(i);
                            if ( ! s.startsWith("--") )
                            {
                                sql += s + "\n";
                            }
                        }
                        if ( ! sql.isEmpty() && ! query.exec(sql) )
                        {
                            ret = -1;
                        }
                    }
                    query.finish();
                }
            }else
            {
                ret = 1;
            }
        }
        break;
    }
    m_accepted = ret >0;
    return ret;
}

void TcDatabase::close()
{
    m_lastError = "";
    if ( m_handle.isOpen() )
    {
        m_handle.close();
    }
    m_engineFile = "";
}

void TcDatabase::loadEngine()
{
    loadEngine(m_engineFile);
}

void TcDatabase::loadEngine(const QString& filename)
{
    m_sqls.clear();
    if ( m_handle.isOpen() )
    {
        if ( dbType() == SQLSERVER )
        {
            // 取出存储过程名
            QSqlQuery procedures_query = QSqlQuery(m_handle);
            QSqlQuery query = QSqlQuery(m_handle);
            if ( procedures_query.exec("exec sp_procedures_rowset2") )
            {
                while(procedures_query.next())
                {
                    QSqlRecord procedures = procedures_query.record();
                    QSqlField  fieldSchema = procedures.field("PROCEDURE_SCHEMA");
                    if ( fieldSchema.isValid() && fieldSchema.value() != "sys" )
                    {
                        QSqlField  field = procedures.field("PROCEDURE_NAME");
                        if ( field.isValid() )
                        {
                            SQLContext cnt;
                            QString procedureID = field.value().toString().toLower();
                            int index = procedureID.indexOf(";");
                            if ( index >= 0 )
                            {
                                procedureID = procedureID.left(index);
                            }
                            cnt.id = procedureID;
                            QString paramsLine;
                            if ( query.exec("exec sp_procedure_params_rowset '"+procedureID+"'") )
                            {
                                while(query.next())
                                {
                                    QSqlRecord paramField = query.record();
                                    QSqlField  paramName = paramField.field("PARAMETER_NAME");
                                    QString pname = paramName.value().toString();

                                    if ( pname.compare("@RETURN_VALUE", Qt::CaseInsensitive) != 0 )
                                    {
                                        QSqlField  paramType = paramField.field("TYPE_NAME");
                                        pname.remove(0, 1);

                                        QString ptype = paramType.value().toString().toLower();
                                        if ( ptype == "nvarchar" )
                                        {
                                            ptype = "string";
                                        }

                                        cnt.params.insert(pname, ptype);
                                        paramsLine += ", :" + pname;
                                    }
                                }
                                query.finish();

                                if ( ! paramsLine.isEmpty() )
                                {
                                    paramsLine.remove(0, 2);
                                }
                            }
                            cnt.text = "exec " + procedureID + " " + paramsLine;
                            m_sqls[procedureID] = cnt;
                            Q_EMIT dbiLoading(m_sqls.count(), procedureID);
                        }
                    }
                }
                procedures_query.finish();
            }
        }else
        if ( dbType() == MYSQL )
        {
            // 取出存储过程名
            QString sql = "SELECT `name`, `param_list`, `body`, `returns` FROM `mysql`.`proc` WHERE `language` = 'SQL' AND `db` = '"+dbName()+"';";
            QSqlQuery query = QSqlQuery(m_handle);
            if ( query.exec(sql) )
            {
                QSqlField  field;
                while(query.next())
                {
                    QSqlRecord procedures = query.record();

                    QString param_line;

                    SQLContext cnt;
                    cnt.id     = procedures.field("name").value().toString();
                    cnt.params =  getParamList(param_line, procedures.field("param_list").value().toString());
                    cnt.text   = "call " + cnt.id + "(" + param_line + ");";
                    //cnt.text   = procedures.field("body").value().toString();
                    m_sqls[cnt.id] = cnt;
                    Q_EMIT dbiLoading(m_sqls.count(), cnt.id);
                    Q_EMIT dbiLoading(m_sqls.count(), cnt.text);
                }
                query.finish();
            }
        }else
        if ( dbType() == POSTGRESQL )
        {
            // 取出存储过程名
            QSqlQuery storedproc_query = QSqlQuery(m_handle);
            QSqlQuery query = QSqlQuery(m_handle);
            if ( storedproc_query.exec("SELECT specific_name"
                                           " , routine_name"
                                        " FROM information_schema.routines"
                                       " WHERE specific_schema = 'public'"
                                         " AND routine_schema  = 'public'"
                                         " AND routine_type    = 'FUNCTION';") )
            {
                while(storedproc_query.next())
                {
                    QSqlRecord storedprocs = storedproc_query.record();
                    QSqlField  fieldspecific = storedprocs.field("specific_name");
                    QSqlField  fieldsqlid    = storedprocs.field("routine_name" );
                    if ( fieldspecific.isValid() && fieldsqlid.isValid() )
                    {
                        SQLContext cnt;
                        cnt.id = fieldsqlid.value().toString().toLower();
                        QString paramsLine;
                        if ( query.exec("SELECT parameter_name"
                                            " , udt_name"
                                         " FROM information_schema.parameters"
                                        " WHERE specific_schema = 'public'"
                                          " AND specific_name   = '"+fieldspecific.value().toString()+"'"
                                          " AND parameter_mode   = 'IN'"
                                        " ORDER BY ordinal_position;") )
                        {
                            while(query.next())
                            {
                                QSqlRecord fields = query.record();
                                QSqlField  paramName = fields.field("parameter_name");
                                QSqlField  paramType = fields.field("udt_name"      );
                                if ( paramName.isValid() && paramType.isValid() )
                                {
                                    cnt.params.insert(paramName.value().toString(),
                                                      paramType.value().toString());
                                    paramsLine += ", :" + paramName.value().toString();
                                }
                            }
                            query.finish();

                            if ( ! paramsLine.isEmpty() )
                            {
                                paramsLine.remove(0, 2);
                            }
                        }
                        cnt.text = "SELECT * FROM " + cnt.id + "(" + paramsLine + ");";
                        m_sqls[cnt.id] = cnt;
                        Q_EMIT dbiLoading(m_sqls.count(), cnt.id);
                    }
                }
                storedproc_query.finish();
            }
        }
    }
    QStringList filenames;
    QDir dir(filename);
    if ( dir.exists() )
    {
        filenames = dir.entryList(QStringList(), QDir::Files, QDir::Name);
        for( int i=0; i<filenames.count(); i++ )
        {
            QString ddlfile = filenames.at(i);
            filenames[i] = dir.absolutePath() + QDir::separator() + ddlfile;
        }
    }else
    {
        QFileInfo sqlsInfo(filename);
        if ( sqlsInfo.exists() )
        {
            filenames.append(filename);
        }
    }
    foreach(QString ddlfile, filenames)
    {
        QFile f(ddlfile);
        if ( f.open(QFile::Text | QFile::ReadOnly) )
        {
            m_engineFile = ddlfile;

            QTextStream in(&f);

            int                     rdType = 0;
            QString                 sqlId;
            QString                 sqlText;
            QMultiHash<QString, QString> sqlParams;
            while(!in.atEnd())
            {
                QString line = in.readLine().trimmed();
                clearComment(line);
                if ( line.isEmpty() )
                {

                }else
                if ( line.startsWith("SQL:", Qt::CaseInsensitive) )
                {
                    if ( ! sqlId.isEmpty() && ! sqlText.isEmpty() )
                    {
                        sqlText.replace("@", ":");

                        SQLContext cnt;
                        cnt.id     = sqlId;
                        cnt.text   = sqlText;
                        cnt.params = sqlParams;
                        m_sqls[sqlId] = cnt;
                        Q_EMIT dbiLoading(m_sqls.count(), sqlId);
                    }
                    sqlId = line.mid(4).trimmed().toLower();
                    sqlText.clear();
                    sqlParams.clear();
                    rdType = 1;
                }else
                if ( line.startsWith("Params:", Qt::CaseInsensitive) )
                {
                    rdType = 2;
                }else
                if ( ! sqlId.isEmpty() )
                {
                    switch(rdType)
                    {
                    case 1:
                        sqlText += line + "\n";
                        break;
                    case 2:
                    {
                        QString paramName;
                        QString paramType = "string";
                        int pos;
                        if ( (pos=line.indexOf(" ")) >0 )
                        {
                            paramName = line.left(pos);
                            line = line.remove(0, pos).trimmed();
                            if ( (pos=line.indexOf(" ")) >0 )
                            {
                                paramType = line.left(pos);
                            }else
                            {
                                paramType = line;
                            }
                        }else
                        {
                            paramName = line;
                        }
                        QChar c = paramName.at(0);
                        if ( c == ':' || c == '@' )
                        {
                            paramName.remove(0, 1);
                        }
                        sqlParams.insert(paramName, paramType.toLower());
                        break;
                    }
                    }
                }
            }
            f.close();

            if ( ! sqlId.isEmpty() && ! sqlText.isEmpty() )
            {
                SQLContext cnt;
                cnt.id     = sqlId;
                cnt.text   = sqlText;
                cnt.params = sqlParams;
                m_sqls[sqlId] = cnt;
                Q_EMIT dbiLoading(m_sqls.count(), sqlId);
            }
        }
    }
}

QMultiHash<QString, QString> TcDatabase::getParamList(QString &param_line, QString param_list)
{
    QHash<QString, QString> ret;

    param_line = "";
    param_list = param_list.trimmed();
    while(! param_list.isEmpty())
    {
        QString paramName;
        int index = param_list.indexOf(" ");
        if ( index >0 )
        {
            paramName = param_list.left(index);
            param_list = param_list.remove(0, index).trimmed();
            if ( paramName.compare("OUT", Qt::CaseInsensitive)==0
              || paramName.compare("IN" , Qt::CaseInsensitive)==0 )
            {
                index = param_list.indexOf(" ");
                if ( index >0 )
                {
                    paramName = param_list.left(index);
                    param_list = param_list.remove(0, index).trimmed();
                }
            }
            if ( ! paramName.isEmpty() )
            {
                QString paramType;

                index = param_list.indexOf(",");
                if ( index >0 )
                {
                    paramType = param_list.left(index);
                    param_list = param_list.remove(0, index+1).trimmed();
                }else
                {
                    paramType = param_list;
                    param_list = "";
                }
                if ( ! paramType.isEmpty() )
                {
                    param_line += ", ?";//+ paramName;
                    ret.insert(paramName, paramType.toLower());
                }
            }
        }
    }
    if ( param_line.length() >= 2 )
    {
        param_line.remove(0, 2);
    }
    return ret;
}

void TcDatabase::clearComment(QString& s)
{
    int pos;
    if ( (pos = s.indexOf("#")) >=0 )
    {
        s = s.mid(0, pos);
    }
    if ( (pos = s.indexOf("--")) >=0 )
    {
        s = s.mid(0, pos);
    }
    if ( (pos = s.indexOf("//")) >=0 )
    {
        s = s.mid(0, pos);
    }
    s = s.trimmed();
}

QSqlQuery* TcDatabase::prepare(const QString& sqlID, TcParams prams,
                               int userNo, const QString& userID, const QString& username)
{
    QSqlQuery* ret = NULL;

    m_lastError = "";
    if ( m_handle.isOpen() && m_accepted )
    {
        QSqlQuery* query = new QSqlQuery(m_handle);
        if ( query != NULL )
        {
            QHash<QString, SQLContext>::const_iterator it = m_sqls.find(sqlID.toLower());
            if ( it != m_sqls.constEnd() && it.key() == sqlID.toLower() )
            {
                SQLContext sql = it.value();
                if ( query->prepare(sql.text) )
                {
//DEBUG_OUT(sqlID)
                    // SQL文中包括 ? 时，表示参数以序号赋值
                    bool NonName = sql.text.indexOf("?") >= 0;
                    int  ParamIndex = 0;
                    QStringList dbKeys = sql.params.keys();
                    foreach(QString dbKey, dbKeys)
                    {
                        QString dbType  = sql.params.value(dbKey);
//qDebug()<<prams.value(dbKey);
//DEBUG_OUT(dbKey + " = (" + dbType+"): "+prams.value(dbKey))
                        // 循环对照变量名，是为了确保大小写不统一时也能识别
                        QString strValue;
//                        bool    useString = false;
                        QByteArray dbValue;
                        if ( dbKey.compare("CreaterNo", Qt::CaseInsensitive)==0
                          || dbKey.compare("CreatorNo", Qt::CaseInsensitive)==0
                          || dbKey.compare("UpdaterNo", Qt::CaseInsensitive)==0 )
                        {
                            dbValue = QByteArray::number(userNo);
                        }else
                        if ( dbKey.compare("CreaterID", Qt::CaseInsensitive)==0
                          || dbKey.compare("CreatorID", Qt::CaseInsensitive)==0
                          || dbKey.compare("UpdaterID", Qt::CaseInsensitive)==0 )
                        {
                            //strValue = userID;
                            dbValue = userID.toUtf8();
                        }else
                        if ( dbKey.compare("Creater" , Qt::CaseInsensitive)==0
                          || dbKey.compare("Creator" , Qt::CaseInsensitive)==0
                          || dbKey.compare("Updater" , Qt::CaseInsensitive)==0 )
                        {
                            dbValue = username.toUtf8();
                        }else
                        {
                            dbValue = prams[dbKey.toLower()];
                        }

                        QString aKey = ':' + dbKey;
                        if ( dbType.compare("i", Qt::CaseInsensitive) == 0
                          || dbType.compare("int", Qt::CaseInsensitive) == 0
                          || dbType.compare("int4", Qt::CaseInsensitive) == 0 ) // PostgreSQL field type.
                        {
                            int value = dbValue.toInt();
                            if ( NonName )
                            {
                                query->bindValue(ParamIndex, value);
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
                                query->bindValue(aKey, value);
                            }
                        }else
                        if ( dbType.compare("n", Qt::CaseInsensitive) == 0
                          || dbType.compare("double", Qt::CaseInsensitive) == 0
                          || dbType.compare("number", Qt::CaseInsensitive) == 0 )
                        {
                            double value = dbValue.toDouble();
                            if ( NonName )
                            {
                                query->bindValue(ParamIndex, value);
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
                                query->bindValue(aKey, value);
                            }
                        }else
                        if ( dbType.compare("d", Qt::CaseInsensitive) == 0
                          || dbType.compare("date", Qt::CaseInsensitive) == 0
                          || dbType.compare("time", Qt::CaseInsensitive) == 0
                          || dbType.compare("time", Qt::CaseInsensitive) == 0
                          || dbType.compare("datetime", Qt::CaseInsensitive) == 0
                          || dbType.compare("timestamp", Qt::CaseInsensitive) == 0 )
                        {
                            QDateTime value = TcUtils::toDateTime(QString(dbValue));
                            if ( NonName )
                            {
                                if ( dbValue.isEmpty() )
                                {
                                    query->bindValue(ParamIndex, QVariant());
                                }else
                                {
                                    if ( this->dbType() == SQLTIE )
                                    {// SQLite 数据库的日期时间用String类型存储
                                        query->bindValue(ParamIndex, QString(dbValue));
                                    }else
                                    {
                                        query->bindValue(ParamIndex, value);
                                    }
                                }
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
                                if ( dbValue.isEmpty() )
                                {
                                    query->bindValue(aKey, QVariant());
                                }else
                                {
                                    if ( this->dbType() == SQLTIE )
                                    {// SQLite 数据库的日期时间用String类型存储
                                        query->bindValue(aKey, QString(dbValue));
                                    }else
                                    {
                                        query->bindValue(aKey, value);
                                    }
                                }
                            }
                        }else
                        if ( dbType.compare("b", Qt::CaseInsensitive) == 0
                          || dbType.compare("bool", Qt::CaseInsensitive) == 0
                          || dbType.compare("boolean", Qt::CaseInsensitive) == 0 )
                        {
                            bool value = dbValue.toInt() >0
                                          || QString(dbValue).compare("ok", Qt::CaseInsensitive)==0
                                          || QString(dbValue).compare("yes", Qt::CaseInsensitive)==0
                                          || QString(dbValue).compare("true", Qt::CaseInsensitive)==0;
                            if ( NonName )
                            {
                                query->bindValue(ParamIndex, value);
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
                                query->bindValue(aKey, value);
                            }
                        }else
                        if ( dbType.compare("s", Qt::CaseInsensitive) == 0
                          || dbType.compare("str", Qt::CaseInsensitive) == 0
                          || dbType.compare("text", Qt::CaseInsensitive) == 0
                          || dbType.compare("ntext", Qt::CaseInsensitive) == 0
                          || dbType.compare("string", Qt::CaseInsensitive) == 0 )
                        {
                            QString value = dbValue;
//DEBUG_OUT(aKey + " =>= " + value)
                            if ( NonName )
                            {
                                query->bindValue(ParamIndex, value);
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
//                                if ( dbKey.compare("UserID"   , Qt::CaseInsensitive)==0
//                                  || dbKey.compare("CreaterID", Qt::CaseInsensitive)==0
//                                  || dbKey.compare("CreatorID", Qt::CaseInsensitive)==0
//                                  || dbKey.compare("UpdaterID", Qt::CaseInsensitive)==0 )
//                                {
//                                    query->bindValue(aKey, userID);
//                                }else
//                                if ( dbKey.compare("Username", Qt::CaseInsensitive)==0
//                                  || dbKey.compare("Creater" , Qt::CaseInsensitive)==0
//                                  || dbKey.compare("Creator" , Qt::CaseInsensitive)==0
//                                  || dbKey.compare("Updater" , Qt::CaseInsensitive)==0 )
//                                {
//                                    query->bindValue(aKey, username);
//                                }else
//                                {
                                    query->bindValue(aKey, value);
//                                }
                            }
                        }else
                        {// 默认都是 bytes 型
                            if ( NonName )
                            {
                                query->bindValue(ParamIndex, dbValue);
                            }else
                            if ( aKey == ":RETURN_VALUE" )
                            {
                            }else
                            {
                                query->bindValue(aKey, dbValue);
                            }
                        }
                        ParamIndex++;
                    }
                    ret = query;
                    query = NULL;
                }else
                {
                    m_lastError = "SQL["+sqlID+"] prepare error:" + query->lastError().text();
                }
            }else
            {
                m_lastError = "SQL-ID not found: " + sqlID;
            }
            delete query;
        }else
        {
            m_lastError = "SQL-ID not found: " + sqlID;
        }
    }else
    {
        m_lastError = "database not open.";
    }
    return ret;
}

bool TcDatabase::exec(int& result,
                      const QString& sqlID, const TcParams &prams,
                      int userNo, const QString& userID, const QString& username)
{
    bool ret = false;
    QSqlQuery* query = prepare(sqlID, prams, userNo, userID, username);
    if ( query != NULL )
    {
        if ( query->exec() )
        {
            result = 0;
            if ( query->isSelect() )
            {
                if ( dbType() == POSTGRESQL
                  && query->size()==1 && query->record().count()==1
                  && query->record().field(0).name().compare(sqlID, Qt::CaseInsensitive)==0 )
                {
                    if ( query->next() )
                    {
                        result = query->record().field(0).value().toInt();
                    }
                }else
                {
                    while(query->next())
                    {
                        result ++;
                    }
                }
            }else
            {
                int res = query->lastInsertId().toInt();
                if ( res <= 0 )
                {
                    res = query->numRowsAffected();
                }
                result = res;
            }
            ret = true;
            m_lastError = query->lastError().text();
        }
        query->finish();
        delete query;
    }
    return ret;
}

bool TcDatabase::exec(QVariantList& list,
                      const QString& sqlID, const TcParams &prams,
                      int userNo, const QString& userID, const QString& username)
{
    bool ret = false;
    QSqlQuery* query = prepare(sqlID, prams, userNo, userID, username);
    if ( query != NULL )
    {
        if ( query->exec() )
        {
            if ( query->isSelect() )
            {
                while(query->next())
                {
                    QSqlRecord record = query->record();
                    QVariantMap map;
                    for( int i=0;i<record.count();i++ )
                    {
                        QSqlField field = record.field(i);
                        QString  k = field.name().toLower();
                        QVariant v = field.value();
                        map[k] = v;
                    }
                    list.append(map);
                }
            }
            ret = true;
        }else
        {
            m_lastError = query->lastError().text();
        }
        query->finish();
        delete query;
    }
    return ret;
}

int TcDatabase::exec(int& result, QVariantList& list, const QString& sqlID, const TcParams& params,
                              int userNo, const QString& userID , const QString& username)
{
    int ret = 0;
    QSqlQuery* query = prepare(sqlID, params, userNo, userID, username);
    if ( query != NULL )
    {
        if ( query->exec() )
        {
            result = 0;
            if ( query->isSelect() )
            {
                if ( dbType() == POSTGRESQL
                  && query->size()==1 && query->record().count()==1
                  && query->record().field(0).name().compare(sqlID, Qt::CaseInsensitive)==0 )
                {
                    if ( query->next() )
                    {
                        result = query->record().field(0).value().toInt();
                    }
                }else
                {
                    while(query->next())
                    {
                        QSqlRecord record = query->record();
                        QVariantMap map;
                        for( int i=0;i<record.count();i++ )
                        {
                            QSqlField field = record.field(i);
                            QString  k = field.name().toLower();
                            QVariant v = field.value();
                            map[k] = v;
                        }
                        list.append(map);
                    }
                    ret = 2;
                }
            }else
            {
                result = query->lastInsertId().toInt();
                if ( result <= 0 )
                {
                    result = query->numRowsAffected();
                }
                ret = 1;
            }
        }else
        {
            m_lastError = query->lastError().text();
            ret = -1;
        }
        query->finish();
        delete query;
    }
    return ret;
}

int TcDatabase::exec(int& result, QList<QByteArray>& list, const QString& sqlID, const TcParams& params,
                              int userNo, const QString& userID , const QString& username)
{
    int ret = 0;
    QSqlQuery* query = prepare(sqlID, params, userNo, userID, username);
    if ( query != NULL )
    {
        if ( query->exec() )
        {
            result = 0;
            if ( query->isSelect() )
            {
                list.clear();
                if ( dbType() == POSTGRESQL
                  && query->size()==1 && query->record().count()==1
                  && query->record().field(0).name().compare(sqlID, Qt::CaseInsensitive)==0 )
                {
                    if ( query->next() )
                    {
                        result = query->record().field(0).value().toInt();
                    }
                    ret = 1;
                }else
                {
                    while(query->next())
                    {
                        QSqlRecord record = query->record();
                        QByteArray fieldBytes;
                        for( int i=0;i<record.count();i++ )
                        {
                            QSqlField field = record.field(i);
                            QVariant value = field.value();
                            fieldBytes.append(TcUtils::addField(field.name(), field.value()));
                        }
                        list.append(fieldBytes);
                        result ++;
                    }
                    ret = 2;
                }
            }else
            {
                result = query->lastInsertId().toInt();
                if ( result <= 0 )
                {
                    result = query->numRowsAffected();
                }
                ret = 1;
            }
        }else
        {
            m_lastError = query->lastError().text();
            ret = -1;
        }
        query->finish();
        delete query;
    }
    return ret;
}
