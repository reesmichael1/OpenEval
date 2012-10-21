#include <QtGui>
#include "FindEmployee.h"

FindEmployee::FindEmployee(QDialog * parent)
    : QDialog(parent)
{
    QLabel *employeeNameLabel = new QLabel(tr("Employee Name"));
    employeeName = new QLineEdit;
    employeeName->setMinimumWidth(300);

    findEmployeeButton = new QPushButton(tr("Find Employee"));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(employeeNameLabel);
    mainLayout->addWidget(employeeName);
    mainLayout->addWidget(findEmployeeButton);

    setLayout(mainLayout);

}
