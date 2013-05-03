#ifndef TIANCHI_FORMUTILS_H
#define TIANCHI_FORMUTILS_H

#include <QWidget>

class TcFormUtils
{
public:
    TcFormUtils();

    inline QWidget* parentForm() const { return m_parentForm; }
    inline void     setParentForm(QWidget* value) { m_parentForm = value; }
private:
    QWidget*    m_parentForm;
};

#endif // TIANCHI_FORMUTILS_H
