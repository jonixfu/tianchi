// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// ********************************************************************************************************************
// 文档说明：引用单元头文件
// ====================================================================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.16   圣域天子    建立
// ====================================================================================================================
/// @file tianchi.h 引用单元头文件
#ifndef TIANCHI_H
#define TIANCHI_H

#include "tianchi/Chinese/Chinese.h"

#include "tianchi/Core/Classes.h"
#include "tianchi/Core/Common.h"
#include "tianchi/Core/String.h"
#include "tianchi/Core/Utils.h"

#include "tianchi/File/Directory.h"
#include "tianchi/File/File.h"
#include "tianchi/File/Json.h"
#include "tianchi/File/Log.h"
#include "tianchi/File/MSExcel.h"

#include "tianchi/Gui/FormUtils.h"
#include "tianchi/Gui/GuiUtils.h"

#include "tianchi/Network/Udp.h"
#include "tianchi/Network/DownloadHttp.h"
#include "tianchi/Network/SingleInstance.h"

#include "tianchi/OS/OS.h"

#include "tianchi/Sql/DataAccess.h"
#include "tianchi/Sql/Database.h"
#include "tianchi/Sql/MSSQL.h"

#include "tianchi/Widget/TreeEx.h"

// 以下为控件
#include "tianchi/Gui/ClickLabel.h"
#include "tianchi/Gui/DateEdit.h"
#include "tianchi/Gui/HeaderSetupDialog.h"
#include "tianchi/Gui/MarqueeLabel.h"

namespace Tianchi
{
typedef ::TcChinese             Chinese;

typedef ::TcPlayer              Player;
typedef ::TcInvoke              Invoke;
typedef ::TcDBFields            DBFields;
typedef ::TcString              String;
typedef ::TcStringList          StringList;

typedef ::TcUtils               Utils;

typedef ::TcDirectory           Directory;

typedef ::TcFile                File;
typedef ::TcJSONObject          JSONObject;
typedef ::TcLog                 Log;
typedef ::TcMSExcel             MSExcel;

typedef ::TcFormUtils           FormUtils;

typedef ::TcCursorCustom        CursorCustom;
typedef ::TcCursorWait          CursorWait;
typedef ::TcCursorBusy          CursorBusy;

typedef ::TcDownload            Download;
typedef ::TcDownloadList        DownloadList;
typedef ::TcSingleInstance      SingleInstance;
typedef ::TcUdp                 Udp;

typedef ::TcOS                  OS;

typedef ::TcDatabase            Database;
typedef ::TcMSSQL               MSSQL;

typedef ::TcTreeEx              TreeEx;
typedef ::TcTreeItem            TreeItem;


// 以下为控件
typedef ::TcClickLabel          ClickLabel;
typedef ::TcDateEdit            DateEdit;
typedef ::TcHeaderSetupDialog   HeaderSetupDialog;
typedef ::TcMarqueeLabel        MarqueeLabel;

}

#endif // TIANCHI_H
