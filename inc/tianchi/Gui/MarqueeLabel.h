// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：跑马灯Label, 点击时自动打开网址
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.18   XChinux     建立
//
// ==========================================================================
/// @file MarqueeLabel.h 跑马灯Label,点击时自动打开网址
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

/// @brief 跑马灯类MarqueeLabel,点击时自动打开网址
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
