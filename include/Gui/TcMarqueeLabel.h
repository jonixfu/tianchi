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
/// @file TcMarqueeLabel.h 跑马灯Label,点击时自动打开网址
// ==========================================================================
#ifndef TIANCHI_MARQUEELABEL_H
#define TIANCHI_MARQUEELABEL_H

#include "TcGlobal.h"

#include <QLabel>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class TcMarqueeLabelPrivate;
/// @brief 跑马灯类MarqueeLabel,点击时自动打开网址
/// @author XChinux XChinux@163.com
/// @date 2013-04-18
class TIANCHI_API TcMarqueeLabel : public QLabel
{
    Q_OBJECT

    Q_ENUMS(Direction)

    // @brief   设置文字滚动方向
    Q_PROPERTY(Direction direction
            READ direction
            WRITE setDirection
            NOTIFY directionChanged
            DESIGNABLE true)

    /// @brief  设置每移动一像素所需时间(毫秒)
    Q_PROPERTY(int interval 
            READ interval 
            WRITE setInterval
            NOTIFY intervalChanged
            DESIGNABLE true)

    /// @brief  设置是否启动移动状态
    Q_PROPERTY(bool active
            READ isActive
            WRITE setActive
            NOTIFY activeChanged
            DESIGNABLE true)

    Q_PROPERTY(Qt::Alignment alignment 
            READ alignment 
            WRITE setAlignment
            DESIGNABLE true)
public:
    TcMarqueeLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);
    TcMarqueeLabel(const QString &text, QWidget *parent = 0, 
            Qt::WindowFlags f = 0);
    virtual ~TcMarqueeLabel();
    /// @brief  返回interval
    int interval() const;
    /// @brief  返回当前状态
    bool isActive() const;

    enum Direction
    {
        RightToLeft = 0,
        BottomToTop = 1 
    };

    Direction direction() const;
    void setAlignment(Qt::Alignment align);
Q_SIGNALS:
    /// @brief  interval属性变化时发出此信号
    void intervalChanged(int interval);
    /// @brief  active属性变化时发出此信号
    void activeChanged(bool active);
    /// @brief  direction属性变化时发出错信号
    void directionChanged(Direction direction);
public Q_SLOTS:
    /// @brief  停止移动并且复位位置为0
    /// @see    stop()
    void reset();
    /// @brief  设置运行状态
    /// @see    start(), stop()
    void setActive(bool active);
    /// @brief  设置每移动一像素所需时间
    /// @see    interval()
    void setInterval(int msec);
    /// @brief  启动运行
    /// @ses    setActive(bool active), stop()
    void start();
    /// @brief  停止运行
    /// @see    setActive(bool active), start()
    void stop();
    /// @brief  设置移动方向
    /// @see    direction(), directionChagned(Direction direction)
    void setDirection(Direction direciton);
protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    virtual void paintEvent(QPaintEvent *event);
private:
    Q_DISABLE_COPY(TcMarqueeLabel)
    Q_DECLARE_PRIVATE(TcMarqueeLabel)
    Q_PRIVATE_SLOT(d_func(), void _q_openLink(const QString &))
    TcMarqueeLabelPrivate* const d_ptr;
};

#endif
