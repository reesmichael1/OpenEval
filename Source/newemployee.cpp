//Operations that define the New Employee window.

#include "NewEmployee.h"
#include <QtGui>

//Draw the New Employee window.
NewEmployee::NewEmployee(QWidget *parent)
    : QDialog(parent)
{

    assignEmployeeID();

    QLabel *firstNameLabel = new QLabel(tr("First Name"));
    employeeFirstName = new QLineEdit;

    QLabel *lastNameLabel = new QLabel(tr("Last Name"));
    employeeLastName = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Street Address"));
    employeeAddress = new QLineEdit;

    QLabel *cityLabel = new QLabel(tr("City"));
    employeeCity = new QLineEdit;

    QLabel *stateLabel = new QLabel(tr("State"));
    employeeState = new QLineEdit;

    QLabel *zipLabel = new QLabel(tr("Zip Code"));
    employeeZipCode = new QLineEdit;

    QLabel *phoneLabel = new QLabel(tr("Phone Number"));
    employeePhone = new QLineEdit;

    QLabel *cellLabel = new QLabel(tr("Cell Phone"));
    employeeCell = new QLineEdit;

    QLabel *emailLabel = new QLabel(tr("E-Mail Address"));
    employeeEMail = new QLineEdit;

    QLabel *employerLabel = new QLabel(tr("Employer"));
    employeeEmployer = new QComboBox;

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(accept()));

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(submitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(firstNameLabel, 0, 0);
    mainLayout->addWidget(employeeFirstName, 0, 1, 1, 4);
    mainLayout->addWidget(lastNameLabel, 0, 5, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(employeeLastName, 0, 6, 1, 4);
    mainLayout->addWidget(phoneLabel, 1, 0);
    mainLayout->addWidget(employeePhone, 1, 1, 1, 4);
    mainLayout->addWidget(cellLabel, 1, 5, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(employeeCell, 1, 6, 1, 4);
    mainLayout->addWidget(addressLabel, 2, 0);
    mainLayout->addWidget(employeeAddress, 2, 1, 1, 9);
    mainLayout->addWidget(cityLabel, 3, 0);
    mainLayout->addWidget(employeeCity, 3, 1, 1, 3);
    mainLayout->addWidget(stateLabel, 3, 4);
    mainLayout->addWidget(employeeState, 3, 5);
    mainLayout->addWidget(zipLabel, 3, 6);
    mainLayout->addWidget(employeeZipCode, 3, 7, 1, 3);
    mainLayout->addWidget(emailLabel, 4, 0);
    mainLayout->addWidget(employeeEMail, 4, 1, 1, 5);
    mainLayout->addWidget(employerLabel, 4, 6);
    mainLayout->addWidget(employeeEmployer, 4, 7, 1, 3);
    mainLayout->addLayout(buttonLayout, 5, 0, 1, 10);

    setLayout(mainLayout);
    setWindowTitle(tr("New Employee"));
    addEmployers();
}

//This resets the New Employee window to its base state
//and hides it.
void NewEmployee::cancel()
{
    hide();
    clearFields();
}

//This writes the new employee to the employee data file
//and resets the window to its base state.
void NewEmployee::submit()
{
    assignEmployeeID();
    writeEmployeeData();
    clearFields();
}

//This adds newly created employers to the "Select Employer"
//menu within the New Employee window.
void NewEmployee::addEmployers()
{

    employeeEmployer->clear();

    QFile employerDataFile(EMPLOYERFILE);
    QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);

    for (int i = 0; i < employerIDVector.size(); i++)
    {
        QString employerDataString = returnDataString(&employerDataFile, employerIDVector.at(i), 0);
        QStringList employerDataList = employerDataString.split("\",\"");
        employeeEmployer->addItem(employerDataList.at(1));
    }

}

//This sets the employee ID that will be assigned to the
//new employee as one higher the current greatest ID within
//the employee data file.
void NewEmployee::assignEmployeeID()
{
    QFile employeeDataFile(EMPLOYEEFILE);
    QVector<int> employeeIDVector = generateIDVector(&employeeDataFile, 0);
    currentEmployeeID = returnOneHigherThanMaxValue(employeeIDVector);
}

//This takes a pointer to the current employer ID within OpenEval
//so that the fields can be updated when the new employee is submitted.
void NewEmployee::assignEmployerID(int *employerID)
{
    currentEmployerID = employerID;
}

//This writes the information about the employee into the employee data file.
void NewEmployee::writeEmployeeData()
{


    QFile employeeDataFile(EMPLOYEEFILE);

    QString employeeDataString =  QString::number(currentEmployeeID) + "\",\"" + employeeFirstName->text() + "\",\""
                            + employeeLastName->text() + "\",\"" + employeeEMail->text() + "\",\""
                            + employeePhone->text() + "\",\"" + employeeCell->text() + "\",\""
                            + employeeAddress->text() + "\",\"" + employeeCity->text() + "\",\""
                            + employeeState->text() + "\",\"" + employeeZipCode->text();

    addStringToFile(&employeeDataFile, employeeDataString);

    employEmployee();
}

//This writes the employee ID and the employer ID to
//the field placements data file.
void NewEmployee::employEmployee()
{
    QString employer = employeeEmployer->currentText();
    QFile employerDataFile(EMPLOYERFILE);

    QString employerDataString = returnLineWithString(&employerDataFile, employer, 1);
    QStringList employerDataList = employerDataString.split("\",\"");

    int employerID = employerDataList.at(0).toInt();
    *currentEmployerID = employerID;

    QString fieldPlacementsString = QString::number(currentEmployeeID) + "\",\"" + QString::number(employerID);

    QFile fieldPlacementsFile(FIELDPLACEMENTSFILE);
    addStringToFile(&fieldPlacementsFile, fieldPlacementsString);

}

//This resets all of the editable fields within the
//New Employee window.
void NewEmployee::clearFields()
{
    employeeFirstName->setText("");
    employeeLastName->setText("");
    employeeAddress->setText("");
    employeeCity->setText("");
    employeeState->setText("");
    employeeZipCode->setText("");
    employeePhone->setText("");
    employeeCell->setText("");
    employeeEMail->setText("");

    employeeFirstName->setFocus();
}
