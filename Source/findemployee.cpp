#include <QtGui>
#include "FindEmployee.h"

FindEmployee::FindEmployee(QDialog * parent)
    : QDialog(parent)
{
    QLabel *employeeNameLabel = new QLabel(tr("Employee Name"));
    employeeName = new QLineEdit;
    employeeName->setMinimumWidth(300);

    findEmployeeButton = new QPushButton(tr("Find Employee"));
    connect(findEmployeeButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(findEmployeeButton, SIGNAL(clicked()), this, SLOT(findEmployee()));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(employeeNameLabel);
    mainLayout->addWidget(employeeName);
    mainLayout->addWidget(findEmployeeButton);

    setLayout(mainLayout);

}

void FindEmployee::findEmployee()
{
    QFile employeeDataFile(EMPLOYEEFILE);
    QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);
    QString employeeDataString;

    for (int i = 0; i < employeeIDVector.size(); i++)
    {
        employeeDataString = returnDataString(&employeeDataFile, employeeIDVector.at(i), 0);
        if (employeeDataString.contains(employeeName->text()))
        {
            QStringList employeeDataList = employeeDataString.split(',');
            *currentEmployeeID = employeeDataList.at(0).toInt();
        }
    }

}

void FindEmployee::setEmployeeID(int *employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}
