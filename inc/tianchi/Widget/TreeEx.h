// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵����QTreeWidget �ؼ���չ
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.05.03   ʥ������    ����
//
// ====================================================================================================================
/// @file TreeEx.h QTreeWidget �ؼ���չ
// ====================================================================================================================
#ifndef TIANCHI_TREEEX_H
#define TIANCHI_TREEEX_H

#include "tianchi/Global.h"
#include "tianchi/File/MSExcel.h"

#include <QTreeWidget>

class TcTreeExPrivate;

/// @brief �� QTreeWidget ����չ���ܣ���ֱ�ӵ����� Excel ��
/// @author ʥ������ Jonix@qtcn.org
class TIANCHI_API TcTreeEx
{
public:
    enum ExportType
    {
        TextFile = 1
      , MSExcel  = 2
    };
    /// @brief ���캯��
    /// @param [in] view ��Ҫ������ QTreeWidget ����
    TcTreeEx(QTreeWidget* widget=0);

    /// @brief ���õ���ģʽ
    /// @param [in] widget ��Ҫ������ QTreeWidget ����
    void setWidget(QTreeWidget* widget);

    /// @brief ���õ���ģʽ
    /// @param [in] type ��Ҫ����������(enum ExportType)
    void setExportType(int type);

    /// @brief ���õ���ģʽ
    /// @param [in] state 0 ȫ��, 1 ѡ��
    void setSelectedState(int state);

    /// @brief ���õ������ı��ļ���
    /// @param [in] filename �������ı��ļ���
    void setTextFileName(const QString& filename);

    /// @brief ���� Excel �Ķ���ʵ��<br>
    /// ʹ�ô˷����󵼳�ģʽ�Զ�����Ϊ MSExcel
    void setMSExcelObject(TcMSExcel* excel, bool hasHeader=true, int startRow=1, int startCol=1);

    /// @brief ִ�е�������
    int  save();

private:
    Q_DISABLE_COPY(TcTreeEx)
    Q_DECLARE_PRIVATE(TcTreeEx)
    TcTreeExPrivate*   d_ptr;
};

namespace Tianchi
{
    typedef ::TcTreeEx TreeEx;
}


#endif // TIANCHI_TREEEX_H
