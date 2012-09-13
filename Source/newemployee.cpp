#include "NewEmployee.h"
#include <QtGui>

NewEmployee::NewEmployee(QWidget *parent)
    : QDialog(parent)
{

    employerDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYERS.txt");
    employeeDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYEES.txt");
    employeeIDDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYEEID.txt");
    fieldPlacementsFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/FIELDPLACEMENTS.txt");
    employerData = new QTextStream(employerDataFile);
    employeeData = new QTextStream(employeeDataFile);
    employeeIDData = new QTextStream(employeeIDDataFile);
    fieldPlacementsData = new QTextStream(fieldPlacementsFile);

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
    addEmployers();
}

void NewEmployee::cancel()
{
    hide();
    clearFields();
}

void NewEmployee::submit()
{
    firstName = employeeFirstName->text();
    lastName = employeeLastName->text();
    address = employeeAddress->text();
    city = employeeCity->text();
    state = employeeState->text();
    zipCode = employeeZipCode->text();
    phone = employeePhone->text();
    cell = employeeCell->text();
    eMail = employeeEMail->text();
    employeeFirstName->setFocus();
    writeEmployeeData();
    clearFields();
}

void NewEmployee::addEmployers()
{

    employeeEmployer->clear();

    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerDataString = employerDataFile->readLine();

    while(employerDataString != "")
    {
        QStringList employerDataList = employerDataString.split(',');
        QString employerNameString = employerDataList.at(1);
        employeeEmployer->addItem(employerNameString);
        employerDataString = employerData->readLine();
    }

    employerDataFile->close();

}

void NewEmployee::assignEmployeeID()
{
    employeeIDDataFile->open(QIODevice::ReadWrite | QIODevice::Text);
    QString employeeIDString = employeeIDData->readLine();
    if (employeeIDString == "")
    {
        employeeID = 1;
        employeeIDData->operator <<(employeeID);
    }
    else
    {
        employeeID = employeeIDString.toInt();
    }
    employeeIDDataFile->close();
}

int NewEmployee::setEmployeeInfo(int currentEmployeeID)
{
    //Someday this function will do something. I promise.
    return currentEmployeeID;
}

void NewEmployee::writeEmployeeData()
{

    employeeDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    employeeData->operator <<(employeeID) << "," << firstName << "," << lastName << "," << eMail << "," << phone << "," <<
                                     cell << "," << address << "," << city << "," << state << "," << zipCode << endl;

    employeeDataFile->close();

    employEmployee();

    //Increment the employee ID and write to the data file.
    employeeID++;
    employeeIDDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);
    employeeIDData->operator <<(employeeID);
    employeeIDDataFile->close();
}

void NewEmployee::employEmployee()
{
    employer = employeeEmployer->currentText();
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerNameString = employerDataFile->readLine();
    while(!employerNameString.contains(employer))
    {
        employerNameString = employerDataFile->readLine();
    }

    employerDataFile->close();

    QStringList employerDataList = employerNameString.split(',');
    int employerID = employerDataList.at(0).toInt();

    fieldPlacementsFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    fieldPlacementsData->operator <<(employeeID) << "," << employerID << endl;
    fieldPlacementsFile->close();
}

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
}
