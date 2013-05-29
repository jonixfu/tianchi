// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵����������Ԫ���˵�Ԫ��ʹ�� namespace Tianchi
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.15   ʥ������    ����
//
// ====================================================================================================================
/// @file TcCommon.h ������Ԫ���˵�Ԫ��ʹ�� namespace Tianchi
#ifndef TIANCHI_COMMON_H
#define TIANCHI_COMMON_H

#include "TcGlobal.h"

#include <QTextCodec>
#include <QDateTime>

#ifdef QT_WIDGETS_LIB
    #include <QMessageBox>
#endif

#include <iostream>
using namespace std;

QString GBK(const char* s);
QString UTF8(const char* s);

/// @brief �����ַ�����ʹ�ú���ǰӦ��Ϊ "GBK"
/// @param [in] name �ַ�������
/// @par ʾ��:
/// @code
/// int main(int argc, char *argv[])
/// {
///     QApplication app(argc, argv);
///     // ��ΪӦ�ó��������ַ���
///     initQS("GBK");
///
///     ...
/// }
/// void MyFunction()
/// {
///
///     qDebug()<<QS("��ʾΪ���֣����������룡");
///
/// }
/// @endcode
/// @return ȫ���ַ�������
/// @author ʥ������ Jonix@qtcn.org
/// @date 2013-05-06
QTextCodec* initQS(const QByteArray& name="GBK");

/// @brief �����ַ���ת��
/// @param [in] s ���ֳ������� char* �͵ı���
/// @par ʾ��:
/// @code
/// int main(int argc, char *argv[])
/// {
///     QApplication app(argc, argv);
///     // ��ΪӦ�ó��������ַ���
///     initQS("GBK");
///
///     ...
/// }
/// void MyFunction()
/// {
///
///     qDebug()<<QS("��ʾΪ���֣����������룡");
///
/// }
/// @endcode
/// @return ת����ĺ����ַ�������
/// @author ʥ������ Jonix@qtcn.org
/// @date 2013-04-15
inline QString QS(const char* s)
{
    return QTextCodec::codecForLocale()->toUnicode(s);
}

/// @brief �� Unicode(�����ַ���)ת�����ַ���
inline QByteArray SQ(const QString& s)
{
    return QTextCodec::codecForLocale()->fromUnicode(s);
}

/// @brief ȡ���ֵ
#define max(a,b)    (((a) > (b)) ? (a) : (b))
/// @brief ȡ��Сֵ
#define min(a,b)    (((a) < (b)) ? (a) : (b))
/// @brief ��֧�߼��ж�
inline int     iif(bool logic, int v1, int v2=0) { return logic ? v1 : v2; }
/// @brief ��֧�߼��ж�
inline QString iif(bool logic, const QString& v1, const QString& v2="") { return logic ? v1 : v2; }

#ifdef QT_WIDGETS_LIB
/// @brief ��ʾ�ı��Ի���
/// @param [in] ��ʾ������
/// @see class QMessageBox
inline void MsgBox(const QString& s)
{
    QMessageBox::information(NULL, "", s);
}
#endif

#define TC_FREE(x)  {delete x; x=NULL;}

/// @brief ������Ϣ������ʾ��
/// @param [in] file Դ�ļ���
/// @param [in] line ��λ��
/// @param [in] text ��ʾ�ı�����
inline void print_out(const char* file, int line, const QString& text="")
{
    cout<<QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss->").toLocal8Bit().data()<<file<<"("<<line<<"): "<<text.toLocal8Bit().data()<<endl;
}
//    inline void debug_out(const char* file, int line, const QByteArray& text="")
//    {
//        cout<<QDateTime::currentDateTime().toString("yyyy/MM/dd HH:mm:ss->").toLocal8Bit().data()<<file<<"("<<line<<"): "<<text.data()<<endl;
//    }
/// @brief ������Ϣ������ʾ��
/// @param [in] file Դ�ļ���
/// @param [in] line ��λ��
/// @param [in] value ��ʾ��ֵ
inline void print_out(const char* file, int line, int value)
{
    print_out(file, line, QString::number(value));
}

#if defined(QT_DEBUG)
    /// @brief Ϊ�˷�������ʱ������ʾ��ǰ�ļ����кţ���������ʱ����ִ�в��衣
    #define DEBUG_STEP    print_out(__FILE__, __LINE__);
    /// @brief Ϊ�˷�������ʱ�������õĺ�
    #define DEBUG_OUT(x)  print_out(__FILE__, __LINE__, x);
#else
    /// @brief Ϊ�˷�������ʱ������ʾ��ǰ�ļ����кţ���������ʱ����ִ�в��衣
    #define DEBUG_STEP
    /// @brief Ϊ�˷�������ʱ�������õĺ�
    #define DEBUG_OUT(x)
#endif

/// @brief Ϊ�˷�������ʱ������ʾ��ǰ�ļ����кţ���������ʱ����ִ�в��衣
#define SHOW_STEP    print_out(__FILE__, __LINE__);
/// @brief Ϊ�˷�������ʱ�������õĺ�
#define SHOW_OUT(x)  print_out(__FILE__, __LINE__, x);


/// @brief Ϊ�˷�������ʱ������ʾ��ǰ�ļ����кţ���������ʱ����ִ�в��衣
#define HERE_STEP       print_out(__FILE__, __LINE__);
/// @brief Ϊ�˷�������ʱ�������õĺ�
#define HERE_SHOW(x)    print_out(__FILE__, __LINE__, x);

/// @brief ���������ַ�����yyyy-MM-dd
QString YYYY_MM_DD(QDate date);
/// @brief ���������ַ�����yyyy-MM-dd
QString YYYY_MM_DD(QDateTime datetime);
/// @brief ��������ʱ���ַ�����yyyy-MM-dd HH:mm:ss
QString YYYY_MM_DD_HH_MM_SS(QDateTime datetime);
/// @brief ��������ʱ���ַ�����yyyy-MM-dd HH:mm:ss.zzz
QString YYYY_MM_DD_HH_MM_SS_ZZZ(QDateTime datetime);

#endif // TIANCHI_COMMON_H
