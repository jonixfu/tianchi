#ifndef TIANCHI_FORMUTILS_H
#define TIANCHI_FORMUTILS_H

#include "tianchi/Global.h"

#include <QWidget>

class TIANCHI_API TcFormUtils
{
public:
    TcFormUtils();

    inline QWidget* parentForm() const { return m_parentForm; }
    inline void     setParentForm(QWidget* value) { m_parentForm = value; }
private:
    QWidget*    m_parentForm;
};

#endif // TIANCHI_FORMUTILS_H
