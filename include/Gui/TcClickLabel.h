// **************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// **************************************************************************
// �ĵ�˵�����ɷ���clicked�źŵ�Label����
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.04.17   XChinux     ����
//
// ==========================================================================
/// @file TcClickLabel.h �ɷ���clicked�źŵ�Label����
// ==========================================================================
#ifndef TIANCHI_CLICKLABEL_H
#define TIANCHI_CLICKLABEL_H

#include "TcGlobal.h"

#include <QLabel>

class TcClickLabelPrivate;

/// @brief �ɷ���clicked�źŵ�Label����
class TIANCHI_API TcClickLabel : public QLabel
{
    Q_OBJECT
public:
    TcClickLabel(QWidget *parent = 0, Qt::WindowFlags f = 0);
    TcClickLabel(const QString &text, QWidget *parent = 0,
            Qt::WindowFlags f = 0);
    virtual ~TcClickLabel();
Q_SIGNALS:
    /// @brief �������ʱ����clicked�ź�
    void clicked();

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    Q_DISABLE_COPY(TcClickLabel)
    Q_DECLARE_PRIVATE(TcClickLabel)
    TcClickLabelPrivate* const d_ptr;
};

#endif
