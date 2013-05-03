// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：可发出clicked信号的Label部件
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.22   XChinux     建立
//
// ==========================================================================
/// @file LineEdit.cpp extended QLineEdit widget
// ==========================================================================
#include "tianchi/Gui/LineEdit.h"

#include <QPainter>
#include <QContextMenuEvent>
#include <QStyleOptionFrame>

class TcLineEditPrivate
{
    Q_DECLARE_PUBLIC(TcLineEdit)
public:
    explicit TcLineEditPrivate(TcLineEdit *qptr);
    ~TcLineEditPrivate();
    TcLineEdit *q_ptr;
    QString labelText;
    QVariant userData;
};

TcLineEditPrivate::TcLineEditPrivate(TcLineEdit *qptr) : q_ptr(qptr)
{
}

TcLineEditPrivate::~TcLineEditPrivate()
{
}

TcLineEdit::TcLineEdit(QWidget * parent)
    : QLineEdit(parent), d_ptr(new TcLineEditPrivate(this))
{
}

TcLineEdit::~TcLineEdit()
{
    delete d_ptr;
}

QString TcLineEdit::labelText() const
{
    Q_D(const TcLineEdit);
    return d->labelText;
}

QVariant TcLineEdit::data() const
{
    Q_D(const TcLineEdit);
    return d->userData;
}

void TcLineEdit::setLabelText(const QString &labelText)
{
    Q_D(TcLineEdit);
    if (d->labelText == labelText)
    {
        return;
    }
    d->labelText = labelText;
    update();
    emit labelTextChanged(labelText);
}

void TcLineEdit::setData(const QVariant &userData)
{
    Q_D(TcLineEdit);
    if (d->userData == userData)
    {
        return;
    }
    d->userData = userData;
    emit dataChanged(userData);
}

void TcLineEdit::paintEvent(QPaintEvent *event)
{
    if (hasFocus() && !isReadOnly() && isEnabled())
    {
        QLineEdit::paintEvent(event);
    }
    else
    {
        QPainter p(this);
        QRect r = rect();
        QPalette pal = palette();

        QStyleOptionFrameV2 panel;
        initStyleOption(&panel);
        style()->drawPrimitive(QStyle::PE_PanelButtonBevel, &panel, &p, this);
        r = style()->subElementRect(QStyle::SE_LineEditContents, &panel, this);

        QPen oldpen = p.pen();
        p.setPen(QColor(Qt::darkBlue));

        QFontMetrics fm = fontMetrics();

        Q_D(TcLineEdit);
        QString elidedText = fm.elidedText(d->labelText,
                Qt::ElideRight, r.width());
        p.drawText(r, Qt::AlignLeft | Qt::AlignVCenter, elidedText);
        p.setPen(oldpen);
    }
}

void TcLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    QLineEdit::mouseDoubleClickEvent(event);
    emit doubleClicked();
}

void TcLineEdit::contextMenuEvent(QContextMenuEvent *event)
{
    if (hasFocus() && !isReadOnly() && isEnabled())
    {
        QLineEdit::contextMenuEvent(event);
    }
    else
    {
        event->ignore();
    }
}
