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
//
// ====================================================================================================================
// ʹ��˵��:
// 1. �������� tianchi.dll ʱ���� .pro ����ӣ�
//     DEFINES += TIANCHI_EXPORT
// ====================================================================================================================
#ifndef TIANCHI_GLOBAL_H
#define TIANCHI_GLOBAL_H

#include <QtGlobal>

#define TIANCHI_VERSION 0x000002

#if defined(TIANCHI_EXPORT)
#   define TIANCHI_API Q_DECL_EXPORT
#elif defined(TIANCHI_IMPORT)
#   define TIANCHI_API Q_DECL_IMPORT
#else
#   define TIANCHI_API
#endif

// ���ֿռ䣬������ֿռ��г�ͻ�޸� Tianchi �Ϳ���
#ifndef TIANCHI_NAMESPACE
#   define TIANCHI_NAMESPACE Tianchi
#   define TIANCHI_BEGIN_NAMESPACE namespace TIANCHI_NAMESPACE {
#   define TIANCHI_END_NAMESPACE } // namespace TIANCHI_NAMESPACE
#endif

#endif // TIANCHI_GLOBAL_H
