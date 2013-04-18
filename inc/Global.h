// ********************************************************************************************************************
// Tianchi share library for Qt (C++)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// ********************************************************************************************************************
// 文档说明：常用功能函数
// ====================================================================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.11   cnhemiya    建立
//
// ====================================================================================================================
// 使用说明:
// 1. 编译生成 tianchi.dll 时请在 .pro 中添加：
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

// 名字空间，如果名字空间有冲突修改 Tianchi 就可以
#ifndef TIANCHI_NAMESPACE
#   define TIANCHI_NAMESPACE Tianchi
#   define TIANCHI_BEGIN_NAMESPACE namespace TIANCHI_NAMESPACE {
#   define TIANCHI_END_NAMESPACE } // namespace TIANCHI_NAMESPACE
#endif

#endif // TIANCHI_GLOBAL_H
