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

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(hide()));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(employeeNameLabel);
    mainLayout->addWidget(employeeName);
    mainLayout->addWidget(findEmployeeButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);
    setWindowTitle(tr("Find Employee"));
}

void FindEmployee::findEmployee()
{
    bool employeeFound = false;
    QFile employeeDataFile(EMPLOYEEFILE);
    QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);
    QString employeeDataString;

    for (int i = 0; i < employeeIDVector.size(); i++)
    {
        employeeDataString = returnDataString(&employeeDataFile, employeeIDVector.at(i), 0);
        if (employeeDataString.contains(employeeName->text()))
        {
            QStringList employeeDataList = employeeDataString.split("\",\"");
            *currentEmployeeID = employeeDataList.at(0).toInt();
            employeeFound = true;
        }
    }

    if (!employeeFound)
    {
        QMessageBox employeeNotFoundBox;
        employeeNotFoundBox.setText(tr("Sorry, %1 is not an employee of this employer.")
            .arg(employeeName->text()));
        employeeNotFoundBox.setWindowTitle(tr("Employee Not Found"));
        employeeNotFoundBox.exec();
    }

}

void FindEmployee::cancel()
{
    employeeName->setText("");
}

void FindEmployee::setEmployeeID(int *employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}
