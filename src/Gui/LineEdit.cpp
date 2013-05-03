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
// 2013.04.22   XChinux     ����
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
