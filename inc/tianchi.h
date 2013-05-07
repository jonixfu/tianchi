// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵�������õ�Ԫͷ�ļ�
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.16   ʥ������    ����
// ====================================================================================================================
/// @file tianchi.h ���õ�Ԫͷ�ļ�
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

// ����Ϊ�ؼ�
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


// ����Ϊ�ؼ�
typedef ::TcClickLabel          ClickLabel;
typedef ::TcDateEdit            DateEdit;
typedef ::TcHeaderSetupDialog   HeaderSetupDialog;
typedef ::TcMarqueeLabel        MarqueeLabel;

}

#endif // TIANCHI_H
