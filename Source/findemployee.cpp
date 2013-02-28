//Operations that define the Find Employee window.

#include <QtGui>
#include "FindEmployee.h"

//Draw the Find Employee window.
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

//This function takes a pointer to the employee ID to be changed
//and the value of the employer ID.
void FindEmployee::setIDValues(int *employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}

//This searches the employee data file for an employee with
//a certain name. If the employee cannot be found, the function
//provides a notification that says so. Otherwise, the pointer
//to the employee ID within the main OpenEval window is updated.
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

//This resets the find employee window to its base state.
void FindEmployee::cancel()
{
    employeeName->setText("");
}
