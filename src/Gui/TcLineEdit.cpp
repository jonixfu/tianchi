#include "Gui/TcLineEdit.h"

#include <QPainter>
#include <QContextMenuEvent>
#include <QStyleOptionFrame>

class TcLineEditPrivate
{
    Q_DECLARE_PUBLIC(TcLineEdit)
public:
    explicit TcLineEditPrivate(TcLineEdit *qptr);
    ~TcLineEditPrivate();

    /**
     * when editingFinsihed emitted, if text property is empty, then 
     * clear labelText and data property
     */
    void _q_editingFinished();
    TcLineEdit* const q_ptr;

    QString labelText;
    QVariant userData;
};

TcLineEditPrivate::TcLineEditPrivate(TcLineEdit *qptr) : q_ptr(qptr)
{
    QObject::connect(q_ptr, SIGNAL(editingFinished()),
            q_ptr, SLOT(_q_editingFinished()));
}

TcLineEditPrivate::~TcLineEditPrivate()
{
}

void TcLineEditPrivate::_q_editingFinished()
{
    Q_Q(TcLineEdit);
    if (q->text().isEmpty())
    {
        q->setData(QVariant());
        q->setLabelText(QString());
    }
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
    Q_EMIT labelTextChanged(labelText);
}

void TcLineEdit::setData(const QVariant &userData)
{
    Q_D(TcLineEdit);
    if (d->userData == userData)
    {
        return;
    }
    d->userData = userData;
    Q_EMIT dataChanged(userData);
}

void TcLineEdit::clear()
{
    QLineEdit::clear();
    setLabelText(QString());
    setData(QVariant());
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
    Q_EMIT doubleClicked();
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

#include "moc_TcLineEdit.cpp"
