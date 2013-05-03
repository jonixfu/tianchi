// **************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// **************************************************************************
// �ĵ�˵���������Label, ���ʱ�Զ�����ַ
// ==========================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------
// 2013.04.18   XChinux     ����
//
// ==========================================================================
/// @file MarqueeLabel.h �����Label,���ʱ�Զ�����ַ
// ==========================================================================
#ifndef TIANCHI_MARQUEELABEL_H
#define TIANCHI_MARQUEELABEL_H

#include "tianchi/Global.h"

#include <QLabel>
#include <QPropertyAnimation>

class QT_PREPEND_NAMESPACE(QResizeEvent);
class TcMarqueeLabel;
class TcMarqueeLabelPrivate
{
    Q_DECLARE_PUBLIC(TcMarqueeLabel)

public:
    explicit TcMarqueeLabelPrivate(TcMarqueeLabel *qptr);
    ~TcMarqueeLabelPrivate();

    void _q_openLink(const QString &url);

    QPropertyAnimation *animation;
    TcMarqueeLabel *q_ptr;
};

/// @brief �������MarqueeLabel,���ʱ�Զ�����ַ
/// @author XChinux XChinux@163.com
/// @date 2013-04-18
class TIANCHI_API TcMarqueeLabel : public QLabel
{
    Q_OBJECT
public:
    TcMarqueeLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);
    TcMarqueeLabel(const QString &text, QWidget *parent = 0,
            Qt::WindowFlags f = 0);
    virtual ~TcMarqueeLabel();

public Q_SLOTS:
    void setText(const QString &text);

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void enterEvent(QEvent *event);

private:
    Q_DISABLE_COPY(TcMarqueeLabel)
    Q_DECLARE_PRIVATE(TcMarqueeLabel)
    Q_PRIVATE_SLOT(d_func(), void _q_openLink(const QString &))
    TcMarqueeLabelPrivate* d_ptr;

};

#endif
