// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵������ر�׼���弯
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.11   cnhemiya    ����
// 2013.04.17   XChinux     ����Qt/qglobal.h�ļ���дGlobal.h
// ====================================================================================================================
// ʹ��˵��:
// 1. �������� tianchi.dll ʱ���� .pro �����ӣ�
//     DEFINES += TIANCHI_EXPORT
// ====================================================================================================================
/// @file Global.h ��ر�׼���弯
#ifndef TIANCHI_GLOBAL_H
#define TIANCHI_GLOBAL_H

#include <QtGlobal>

/// @brief ����ع���Դ��⡷�ķ����汾��
#define TIANCHI_VERSION 0x000001

/// @brief ��ǰ׺��������
#if defined(TIANCHI_EXPORT)
#   define TIANCHI_API Q_DECL_EXPORT
#elif defined(TIANCHI_IMPORT)
#   define TIANCHI_API Q_DECL_IMPORT
#else
#   define TIANCHI_API
#endif

#endif // TIANCHI_GLOBAL_H