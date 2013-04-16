// ********************************************************************************************************************
// Tianchi share library for Qt (C++)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵�������ù��ܺ���
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.11   cnhemiya    ����

// ====================================================================================================================
#ifndef TIANCHI_GLOBAL_H
#define TIANCHI_GLOBAL_H

#include <QtGlobal>

// ���� dll ʱ���� .pro ����ӣ�
// DEFINES += TIANCHI_EXPORT

// ���� exe ������ dll ʱ���� .pro ����ӣ�
// DEFINES += TIANCHI_IMPORT

// ֱ������Դ�����ʱ����Ҫ���� TIANCHI_EXPORT �� TIANCHI_IMPORT
// DEFINES -= TIANCHI_EXPORT
// DEFINES -= TIANCHI_IMPORT

#if defined(TIANCHI_EXPORT)
#   define TIANCHI_API Q_DECL_EXPORT
#elif defined(TIANCHI_IMPORT)
#   define TIANCHI_API Q_DECL_IMPORT
#else
#   define TIANCHI_API
#endif

#ifndef TIANCHI_VERSION
#   define TIANCHI_VERSION 0x000002
#endif

// ���ֿռ䣬������ֿռ��г�ͻ�޸� Tianchi �Ϳ���
#ifndef TIANCHI_NAMESPACE
#   define TIANCHI_NAMESPACE Tianchi
#   define TIANCHI_BEGIN_NAMESPACE namespace TIANCHI_NAMESPACE {
#   define TIANCHI_END_NAMESPACE } // namespace TIANCHI_NAMESPACE
#endif

// ���ò���ϵͳԤ����
// Q_OS_WIN
// Q_OS_WIN32
// Q_OS_WIN64
// Q_OS_WINCE

// Q_OS_LINUX

// Q_OS_MAC

// ���ñ�����Ԥ����
// _MSC_VER
// __GNUC__
// __BORLANDC__

// ����
//#ifndef TC_TYPE_DEFINE
//#   define TC_TYPE_DEFINE
//typedef tcint8      char;
//typedef tcint16     short;
//typedef tcint32     long;
//typedef tcint64     long long;
//typedef tcuint8     unsigned char;
//typedef tcuint16    unsigned short;
//typedef tcuint32    unsigned long;
//typedef tcuint64    unsigned long long;
//#endif

#endif // TIANCHI_GLOBAL_H
